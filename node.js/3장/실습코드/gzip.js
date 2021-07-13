
const zlib = require('zlib');
const fs = require('fs');

const readStream = fs.createReadStream('./readme4.txt');
const zlibStream = zlib.createGzip();//createGzip()은 스트림 지원하는 메서드 -> 파이핑 가능
const writeStream = fs.createWriteStream('./readme4.txt.gz');
readStream.pipe(zlibStream).pipe(writeStream);//버퍼 데이터가 전달되다가 gzip으로 압축을 거친 후 파일로 써짐
