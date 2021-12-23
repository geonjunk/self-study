const mongoose = require('mongoose');

const connect = () => {
  if (process.env.NODE_ENV !== 'production') {
    mongoose.set('debug', true);
  }
  mongoose.connect('db주소', {//6버전 부터 useNewUrlParser, useUnifiedTopology, and useCreateIndex 는 true, and useFindAndModify 는 false 로 항상 동작하므로 옵션 줄 필요없음
    dbName: 'nodejs',
   /* useNewUrlParser: true,
    useCreateIndex: true,*/
  }, (error) => {
    if (error) {
      console.log('몽고디비 연결 에러', error);
    } else {
      console.log('몽고디비 연결 성공');
    }
  });
};

mongoose.connection.on('error', (error) => {
  console.error('몽고디비 연결 에러', error);
});
mongoose.connection.on('disconnected', () => {
  console.error('몽고디비 연결이 끊겼습니다. 연결을 재시도합니다.');
  connect();
});

module.exports = connect;