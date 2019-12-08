const port = 3000;

const http = require('http');
var fs = require('fs');
var io = require('socket.io').listen(port);

const hostname = '127.0.0.1';


fs.readFile('./index.html', function (err, html) {

  if (err) {
    throw err; 
  }  

  const server = http.createServer((req, res) => {
    res.writeHeader(200, {"Content-Type": "text/html"});  
    res.write(html);  
    res.end(); 
  }).listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}/`);
  });
});

io.sockets.on('connection', function (socket) { // connection이 발생할 때 핸들러를 실행합니다.

  console.log('server running at port port');
  
      socket.emit('news', { hello: 'world' }); // 클라이언트로 news 이벤트를 보냅니다. (hello 라는 키에 world라는 값이 담깁니다)
  
   
  
  socket.on('my other event', function (data) { // 클라이언트에서 my other event가 발생하면 데이터를 받습니다.
  
        console.log(data);
  
      });

  socket.on('my other event', function (data) { // 클라이언트에서 my other event가 발생하면 데이터를 받습니다.
  
      console.log(data);

    });

  
  });