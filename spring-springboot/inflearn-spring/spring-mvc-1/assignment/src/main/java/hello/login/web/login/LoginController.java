package hello.login.web.login;

import hello.login.domain.login.LoginService;
import hello.login.domain.member.Member;
import hello.login.web.SessionConst;
import javax.servlet.http.HttpSession;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Controller;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

import javax.servlet.http.HttpServletRequest;
import javax.validation.Valid;
import org.springframework.web.bind.annotation.RequestParam;

@Slf4j
@Controller
@RequiredArgsConstructor
public class LoginController {

    private final LoginService loginService;

    @GetMapping("/login")
    public String loginForm(@ModelAttribute("loginForm") LoginForm form) {
        return "login/loginForm";
    }

  @PostMapping("/login")
  public String signIn(@Valid @ModelAttribute LoginForm form, BindingResult bindingResult,
      @RequestParam(defaultValue = "/") String redirectURL,
      HttpServletRequest request) {

    if(bindingResult.hasErrors()){
      return "login/loginForm";
    }

    Member loginMember = loginService.login(form.getLoginId(), form.getPassword());
    log.info("login? {}",loginMember);

    if(loginMember == null){
      bindingResult.reject("loginFail","아이디 또는 비밀번호가 맞지 않습니다. ");
      return "login/loginForm";
    }

    // 로그인 성공처리

    // 세션 생성
    HttpSession session = request.getSession();

    // 세션에 로그인 회원 정보 보관
    session.setAttribute(SessionConst.LOGIN_MEMBER,loginMember);

    // redirectURL 적용
    return "redirect:"+redirectURL;
  }

  @GetMapping("/members/add") // 회원가입

    @PostMapping("/logout")
    public String logout(HttpServletRequest request) {
        // 세션을 삭제한다.
        HttpSession session = request.getSession(false);
        if(session != null){
            session.invalidate();
        }

        return "redirect:/";
    }

}
