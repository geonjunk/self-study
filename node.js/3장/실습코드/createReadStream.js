const fs = require('fs');

const readStream = fs.createReadStream('./readme3.txt', { highWaterMark: 16 });//highWaterMark속성을 통해 한번에 읽을 바이트 수 지정, r기본값은 64000바이트(64KB)
const data = [];

readStream.on('data', (chunk) => {
data.push(chunk);
console.log('data :', chunk, chunk.length);
});

readStream.on('end', () => {
console.log('end :', Buffer.concat(data).toString());
});

readStream.on('error', (err) => {
console.log('error :', err);
});