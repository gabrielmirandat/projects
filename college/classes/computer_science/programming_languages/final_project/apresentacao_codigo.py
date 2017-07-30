
#Bibliotecas usadas no programa

#Biblioteca que implementa thread (Padrão)

#Por meio dessa biblioteca, foi possível a geração de threads no programa.
#O programa em si faz uso de threads em duas situações:
    ##Para a inteface gráfica e operações que não afetam o funcionamento dessa (quase todas as operações do programa);
    ##Para realizar a leitura dos dados do twitter, uma vez que essa acquisição é realizada por meio de um streamer, que impede que a interface gráfica complete o loop de execução enquanto ele executa.

import threading

##########################################
#Biblioteca que implementa uso de expressẽs regulares (Padrão)
#Usando a biblioteca 're', foi possível realizar a tokenização do campo 'texto' dos twitters adquiridos pelo streamer.

import re

############################################

#Biblioteca Json(Padrão)
#Usando essa biblioteca, foi possível lidar com dados no formato JSON de maneira eficiente.

import json

##############################################

#Counter(Padrão)
#Essa biblioteca foi útil para o cálculo e organização das frequências dos tokens, separando-as por rótulos

from collections import Counter

#############################################################################

#Tkinter(sudo pip3 install tkinter ou sudo apt-get install python3-tkinter)
#Essa biblioteca foi usada para realizar a interface gráfica do programa

from tkinter import *

#####################################################################################

#Tweepy (sudo apt-get install python3-tweepy ou sudo pip3 install tweepy)
#Essa biblioteca foi usada para realizar o streaming dos dados do twitter
from tweepy.streaming import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream

##################################################################################

#Vincent(JS)
#Usado para tornar os dados legíveis para a biblioteca D3.js

import vincent

#############################################################################

#Web Browser (Padrão)
#Biblioteca usada para realizar operações com o browser (Usamos o Firefox)

import webbrowser

########################################################################################################################

#Regular Expressions para obtenção de expressões nos twitters
#Nota: expressoes_regulares foi adaptado do tutorial de mineração de dados do twitter: http://marcobonzanini.com/2015/03/09/mining-twitter-data-with-python-part-2/

expressoes_regulares = [
    r'<[^>]+>', # Essa parte pega tags HTML
    r'(?:@[\w_]+)', # Essa parte pega menções com @
    r"(?:\#+[\w_]+[\w\'_\-]*[\w_]+)", #Essa parte pega Hashtags
    r'http[s]?://(?:[a-z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-f][0-9a-f]))+', # Essa parte pega sites (URL)
 
    r'(?:(?:\d+,?)+(?:\.?\d+)?)', # Essa parte pega números
    r"(?:[a-z][a-z'\-_]+[a-z])", # Palavras com - e '
    r'(?:[\w_]+)', # Qualquer tipo de palavras
    r'(?:\S)' # Outras estruturas
]

###############################################################################################################################################################

#Palavras que não devem ser consideradas na ora de mostrar as frequências de tokens, uma vez que essas não possuem significado coerente

palavras_retiradas = ['http','https',"'",'in',',',']','[','}','{',')','(','-','for','at','la','"','/','&','at','are','is','it','she','he','we','i','?','!','rt','an','a','to','and','e',':','…','...',',',';','the','.']

######################################################################################

#Regular Expressions
#Compilação

tokens_expressoes_regulares = re.compile(r'('+'|'.join(expressoes_regulares)+')', re.VERBOSE | re.IGNORECASE)

######################################################################################

#Variáveis globais

#Chaves configuradas por default
chave_consumidor = 'jE7PH4Mbf2D0fxyMZQoQFtTdR'
segredo_consumidor = 'noK6zVnO5cXKDyfyIezPTToRK5Qux5qy7KTeyr5CZoIFakJXRD'
chave_tokenAcesso = '4012082602-TdksY8Dghe7tAbh7Eyx7nQlWAllBQFe2OpdwgeP'
segredo_tokenAcesso = 'SAZHuMPWyW7y87RUPhJMR6jUySSoC57Vi8Mr4L435Qn8P'

