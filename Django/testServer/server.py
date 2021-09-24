import socket
import logging
import sys

logging.basicConfig(level=logging.INFO)
SERVER_ADDRESS = ('0.0.0.0', 8000)

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(SERVER_ADDRESS)
logging.info("Port binded")

server.listen()
connection, clientAddress = server.accept()
logging.info("Listening on port 8000")
while 1:
    data = connection.recv(1024)
    logging.info("Received '" + str(data.decode("UTF-8")) + "'")
    if data:
        logging.info("Sending data back")
        connection.sendall(data.encode("UTF-8"))
    else:
        logging.info("No more data have been received")
        break

connection.close()