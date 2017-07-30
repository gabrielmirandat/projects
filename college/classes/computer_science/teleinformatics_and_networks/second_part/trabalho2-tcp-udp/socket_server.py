SocketServer

4 classes básicas concretas:
	- class SocketServer.TCPServer(server_address, RequestHandlerClass, bind_and_activate=True)
		- contínuo stream de dados
	- class SocketServer.UDPServer(server_address, RequestHandlerClass, bind_and_activate=True)
		- datagramas 
	- class SocketServer.UnixStreamServer(server_address, RequestHandlerClass, bind_and_activate=True)
	- class SocketServer.UnixDatagramServer(server_address, RequestHandlerClass, bind_and_activate=True)

As quatro classes fazem request de forma sincrona
Cada request deve ser completado antes que um próximo possa começar
A solução é criar thread pra cada request
As classes ForkingMixIn e ThreadingMixIn server pra dar comportamento assíncrono

Passos pra criar servidor
- criar classe request hendler subclassing a classe BaseRequestHandler e overriding o método handle(), este método processo requests que chegam
- instanciar uma das 4 classes servidoras, passando endereço do servidor e a classe request handler
- chamar handle_request() ou serve_forever() do objeto server para processar os requests
- chame server_close() para fechar o socket

class ThreadingUDPServer(ThreadingMixIn, UDPServer):
    pass