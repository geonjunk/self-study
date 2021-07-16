const http=require(`http`);
const fs=require(`fs`).promises;


http.createServer(async (req,res)=>{
    try{
    const data=await fs.readFile(`./server2.html`);
    res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
    res.end(data);
    }catch(err){
        console.err(err);
        res.writeHead(500,{'Content-Type':`text/plain;charset=utf-8`});//에러 시 그냥 문자열로
        res.end(err.message);
    }


}).listen(8081,()=>{
    console.log(`8081번 포트에서 대기중`);
});
/*
const server=http.createServer((req,res)=>{
    fs.readFile(`./server2.html`)
    .then((data)=>{
        res.writeHead(200,{'Content-Type':`text/html;charset=utf-8`});
        res.end(data);
    }).catch((err)=>{
        console.err(err);
        res.writeHead(500,{'Content-Type':`text/plain;charset=utf-8`});
        res.end(err.message);
    })
});

server.listen(8081,()=>{
    console.log(`8081번 포트에서 대기중`);
});
server.on(`error`,(err)=>{
    console.error(err);
})
*/ //프라미스 방식