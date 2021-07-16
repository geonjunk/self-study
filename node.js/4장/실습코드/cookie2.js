const http= require(`http`);
const fs =require(`fs`).promises;
const url=require(`url`);
const qs=require(`querystring`);

const parseCookies = (cookie = '') =>
  cookie
    .split(';')
    .map(v => v.split('='))
    .reduce((acc, [k, v]) => {
      acc[k.trim()] = decodeURIComponent(v);
      return acc;
}, {});//문자열인 req.headers.cookie를 객체로 변환해주는 함수


http.createServer(async(req,res)=>{
    const cookies=parseCookies(req.headers.cookie);

    if(req.url.startsWith(`/login`)){//주소가 /login으로 시작하는 경우 (/login?name=이름 이런식으로 로그인 정보 받음(쿼리스트링 통한 방식)), 로그인 버튼 누르면 해당 주소로 GET요청 보냄
        const {query} =url.parse(req.url);
        const {name} = qs.parse(query);
        //쿼리 스트링에서 name 추출하는 방법
        const expires=new Date();
        
        expires.setMinutes(expires.getMinutes()+5);//쿠키 유효시간 설정 현재시간+5분
        res.writeHead(302,{//302 or 301 : redirection, Location 주소로 다시 돌려 보냄
            Location:`/`,
            'Set-Cookie': `name=${encodeURIComponent(name)}; Expires=${expires.toGMTString()}; HttpOnly; Path=/`, //요청주소나 쿠키에 한글이 들어가면 문제가 될때가 있어 이는 encodeURIComponent로 인코딩해줌
            // set-cookie에 추가정보 넣을수도 있음 
            //expires : 쿠키의 만료시간 설정 , 설정안하면 세션 쿠키임(브라우저 꺼지면 쿠키 사라짐)
            // 쿠기의 만료시간 지나면 브라우저에서 지난 쿠키는 서버에 보내지않음
            //HttpOnly : 쿠키를 JavaScript로 접근하지 못하게 함, 보안을 위해 사용, 로그인시 필수
        });
        res.end();
    }else if(cookies.name){//name이라는 쿠키 있는경우
        res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
        res.end(`${cookies.name}님 하이`);
    }else{
        try{
            const data=await fs.readFile(`./cookie2.html`);
            res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
            res.end(data);
        }catch(err){
            res.writeHead(500,{'Content-Type':'text/plain;charset=utf-8'});
            res.end(err.message);
        }
    }
}).listen(8084,()=>{
    console.log('8084번 포트에서 서버 대기중');
})