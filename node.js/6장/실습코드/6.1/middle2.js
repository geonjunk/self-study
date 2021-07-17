const express =require(`express`);
const morgan=require(`morgan`);
const cookieParser=require(`cookie-parser`);
const path=require(`path`);
const session = require("express-session");

const app=express();
app.set(`port`,process.env.PORT||3000);

app.use(morgan(`dev`));
app.use(`/`,express.static(path.join(__dirname,`public`)));
app.use(express.json());
app.use(express.urlencoded({extended:true}));
app.use(cookieParser(process.env.COOKIE_SECRET));
app.use(session({
    resave:false,
    saveUninitialized:false,
    secret:process.env.COOKIE_SECRET,
    cookie:{
        httpOnly:true,
        secure:false,
    },
    name: `session-cookie`,
}));

app.use((req,res,next)=>{
    console.log(`모든요청에 실행됨`);
    next();   
});