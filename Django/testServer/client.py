import socket
import logging
import sys

logging.basicConfig()

address = input("Server address: ")
port = int(input("Server port: "))
data = "Hello world!"

clientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
logging.info("Socket was created")
clientSocket.connect((address, port))
clientSocket.send(data.encode("UTF-8"))

clientSocket.setblocking(False)

while(1):
    (srv, srvAddress) = clientSocket.accept()
    data = srv.recv(1024)
    print(data.decode("UTF-8"))

    sys.exit()