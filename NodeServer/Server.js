const net = require("net");

const server = net.createServer((c) => {
  // 'connection' listener
  console.log("client connected");

  c.on('end', () => {
    console.log('client disconnected');
  });

  c.on('error', () => {
    console.log("Error on client");
  });

  c.on('data', (data) => {
      console.log(data+"\n");
  });

});


server.listen(25565);
