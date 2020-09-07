from http.server import HTTPServer, CGIHTTPRequestHandler

server_address = ("0.0.0.0", 443)

httpd = HTTPServer(server_address, CGIHTTPRequestHandler)
httpd.serve_forever()
