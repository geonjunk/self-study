package hello.jdbc.service;

import hello.jdbc.domain.Member;
import hello.jdbc.repository.MemberRepositoryV1;
import hello.jdbc.repository.MemberRepositoryV2;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;

/**
 * 트랜잭션 - 파라미터 연동, 풀을 고려한 종료
 */
@Slf4j
@RequiredArgsConstructor
public class MemberServiceV2 {

    private final DataSource dataSource;
    private final MemberRepositoryV2 memberRepository;

    public void accountTransfer(String fromId, String toId, int money) throws SQLException {
        Connection conn = dataSource.getConnection();

        try{
            conn.setAutoCommit(false); // 트랜잭션 시작 (autocommit false=>트랜잭션 시작을 의미)

            bizLogic(conn,fromId, toId, money);    // 비즈니스로직 메서드 분리
            conn.commit();
        }catch (Exception e){
            conn.rollback(); // 실패시 롤백
            throw new IllegalStateException(e);
        } finally {
            release(conn);
        }
    }

    private void bizLogic(Connection conn,String fromId, String toId, int money) throws SQLException {
        // 비즈니스 로직
        Member fromMember = memberRepository.findById(conn, fromId);
        Member toMember = memberRepository.findById(conn, toId);

        memberRepository.update(conn,fromId, fromMember.getMoney()- money);
        validation(toMember);

        memberRepository.update(conn,toId,toMember.getMoney() + money);
    }

    private static void release(Connection conn) {
        if(conn !=null) {
            try {
                conn.setAutoCommit(true);   // 커넥션 풀 고려하여 autocommit 상태 원복
                conn.close();
            } catch (Exception e) {
                log.info("error", e); // 예외는 {} 안써도 됨
            }
        }
    }

    private static void validation(Member toMember) {
        if(toMember.getMemberId().equals("ex")){
            throw new IllegalStateException("이체중 예외발생");
        }
    }
}
