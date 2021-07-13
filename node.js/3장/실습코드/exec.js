const exec=require(`child_process`).exec;//const {exec}=require(`child_process`);
const process=exec(`dir`);

process.stdout.on(`data`,function(data){
    console.log(data.toString());
});// 실행 결과

process.stdout.on(`error`,function(data){
    console.log(data.toString());
});// 실행 에러