#nome do arquivo que será usado para registrar dados obtidos do twitter
arquivo_nome = 'twitter_data.json'

#Essa variável é útil para podermos salvar dados do twitter no arquivo sem apagar o conteúdo anterior
file_ = None

#Tipo de token configurado como 'all', para ser mostrado nos gráficos todos os tipos de tokens obtidos dos dados
#token_type pode assumir, também, 'hashtag' e 'mentions', mostrando somente termos com hashtags e termos com @ no início, respectivamente.
token_type = 'all'

#Número de tokens a ser mostrados nos gráficos de vizualização de frequência de tokens
token_num = 5

#Variáveis globais usadas na interface gráfica
raiz = None #Raiz da interface
t = None #Janelinha

#Leitor de dados digitados nos campos de digitação
e1 = None
e2 = None
e3 = None
e4 = None

#Variável usada para parar listener de dados do twitter, quando o usuário desejar
STOP = True

#Palavra chave definida por default

palavra = '#starwars' #Palavra a ser buscada no streamer

#1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111

#Thread de interface grafica

class uiThread (threading.Thread): #Implementa threading.Thread
#
    def __init__(self, threadID, name, counter):

        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter

#22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222

#Run da thread de interface gráfica

    def run(self):
    #
        global raiz

        raiz = Tk()
        raiz.wm_title("Twitter Mining")
        raiz.geometry("550x90+50+50")

        frame = Frame(raiz)
        frame.pack()

        token_config = Button(frame, text = "Configurar Tokens",command = self.entrada_acesso, width = 20)
        token_config.grid(row = 0, column = 0)

        chave_config = Button(frame, text = "Configurar Palavras-Chave",command = self.key,width = 20)
        chave_config.grid(row = 0,column = 1)

        data_acq = Button(frame, text = "Adquirir dados", command = self.data_acquire,width = 20)
        data_acq.grid(row = 0, column = 2)

        data_open = Button(frame, text = "Abrir Arquivo de Dados", command = self.data_open,width = 20)
        data_open.grid(row = 1, column = 0)

        token_num = Button(frame,text = "Numero de tokens",command = self.token_num,width = 20)
        token_num.grid(row = 1,column = 1)

        token_type = Button(frame,text = "Tipos de Tokens",command = self.token_type,width = 20)
        token_type.grid(row = 1,column = 2)

        data_token = Button(frame, text = "Tokens frequentes",command = self.tokenizer,width = 20)
        data_token.grid(row = 2, column = 0)

        data_geo = Button(frame, text = "Localizacao Geografica",command = self.geoLocation,width = 20)
        data_geo.grid(row = 2, column = 1)

        Sair = Button(frame, text = "Sair",command = self.finaliza, width = 20)
        Sair.grid(row = 2, column = 2)

        raiz.mainloop()

