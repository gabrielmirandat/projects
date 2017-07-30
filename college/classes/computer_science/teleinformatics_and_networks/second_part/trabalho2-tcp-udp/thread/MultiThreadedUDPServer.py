#!/usr/bin/python
# para rodar: $ python MultiThreadedUDPServer.py

import threading        #biblioteca de thread
import SocketServer     #framework para servidor de internet
import time             # para ver funcionamento de varias requisicoes

# classe gerenciadora de requests de clientes UDP assincrona
class ThreadedUDPRequestHandler(SocketServer.BaseRequestHandler):

    # processa requests que chegam de clientes
    # overriding do metodo handle da classe BaseRequestHandler
    def handle(self):
        # obtem dados do request
        data = self.request[0].strip()
        # obtem socket de comunicacao
        socket = self.request[1]
		#obtem endereco IP do cliente
        client_address = (self.client_address[0])
        # obtem numero da porta do cliente
        port = self.client_address[1]
		# criacao da thread do request do cliente
        cur_thread = threading.current_thread()
        print "thread %s" %cur_thread.name
        print "recebeu pedido do cliente de endereco: %s" %client_address
        print "recebeu dados da porta [%s]: %s" %(port,data)
		
		# resposta para cliente
        response = "%s %s"%(cur_thread.name, data)
        socket.sendto(response.upper(), self.client_address)

        # para ver o uso de varias threads
        time.sleep( 1 )

# servidor UDP assincrono
class ThreadedUDPServer(SocketServer.ThreadingMixIn, SocketServer.UDPServer):
    pass

if __name__ == "__main__":
    # posta de conexao eh 8888
    HOST, PORT = "localhost", 8888

    # obtem servidor
    server = ThreadedUDPServer((HOST, PORT), ThreadedUDPRequestHandler) 
    
    # gerencia request ate um request shutdown
    server.serve_forever()

    # comeca thread com servidor
	# esta thread cria uma nova thread a cada request de cliente
    server_thread = threading.Thread(target=server.serve_forever)

    # sai da thread do servidor quando a thread principal acabar
    server_thread.daemon = True
    server_thread.start()
        
    server.shutdown()
    server.server_close()