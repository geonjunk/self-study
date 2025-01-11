package hello.core.lifecycle;

import org.junit.jupiter.api.Test;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

public class BeanLifeCycleTest {

    @Test
    public void lifeCycleTest() {
        ConfigurableApplicationContext ac = new AnnotationConfigApplicationContext(LifeCycleConfig.class);
        Networkclient client = ac.getBean(Networkclient.class);
        ac.close();
    }

    @Configuration
    static class LifeCycleConfig {

        @Bean
        public Networkclient networkclient() {
            Networkclient networkclient = new Networkclient();
            networkclient.setUrl("http://hello-spring.dev");
            return networkclient;
        }
    }
}