#3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333

    #Aquisição de dados relativos aos campos de autorização

    def getcons_key(self):
    #
        global chave_consumidor
        global e1

        if e1.get() is not None and e1.get() is not '':

            chave_consumidor = e1.get()
            print (chave_consumidor)

    def getcons_secret(self):
    #
        global segredo_consumidor
        global e2

        if e2.get() is not None and e2.get() is not '':

            segredo_consumidor = e2.get()
            print (segredo_consumidor)

    def getaccess_key(self):
    #
        global chave_tokenAcesso
        global e3

        if e3.get() is not None and e3.get() is not '':

            chave_tokenAcesso = e3.get()
            print (chave_tokenAcesso)

    def getaccess_secret(self):
    #
        global segredo_tokenAcesso
        global e4

        if e4.get() is not None and e4.get() is not '':

            segredo_tokenAcesso = e4.get()
            print (segredo_tokenAcesso)   


    def entrada_acesso(self):
    #
        global e1
        global e2
        global e3
        global e4

        t = Toplevel(raiz)
        t.wm_title("Configurando Chaves de Acesso")
        Label(t, text = "Consumer Key").grid(row=0)
        Label(t, text = "Consumer Secret").grid(row=1)
        Label(t, text = "Access Token Key").grid(row=2)
        Label(t, text = "Access Token Secret").grid(row=3)

        e1 = Entry(t)
        e2 = Entry(t)
        e3 = Entry(t)
        e4 = Entry(t)
    
        e1.grid(row=0,column=1)
        e2.grid(row=1,column=1)
        e3.grid(row=2,column=1)
        e4.grid(row=3,column=1)

        Button(t,text = 'GET',command = self.getcons_key).grid(row = 0, column = 2)
        Button(t,text = 'GET',command = self.getcons_secret).grid(row = 1, column = 2)
        Button(t,text = 'GET',command = self.getaccess_key).grid(row = 2, column = 2)
        Button(t,text = 'GET',command = self.getaccess_secret).grid(row = 3, column = 2)
        Button(t, text='Sair', command=t.destroy).grid(row=4, column=2, sticky=W, pady=4)

#44444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444

#Configura palavra chave a ser buscado

    def getkey(self):
    #
        global palavra
        global e1

        if e1.get() is not None and e1.get() is not '':

            palavra = e1.get()
            print ('Nova palavra-chave: ' + palavra)


    def key(self):
    #
        global e1

        t = Toplevel(raiz)
        t.wm_title("Palavra Chave")
        Label(t, text = "Palavras-Chave:").grid(row=0)

        e1 = Entry(t)
        e1.grid(row=0,column=1)

        Button(t, text = 'GET', command = self.getkey).grid(row = 0,column = 2)
        Button(t, text='Sair', command=t.destroy).grid(row=1, column=2, sticky=W, pady=4)


#5555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555

#Aquisição de dados

    def data_acquire(self):
    #
        global STOP
        global t

        STOP = True
        #Configura e começa a thread de aquisição de dados
        th2 = processThread(3, 'Leitor', 3)
        th2.start()

        #Cria uma janela nova
        t = Toplevel(raiz)
        t.wm_title("Adquirindo Dados!") #Título da janela
        Label(t,text = "Pressione 'Sair' para finalizar busca de dados!").grid(row = 0)

        #Botão de saída
        Button(t, text='Sair', command=self.stop).grid(row=5, column=1, sticky=W, pady=4)

#Função para parar thread de acquisição de dados

    def stop(self):
    #
        global STOP
        global t

        #Quando STOP = False, o streamer para de buscar dados
        STOP = False

        #Retirada da janela aberta anteriormente
        t.destroy()

#666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666666

#Imprime o arquivo de dados

    def leitura_arquivo(self):
    #
        global file_
        global arquivo_nome
        dados_arquivo = ''

        #Leitura de um arquivo para mostrar no label o JSON salvo
        file_ = open(arquivo_nome,'r')
        for jsons in file_:
            dados_arquivo = dados_arquivo + jsons

        return dados_arquivo

    def data_open(self):
    #
        t = Toplevel(raiz)
        t.wm_title("Dados do arquivo")

        scroll = Scrollbar(t)
        texto = Text(t,height = 50, width = 100)
        scroll.pack(side = RIGHT, fill = Y)
        texto.pack(side = LEFT, fill = Y)
        scroll.config(command = texto.yview)
        texto.config(yscrollcommand = scroll.set)
        texto.insert(END,self.leitura_arquivo())

#777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777

