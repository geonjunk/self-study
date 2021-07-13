setImmediate(()=>{
    console.log(`Immediate`);
});
process.nextTick(()=>{
    console.log(`nextTick`);
});

setTimeout(()=>{
    console.log(`timeout`);
},0);

Promise.resolve().then(()=>console.log(`promise`));
