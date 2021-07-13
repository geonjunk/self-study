const {Worker, isMainThread,parentPort,}=require(`worker_threads`);
if(isMainThread){//메인스레드일때
    const worker=new Worker(__filename);//다른 파일도 가능(path 모듈이용) 
    worker.on(`message`,(value)=>console.log(`frome worker`,value));
    worker.on(`exit`,()=>console.log(`워커 끝~`));
    worker.postMessage(`ping`);//워커스레드에게 메시지 보냄
}else{//워커스레드일때 
    parentPort.on(`message`,(value)=>{//부모로 부터 메시지 받음
    console.log(`frome parent`,value);
        parentPort.postMessage(`pong`);
        parentPort.close();//워커스레드 부모와의 연결 종료
    })
}