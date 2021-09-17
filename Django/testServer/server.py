import socket
import logging
import sys

logging.basicConfig(level=logging.INFO)
port = int(input("Port to bind: "))
if(port < 1025):
    logging.error("Port value can't be <= 1024")
    sys.exit()
else:
    ADDRESS = ("", port)  # listen all interfaces, port 1234

srv = socket.create_server(ADDRESS, family=socket.AF_INET)
logging.info("Server was created on port " + str(port))

srv.listen()

while(1):
    (client, clientAddress) = srv.accept()
    logging.info("Received connection from " + str(clientAddress))
    data = client.recv(1024)
    print(data.decode("UTF-8"))

    dataToClient = "Hello client!"
    srv.send(dataToClient.encode("UTF-8"))
    sys.exit()