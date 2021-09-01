process.nextTick(()=>{
    console.log(`nextTick`);
});
Promise.resolve().then(console.log(1)); // ()=>를 붙여야 콜백을 받은 후 실행됨

console.log(2);