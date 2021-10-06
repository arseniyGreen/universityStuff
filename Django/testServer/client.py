import socket
import logging
import sys

logging.basicConfig(level=logging.INFO)

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('127.0.0.1', 8000)

logging.info("Connecting to " + str(server_address))
client.connect(server_address)

message = "Hello"

client.sendall(message.encode("UTF-8"))

while(1):
    data = client.recv(1024)
    if data:
        print("Got back '" + str(data.decode("UTF-8") + "'"))
    else:
        break

client.close()