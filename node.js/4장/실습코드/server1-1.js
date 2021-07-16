const http = require(`http`);

http.createServer((req,res)=>{
    res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});//html타입의 한글 사용하기 위해 utf-8형식
    res.write(`<h1>안녕 노드!</h1>`);
    res.write(`<h2>노드 서버야~</h2>`);
    res.end(`<p>안녕 서버!</p>`);
}).listen(8080,()=>{//서버 연결
    console.log(`8080번 포트에서 서버 대기중!`);
});

http.createServer((req, res) => {
    res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
    res.write('<h1>Hello Node!</h1>');
    res.end('<p>Hello Server!</p>');
  })
    .listen(8081, () => { // 서버 연결
      console.log('8081번 포트에서 서버 대기 중입니다!');
});
//여러개의 서버 한번에 실행 가능