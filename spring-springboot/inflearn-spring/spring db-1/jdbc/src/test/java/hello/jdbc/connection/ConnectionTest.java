package hello.jdbc.connection;

import com.zaxxer.hikari.HikariDataSource;
import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.Test;
import org.springframework.jdbc.datasource.DriverManagerDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

import static hello.jdbc.connection.ConnectionConst.*;
import static org.assertj.core.api.Assertions.*;



@Slf4j
public class ConnectionTest {

    @Test
    void driverManager() throws SQLException {
        Connection con1 = DriverManager.getConnection(URL, USERNAME, PASSWORD);
        Connection con2 = DriverManager.getConnection(URL, USERNAME, PASSWORD);

        // connection 다름
        log.info("connection={}, class={}",con1,con1.getClass());
        log.info("connection={}, class={}",con2,con2.getClass());
    }

    @Test
    void dataSourceDriverManager() throws SQLException {
        // DriverManagerDataSource - 항상 새로운 커넥션 획득
        DataSource dataSource = new DriverManagerDataSource(URL,USERNAME,PASSWORD);
        useDataSource(dataSource);
    }

    private void useDataSource(DataSource dataSource) throws SQLException {
        Connection con1 = dataSource.getConnection();
        Connection con2 = dataSource.getConnection();

        log.info("connection={}, class={}",con1,con1.getClass());
        log.info("connection={}, class={}",con2,con2.getClass());
    }

    @Test
    void dataSoruceConncetionPool() throws SQLException, InterruptedException {
        // 커넥션 풀링
        HikariDataSource dataSource = new HikariDataSource();
        dataSource.setJdbcUrl(URL);
        dataSource.setUsername(USERNAME);
        dataSource.setPassword(PASSWORD);
        dataSource.setMaximumPoolSize(10); // 설정안하면 default 10
        dataSource.setPoolName("MyPool"); // 기본 pool 명

        useDataSource(dataSource);
        Thread.sleep(2000);
    }
}
