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

io.sockets.on('connection', function (socket) {

  socket.on('pose', function (data) {

    console.log(data);
  });
});