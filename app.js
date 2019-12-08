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
  
    setInterval(() => {
      socket.emit('news', { connection: 'fine' });
    }, 100);
  
    console.log("connected");

  socket.on('sendPose', function (data) { // 클라이언트에서 my other event가 발생하면 데이터를 받습니다.
  
      console.log(data);

    });

  
  });