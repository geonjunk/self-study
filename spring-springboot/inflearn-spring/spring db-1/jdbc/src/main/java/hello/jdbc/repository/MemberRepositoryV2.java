package hello.jdbc.repository;


import hello.jdbc.domain.Member;
import lombok.extern.slf4j.Slf4j;
import org.springframework.jdbc.support.JdbcUtils;

import javax.sql.DataSource;
import java.sql.*;
import java.util.NoSuchElementException;

/**
 * JDBC - ConnectionParam
 */
@Slf4j
public class MemberRepositoryV2 {

    private final DataSource dataSource;

    public MemberRepositoryV2(DataSource dataSource) {
        this.dataSource = dataSource;
    }

    public Member save(Member member) throws SQLException {
        String sql = "insert into member(member_id, money) values(?, ?)";
        Connection conn = null;
        PreparedStatement pstmt = null;

        try {
            conn = getConncetion();
            pstmt = conn.prepareStatement(sql);

            pstmt.setString(1,member.getMemberId());
            pstmt.setInt(2,member.getMoney());
            pstmt.executeUpdate();

            return member;
        } catch (SQLException e) {
            log.error("db error", e);
            throw e;
        } finally {
            close(conn,pstmt,null);
        }
    }

    public Member findById(String memberId) throws SQLException {
        String sql = "select * from member where member_id = ?";
        Connection conn = null;
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            conn = getConncetion();
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,memberId);

            rs = pstmt.executeQuery();
            if(rs.next()){
               Member member = new Member();
               member.setMemberId(rs.getString("member_id"));
               member.setMoney(rs.getInt("money"));
               return member;
            }else{
                throw new NoSuchElementException("member not found memberId=" +memberId);
            }
        }catch (SQLException e) {
            log.error("db error",e);
            throw e;
        }finally {
            close(conn,pstmt,rs);
        }
    }

    public Member findById(Connection conn,String memberId) throws SQLException {
        String sql = "select * from member where member_id = ?";
        PreparedStatement pstmt = null;
        ResultSet rs = null;

        try {
            pstmt = conn.prepareStatement(sql);
            pstmt.setString(1,memberId);

            rs = pstmt.executeQuery();
            if(rs.next()){
                Member member = new Member();
                member.setMemberId(rs.getString("member_id"));
                member.setMoney(rs.getInt("money"));
                return member;
            }else{
                throw new NoSuchElementException("member not found memberId=" +memberId);
            }
        }catch (SQLException e) {
            log.error("db error",e);
            throw e;
        }finally {
            JdbcUtils.closeResultSet(rs);
            JdbcUtils.closeStatement(pstmt);
            // JdbcUtils.closeConnection(con); connection은 서비스 마지막에 종료
        }
    }

    public void update(String memberId,int money) throws SQLException {
        String sql = "update member set money = ? where member_id = ?";
        Connection conn = null;
        PreparedStatement pstmt = null;
        try {
            conn= getConncetion();
            pstmt= conn.prepareStatement(sql);
            pstmt.setInt(1,money);
            pstmt.setString(2,memberId);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            log.error("db error", e);
            throw e;
        } finally {
            close(conn,pstmt,null);
        }
    }

    public void update(Connection conn,String memberId,int money) throws SQLException {
        String sql = "update member set money = ? where member_id = ?";
        PreparedStatement pstmt = null;
        try {
            pstmt= conn.prepareStatement(sql);
            pstmt.setInt(1,money);
            pstmt.setString(2,memberId);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            log.error("db error", e);
            throw e;
        } finally {
            JdbcUtils.closeStatement(pstmt);
            // JdbcUtils.closeConnection(con); connection은 서비스 마지막에 종료
        }
    }

    public void delete(String memberId) throws SQLException {
        String sql = "delete from member where member_id = ?";
        Connection conn = null;
        PreparedStatement pstmt = null;
        try {
            conn= getConncetion();
            pstmt= conn.prepareStatement(sql);
            pstmt.setString(1,memberId);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            log.error("db error", e);
            throw e;
        } finally {
            close(conn,pstmt,null);
        }
    }

    private void close(Connection con, Statement stmt, ResultSet rs){
        JdbcUtils.closeResultSet(rs);
        JdbcUtils.closeConnection(con);
        JdbcUtils.closeStatement(stmt);
    }

    private Connection getConncetion() throws SQLException {
        Connection con= dataSource.getConnection();
        log.info("get connection ={}, class={}",con,con.getClass());
        return con;
    }

}
