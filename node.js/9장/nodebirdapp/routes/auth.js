const express=require(`express`);
const passport=require(`passport`);
const bcrypt=require(`bcrypt`);
const {isLoggedIn, isNotLoggedIn}=require(`./middlewares`);
const User=require(`../models/user`);

const router=express.Router();

router.post(`/join`,isNotLoggedIn,async(req,res,next)=>{
    const {email,nick, password}=req.body;
    try{
        const exUser=await User.findOne({where:{email}});
        if(exUser){
            return res.redirect('/join?error=exist');
        }
        const hash=await bcrypt.hash(password,12);
        await User.create({
            email,
            nick,
            password:hash,
        });
        return res.redirect('/');
    }catch(error){
        console.error(error);
        return next(error);
    }
});// 회원가입 라우터



router.post('/login',isNotLoggedIn,(req,res,next)=>{
    passport.authenticate('local',(authError,user,info)=>{//로컬 로그인 전략 실행
        if(authError){
            console.error(authError);
            return next(authError);
        }
        if(!user){
            return res.redirect(`/loginError=${info.message}`);
        }
        return req.logIn(user,(loginError)=>{//성공하면 req.login 호출함, req.login은 passport.serializeUser 호출
            if(loginError){
                console.error(loginError);
                return next(loginError);
            }
            return res.redirect('/');
        });
    })(req,res,next);// 미들웨어 내의 미들웨어에는 (req,res,next)를 붙임
});

router.get('/logout',isLoggedIn,(req,res)=>{//req.user객체 제거, req.session을 제거함
    req.logout();
    req.session.destroy();
    res.redirect('/');
});

router.get('/kakao',passport.authenticate('kakao'));
router.get('/kakao/callback',passport.authenticate('kakao',{
    failureRedirect:'/',
}),(req,res)=>{
    res.redirect('/');
})
module.exports=router;