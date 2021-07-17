const express=require(`express`);
const app =express();
const path=require(`path`);

app.set(`port`,process.env.PORT||3000);
//서버에다가 변수를 심는것, 전역변수느낌
//process.env.PORT가 있다면 그것을 사용하고 없으면 기본값 3000

app.get(`/`,(req,res)=>{ //request 메서드와 request url app에다가 붙이므로 if문 안붙여도됨
    res.send(`hello express`);
});

app.post(`/`,(req,res)=>{ 
    res.send(`hello post method`);
});

app.get(`/about`,(req,res)=>{ 
    res.sendFile(path.join(__dirname,`./index.html`));
}); 

app.listen(app.get(`port`),()=>{
    console.log(`익스프레스 서버실행`);
});