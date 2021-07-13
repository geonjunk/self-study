const fs=require(`fs`);
fs.readFile(`./readme.txt`,(error,data)=>{
    if(error){
        throw error;
    }
    console.log(data);//버퍼로 메모리 데이터 출력 
    console.log(data.toString());
});