#Configura quais tipos de tokens devem ser mostrados no gráfico de frequências

    def tokens_all(self):
    #
        global token_type
        token_type = 'all'

    def tokens_mentions(self):
    #
        global token_type
        token_type = 'mentions'

    def tokens_hashtags(self):
    #
        global token_type
        token_type = 'hashtag'

    def token_type(self):
    #
        t = Toplevel(raiz)
        t.wm_title("Configurando Tokens")

        token_all = Button(t, text = "All",command = self.tokens_all, width = 20)
        token_all.grid(row = 0, column = 0)

        token_mentions = Button(t, text = "Mentions",command = self.tokens_mentions,width = 20)
        token_mentions.grid(row = 0,column = 1)

        token_hashtags = Button(t, text = "Hashtags", command = self.tokens_hashtags,width = 20)
        token_hashtags.grid(row = 0, column = 2)

        Sair = Button(t, text = "Sair", command = t.destroy,width = 20)
        Sair.grid(row = 1, column = 3)



#888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888888
#Configurar número de tokens

    def getnumtk(self):
    #
        global token_num
        global e1

        if e1.get() is not None and e1.get() is not '':

            token_num = e1.get()
            token_num = int(token_num)
            print ('Novo numero de tokens no grafico: ' + token_num)

    def token_num(self):
    #
        global e1

        t = Toplevel(raiz)
        t.wm_title("Configurando Tokens")
        Label(t, text = "Numero de tokens:").grid(row=0)

        e1 = Entry(t)
        e1.grid(row=0,column=1)

        Button(t,text = 'GET',command = self.getnumtk).grid(row = 0, column = 2)
        Button(t, text='Sair', command=t.destroy).grid(row=1, column=2, sticky=W, pady=4)


#9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999

#Nota: Método tokenizer(self) foi baseado no tutorial de mineração de dados do twitter: http://marcobonzanini.com/2015/03/09/mining-twitter-data-with-python-part-2/

#Realiza processamento de texto, tokenização e mostra de maneira gráfica os tokens mais frequentes, de acordo com a vontade do usuário (todos os tokens, hashtags ou @mentions)
    def tokenizer(self):

        global token_type
        global token_num
        global palavras_retiradas
        global file_
        global arquivo_nome
        global palavra
        global tokens_expressoes_regulares

        #Lista de palavras (símbolos) que não são considerados tokens
        palavras_proibidas = palavras_retiradas+[palavra] # [palavra] foi adicionada pois ela é o próprio token de busca, logo, será o que, provavelmente, terá a maior frequẽncia

        with open(arquivo_nome,'r') as file_:

            #Criação das estruturas do tipo Counter(), que armazenam um rótulos associados à valores
            contador_simbolos = Counter()
            contador_hashtag = Counter()
            contador_mentions = Counter()

            for jsons in file_:

                tweet = json.loads(jsons)
                #tokenização usando expressões regulares
                simbolos = tokens_expressoes_regulares.findall(tweet['text'])
                texto_twitter = [simbolo.lower() for simbolo in simbolos]

                #todos os tipos de símbolo
                terms_all = [termo for termo in texto_twitter if termo not in palavras_proibidas]
                contador_simbolos.update(terms_all)

                #Somente hashtags
                terms_hashtag = [termo for termo in texto_twitter if termo.startswith('#') and termo not in palavras_proibidas]
                contador_hashtag.update(terms_hashtag)

                #Somente @mentions
                terms_mentions = [termo for termo in texto_twitter if termo.startswith('@') and termo not in palavras_proibidas]
                contador_mentions.update(terms_mentions)

            #Dependendo de token_type, podemos estar interessados em mostrar gráficamente a frequência baseada em todos os tokens,
            #somente hashtags ou somente @mentions. Isso é realizado aqui.

            if token_type is 'all':

                freq_palavras = contador_simbolos.most_common(token_num)

            elif token_type is 'hashtag':

                freq_palavras = contador_hashtag.most_common(token_num)

            elif token_type is 'mentions':

                freq_palavras = contador_mentions.most_common(token_num)

            #Separação dos rótulos e frequências
            rotulos, frequencia = zip(*freq_palavras)

            #Geração de um dicionário com rótulos e frequencias
            dados = {'freq': frequencia, 'rotulo': rotulos}

            #Geração de um Bar vincent, para que o dado possa ser compreendido pela biblioteca D3.js, no HTML
            bar = vincent.Bar(dados,iter_idx = 'rotulo')
            #Armazena como um json em 'term_freq.json'
            bar.to_json('frequencia.json')

            webbrowser.get('firefox').open('chart.html')

