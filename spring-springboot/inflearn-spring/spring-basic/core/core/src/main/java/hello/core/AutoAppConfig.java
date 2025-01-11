package hello.core;


import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.ComponentScan.Filter;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.FilterType;

@Configuration
@ComponentScan( // 스프링 빈을 쭉 읽어서 자동으로 스프링 빈을 올림
        //    basePackages = "hello.core.member", // 탐색 위치 지정
        excludeFilters = @Filter(type = FilterType.ANNOTATION, classes = Configuration.class) // 자동 스캔중 제외할 것
)
public class AutoAppConfig {

//    @Bean(name = "memberMemberRepostiory")
//    MemberRepository memberRepository() {
//        return new MemoryMemberRepository();
//    }

}
