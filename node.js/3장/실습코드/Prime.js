const min=2;
const max=10_000_000;
const prime=[];
const generatePrimes=(start,range)=>{
    let isPrime=true;

    for(let i=start;i<range;i++){
        for(let j=min;j<=Math.sqrt(i);j++){
            if(i%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime){
            prime.push(i); 

        }
        isPrime=true;
    }

};
console.time(`prime`);
generatePrimes(min,max);
console.timeEnd(`prime`);
console.log(prime.length);