const express = require('express');
const path=require('path');
const morgan = require('morgan');
const nunjucks = require('nunjucks');

const connect = require('./schemas');
const indexRouter=require('./routes');
const usersRouter=require('./routes/users');
const commentsRouter=require('./routes/comments');
const app = express();

app.set('port',process.env.PORT||3002);
app.set('view engine','html');
nunjucks.configure('views',{
    express:app,
    watch:true,
});
connect();

app.use(morgan('dev'));//기존 로그대신 추가로그 볼 수 있음
app.use(express.static(path.join(__dirname,'public')));//경로설정
app.use(express.json());//json 형식으로보내면 req.body.객체명 : 이런식으로 접근 가능하게 함
app.use(express.urlencoded({extended:false}));//nodejs에 기본으로 내장된 querystring 이용

app.use('/',indexRouter);
app.use('/users',usersRouter);
app.use('/comments',commentsRouter);

app.use((req,res,next)=>{
    const error = new Error(`${req.method} ${req.url} 라우터가 없습니다.`)
    error.status=404;
    next(error);
});

app.use((err,req,res,next)=>{
    res.locals.message=err.message;//전역에서 사용가능한 지역변수 생성
    res.locals.error=process.env.NODE_ENV!='production' ? err:{};
    res.status(err.status||500);
    res.render('error');
});

app.listen(app.get('port'),()=>{
    console.log(app.get('port'),'번 포트에서 대기 중');
});
