const {Worker, isMainThread,parentPort,workerData,}=require(`worker_threads`);

if(isMainThread){
    const threads=new Set();
    threads.add(new Worker(__filename,{
        workerData:{start : 1},
    }));
    threads.add(new Worker(__filename,{
        workerData:{start:2},
    }));
    for(let worker of threads){
        worker.on(`message`,message=>console.log(`from worker`,message));
        worker.on(`exit`,()=>{
            threads.delete(worker);//threads 목록에서 삭제
            if(threads.size==0){//모든 threads 종료되면 
                console.log(`job done`);
            }
        });
    }
}else{
    const data=workerData;
    parentPort.postMessage(data.start+100);//부모에게 메시지 보냄
}