#1010101010101101010101010101010101010101010101010101010101010

#Nota: Método geoLocation(self) foi baseado no tutorial de mineração de dados do twitter: http://marcobonzanini.com/2015/06/16/mining-twitter-data-with-python-and-js-part-7-geolocation-and-interactive-maps/

#Geo localização
    def geoLocation(self):

        global arquivo_nome

        with open(arquivo_nome, 'r') as file_:
            #Criando o GEOJSON
            dados_geograficos = {
                "type": "FeatureCollection",
                "features": []
            }
            for jsons in file_:

                tweet = json.loads(jsons)
                #Caso o tweet tenha o campo 'place', significa que suas coordenadas geográficas estão disponíveis no campo 'bounding_box'
                if tweet['place']:

                    place = tweet['place']['bounding_box']
                    #Geração das features de cada tweet
                    #NOTA: Os dados do twitter, hoje em dia, oferece as coordenadas na forma polygon, ou seja, em forma de polígono no mapa. Para fins de melhor vizualização, usaremos point e calcularemos o valor baseado nas coordenadas do polígono
                    feature_geografica = {

                        "type": "Feature",
                        "geometry": {"type":"Point","coordinates":[(place["coordinates"][0][0][0]+place["coordinates"][0][1][0]+place["coordinates"][0][2][0]+place["coordinates"][0][3][0])/4,(place["coordinates"][0][0][1]+place["coordinates"][0][1][1]+place["coordinates"][0][2][1]+place["coordinates"][0][3][1])/4]},
                        "properties": {
                            "text": tweet['text'],
                            "created_at": tweet['created_at']
                        }
                    }
                    
                    #Guarda nova feature nos dados geogŕaficos
                    dados_geograficos['features'].append(feature_geografica)
 
        # Save geo data
        with open('dados_geograficos.json', 'w') as fgeografico:

           fgeografico.write(json.dumps(dados_geograficos, indent=4))

        #Mostra mapa interativo
        webbrowser.get('firefox').open('map.html')


#11 11 11 11 11 11 11 11 11 11

#quit program

    def finaliza(self):
    #
        global raiz

        raiz.quit()

#121212121212121212121212121212121212121212121212121212121212121212121212

#Thread para aquisição de dados

class processThread (threading.Thread):

    def __init__(self,threadID, name, counter):
    #
        global file_
        global arquivo_nome

        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        file_ = open(arquivo_nome,'w')

    #Execução
    def run(self):
    #
        Leitor_twitter.Leitor_Stream(self)


#Classe para aquisição de dados

class Leitor_twitter(StreamListener):
    
    #Aquisição de dados, até STOP ==False
    def on_data(self, dado):
    #
        global STOP
        global file_

        print (dado)

        if (dado != None):#Caso não seja obtido nenhum dado, não faz nada

            file_.write(dado)

        return STOP

    def on_error(self, status):
    #
        print ("Erro na aquisicao de dados! Verifique sua conexão com a internet!")
        return STOP


#Streamer

    def Leitor_Stream(self):
    #
        global palavra

        #Realiza a autorização do usuário, para que os dados possam ser acessados por ele
        autorizacao = OAuthHandler(chave_consumidor, segredo_consumidor)
        autorizacao.set_access_token(chave_tokenAcesso, segredo_tokenAcesso)

        #Realiza o stream dos dados
        leitor_stream = Stream(autorizacao, Leitor_twitter())
        leitor_stream.filter(track=[palavra])

###########################################################################################################

#Execução

Programa = uiThread(2, "Programa", 2)
Programa.start()
