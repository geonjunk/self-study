package hello.login.web;

import hello.login.domain.member.Member;
import hello.login.domain.member.MemberRepository;
import hello.login.web.session.SessionManager;
import javax.servlet.http.HttpSession;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.CookieValue;
import org.springframework.web.bind.annotation.GetMapping;

import javax.servlet.http.HttpServletRequest;
import org.springframework.web.bind.annotation.SessionAttribute;

@Slf4j
@Controller
public class HomeController {

    private final MemberRepository memberRepository;
    private final SessionManager sessionManager;

    public HomeController(MemberRepository memberRepository, SessionManager sessionManager) {
        this.memberRepository = memberRepository;
        this.sessionManager = sessionManager;
    }


    // @GetMapping("/")
    public String homeLogin(@CookieValue(name = "memberId", required = false) Long memberId,
      Model model) {
        // @CookieValue : 편리하게 쿠키 값 조회
        // 쿠키 여부, 쿠키가 있어도 회원여부 검사
        if (memberId == null) {
            return "home";
        }

        // 로그인
        Member loginMember = memberRepository.findById(memberId);
        if (loginMember == null) {
            return "home";
        }

        model.addAttribute("member", loginMember);
        return "loginHome";

    }

    //@GetMapping("/")
    public String homeLoginV2(HttpServletRequest request, Model model) {

        // 세션 관리자에 저장된 회원정보 조회
        Member member = (Member) sessionManager.getSession(request);
        if (member == null) {
            return "home";
        }

        // 로그인
        model.addAttribute("member", member);
        return "loginHome";
    }

   // @GetMapping("/")
    public String homeLoginV3(HttpServletRequest request, Model model) {

        // 세션이 없으면 home
        HttpSession session = request.getSession(false);

        if(session==null){
            return "home";
        }

        Member loginMember = (Member) session.getAttribute(SessionConst.LOGIN_MEMBER);

        // 세션에 회원 데이터가 없으면 home
        if(loginMember == null){
            return "home";
        }

        model.addAttribute("member", loginMember);
        return "loginHome";

    }

    @GetMapping("/")
    public String homeLoginV3Spring(
      @SessionAttribute(name = SessionConst.LOGIN_MEMBER, required = false) Member loginMember,
      Model model) {


        // 세션에 회원 데이터 없으면 home
        if(loginMember == null){
            return "home";
        }

        // 세션이 유지되면 로그인으로 이동
        model.addAttribute("member", loginMember);
        return "loginHome";
    }
}