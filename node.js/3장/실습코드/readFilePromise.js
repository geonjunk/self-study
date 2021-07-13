const fs=require(`fs`).promises;//자동으로 프로미스 지원하게 변환
fs.readFile(`./readme.txt`)
.then((data)=>{
    console.log(data);
    console.log(data.toString());
}).catch((err)=>{
    console.error(err);
});