const express=require(`express`);

const app= express();

app.set(`port`,process.env.PORT||3000);
app.use((req,res,next)=>{
    console.log(`모든 요청에 다실행됨`);
    next();
});

app.get(`/`,(req,res,next)=>{// 다음 미들웨어에서 next로 받아야 실행가능
    console.log(`GET/ 요청에서만 실행됩니다`);
    next();
},(req,res)=>{
    throw new Error(`에러는 에러처리 미들웨어로`);
});

app.use((err,req,res,next)=>{ //에러 미들웨어 맨아래에 넣음
    console.error(err);
    res.status(500).send(err.message);
});

app.listen(app.get(`port`),()=>{
    console.log(`익스프레스 서버실행`);
});