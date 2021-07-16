const http = require(`http`);

const server = http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});//html타입의 한글 사용하기 위해 utf-8형식
    res.write(`<h1>안녕 노드!</h1>`);
    res.write(`<h2>노드 서버야~</h2>`);
    res.end(`<p>안녕 서버!</p>`);
}).listen(8080);

server.on(`listening`,()=>{// listen에 콜백을 listening 이벤트 리스너로 바꿈
    console.log(`8080번 포트에서 서버 대기 중`);
})
server.on(`error`,(err)=>{//다 비동기 이므로 에러처리 해주기
    console.error(err);
})

