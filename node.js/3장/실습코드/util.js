const util=require(`util`);
const crypto=require(`crypto`);

const dontUseMe=util.deprecate((x,y)=>{
    console.log(x+y);
},`dontUseMe함수는 deprecated되었음 사용하지마세요`);
dontUseMe(1,2);

const randomBytesPromise=util.promisify(crypto.randomBytes);
randomBytesPromise(64).
then((buf)=>{
    console.log(buf.toString(`base64`));
})
.catch((error)=>{
    console.error(error);
});