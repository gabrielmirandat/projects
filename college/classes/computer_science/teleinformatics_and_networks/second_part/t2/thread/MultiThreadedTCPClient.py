#!/usr/bin/python
# para rodar: $ python MultiThreadedTCPClient.py <dados_de_envio>

import socket
import sys

# define hospedeiro e posta de comunicacao
HOST, PORT = "localhost", 8889

# dados sao obtidos da linha de comando
data = " ".join(sys.argv[1:])

# cria um socket (SOCK_STREAM para TCP, SOCK_DGRAM para UDP)
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    # conecta a servidor e manda dados
    sock.connect((HOST, PORT))
    sock.sendall(data + "\n")

    # recebe dados do servidor e termina programa
    received = sock.recv(1024)
    
    
finally:
	# fecha socket
    sock.close()

print "Enviado: %s"%data
print "Recebido: {}".format(received)