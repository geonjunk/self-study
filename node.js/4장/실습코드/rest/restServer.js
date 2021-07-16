const http=require(`http`);
const fs=require(`fs`).promises;

const users={};// 유저 데이터 저장용

http.createServer(async(req,res)=>{
    try{
        console.log(req.method,req.url);
        if(req.method==`GET`){
            if(req.url==`/`){
                const data=await fs.readFile(`./restFront.html`);
                res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
                return res.end(data);
            }else if(req.url==`/about`){
                const data=await fs.readFile(`./about.html`);
                res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
                return res.end(data);
            }else if(req.url==`/users`){
                res.writeHead(200,{'Content-Type':`text/plain;charset=utf-8`});
                return res.end(JSON.stringify(users));//HTTP에서 메시지는 문자열로 전송이되기 때문에 전송할 때 JSON.stringify() 메서드를 호출하여 JSON을 문자열로 변환
            }
            // /,/about,/users 아닌 경우

            try{//이외에 주소는 해당 주소의 파일이 있으면 제공
                const data=await fs.readFile(`.${req.url}`);
                return res.end(data);
            }catch(err){
                //주소에 해당하는 라우트를 못찾았다는 404에러 발생
            }
        }else if(req.method==`POST`){
            if(res.url=`/user`){
            let body=``;
            //요청의 body를 stream형식으로 받음
            req.on(`data`,(data)=>{
                body+=data;
            });
            return req.on(`end`,()=>{     ///요청의 body 다받은 후 실행 됨
                console.log(`POST 본문(body) : `,body);
                const {name}=JSON.parse(body);
               //받아오는 방식은 외우기 let body부터 여기까지
                const id=Date.now();
                users[id]=name;//동적 생성
                res.writeHead(201);//성공적인 생성(201 : 성공적으로 생성됨)
                res.end(`등록 성공`);
            });
        }
        }else if(req.method==`PUT`){
            if(req.url.startsWith(`/user/`)){
                const key=req.url.split(`/`)[2];
                let body=``;
                req.on(`data`,(data)=>{
                    body+=data;
                });
                return req.on(`end`,()=>{
                    console.log(`PUT 본문(Body) : `,body);
                    users[key]=JSON.parse(body).name;
                    return res.end(JSON.stringify(users));
                });
            }
        }else if(req.method==`DELETE`){
            if(req.url.startsWith(`/user/`)){
                const key=req.url.split(`/`)[2];
                delete users[key];
                return res.end(JSON.stringify(users));
            }
        }
        res.writeHead(404);
        return res.end(`NOT FOUND`);
    }catch(err){
        console.error(err);
        res.writeHead(500,{'Content-Type':`text/html;charset=utf-8`});
        res.end(err.message);
    }
}).listen(8082,()=>{
    console.log(`8082번 포트에서 서버 대기 중`);
})