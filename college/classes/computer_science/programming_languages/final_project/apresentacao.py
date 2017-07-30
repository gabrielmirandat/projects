@'Premissas'

    'Portabilidade': códigos podem ser transferidos entre sistemas operacionais diferentes com pouca ou nenhuma modificação.
    'Extensão de módulos': o interpretador Python é facilmente estendido com novas funções e tipos de dados implementados em C ou C++ (ou 
			 outros idiomas que podem ser chamados a partir de C).
    'Código Aberto': vasta gama de contribuidores, com uma comunidade grande e ativa, o que facilita bastante o processo de desenvolvimento.
    'Produtividade': foco na facilidade de implementação e leitura, permitindo criação rápida e fácil de programas. 

@'Usuário característico'

Inicialmente a linguagem atrairia programadores usuários do sistema UNIX/UNIX-LIKE, mas logo seu uso se estendeu para centros especializados 
no ensino dos princípios de programação. Profissionalmente é usada em diversas áreas, tais como:

    'Aplicações Web'
        'Google': muitos componentes da Google Spider e sua máquina de busca.
        'Youtube': "para produzir recursos sustentáveis em termo recorde com o mínimo de desenvolvedores", Peter Norvig.
        'Dropbox': grande parte do serviço de hospedagem de arquivos na web. 

    'Jogos'
        'Battlefield 2': implementação dos elementos principais do gameplay como manutenção de pontuação e balanceamento de equipes.
        'Civilization IV': toda a lógica interna, incluindo a inteligência artificial.
        'Frets on Fire': completamente em Python, sendo que faz o uso da biblioteca Pygame. 

    'Gráficos'
        'Blender 3D': como linguagem de extensão.
        'Maya': como alternativa ao MEL (linguagem padrão do software).
        'Gimp': como script. 

    'Ciência'
        'NASA': linguagem padrão no Sistema de Planejamento Integrado do centro espacial Johnson, sendo que será instalada no novo Centro de 
	        Controle de Missão como auxiliar com uma interface de usuário shell. 

    'Desenvolvimento de software'
        'Nokia': para prover um ambiente de programação de alto nível para as plataformas S60 e Maemo. 

    'Governo'
        'CIA': site alimentado por Python/Zope/Plone. 

@'Domínio de aplicação'

Python é usado em vários domínios de aplicações.

'Desenvolvimento WEB e INTERNET '

    'Oferece várias alternativas para desenvolvimento web:'
        Frameworks como Django e Pyramid
        Micro-frameworks como Flask e Bottle
        Sistemas de gerenciamento de conteúdo avançadas, tais como Plone e django CMS. 

    'Bibliotecas padrão suportam vários protocolos de internet:'
        HTML and XML
        JSON
        Processamento de E-mai
        Suporte para  FTP, IMAP, e outros protocolos de internet.
        Interface socket de fácil uso. 

    'Sendo que o Package Index tem ainda mais bibliotecas:'
        Requests, poderosa biblioteca de cliente HTTP
        BeautifulSoup, um analisador HTML que pode lidar com todos os tipos de excentricidades do HTML
        Feedparser, para analisar feeds RSS/Atom
        Paramiko, implementa o protocolo SSH2
        Twisted Python, framework para programação assíncrona de rede.     

'Científico e Numérico'

    'Amplamente usado em cálculo científico e numérico:'
        SciPy, grupo de pacotes para matemática, ciência e engenharia.
        Panda, biblioteca de análise de dados e modelagem.
        IPython, poderosa shell interativa que promove fácil edição e registro de sessões de trabalho, e suporta visualização e programação 
		paralela. 

'Educação '

    Python é uma linguagem excelente para o ensino de programação, tanto em um nível introdutório quanto em mais avançados. 

'Desktop GUIs '

    A biblioteca Tk GUI está inclusa na maior parte das distribuições de python.
    Algumas ferramentas bastante úteis são disponibilizadas separadamente:
        wxWidgets
        Kivy, para aplicações multitouch
        Qt, via pyqt ou pyside 

    Há também ferramentas específicas de plataformas
        GTK+
        extensões win32 

'Desenvolvimento de software'

    Python é frequentemente usado como linguagem de suporte ao desenvolvimento de software, para gerir e controlar a arquitetura, testes e 
    muitas outras.
        SCons para controlar arquitetura
        Build e Apache Gump para compilação e teste continuo e automatizado
        Roundup ou Trac para rastrear bugs e desenvolver projetos. 
        
 
'Confiabilidade'

A verificação de dados em Phyton não realiza uma conversão implícita de um tipo de dado para outro e dá exceções quando tipos inconsistentes 
são utilizados. O que acontece é uma vinculação de nome e espaço a cada atribuição de valor a uma variável sendo que o tipo de dados do valor 
recebido é inferido. Também não existe uma definição dos tipos de parâmetros em funções ou método, ou seja, fica a cargo do programador o 
tratamento dos tipos recebido e retornados. Para exceções Phyton se baseia no conceito de herança provido da orientação a objetos. Todas
as exceções são derivadas da classe Exception. Assim, graças a unificação entre classe e tipos – e subclasses sendo subtipos – ao tratar 
uma exceção de uma determinada classe todas as subclasses dessa exceção também são tratadas. Esse suporte ao tratamento de exceções nativo
em Phyton é importante, pois evita que sejam feitas verificações que tornariam o código mais complexo e impactariam direto a legibilidade, 
o custo de implementação e a manutenção como em outras linguagens. A manipulação de exceções aumento a confiabilidade e contribuem para 
evitar que o programa seja finalizado de forma inesperada. Também é importante para sua confiabilidade a facilidade encontrada no modelo 
de objetos que garante que objetos mutáveis com listas, dicionários e entidades externas como arquivos e janelas funcionem quase como 
ponteiros. Isso porque quando passados como argumento para uma função e modificados o chamador vê a mudança. Possui um alto grau de 
flexibilidade o que impacta negativamente sua confiabilidade. Porém, com um modelo elegante de objetos, com o tratamento nativo de 
exceções orientado a objetos e com alta capacidade de abstração e recursos funcionais, isso é contrabalanceado. A verificação de 
tipos pesa muito na confiabilidade geral da linguagem Phyton, tornando-a uma linguagem de baixa confiabilidade. 

'Especificidades'

Foram usadas diversas bibliotecas, como as padrões da linguagem e às externas à ela. Além disto foram usados arquivos html para 
visualização no navegador de internet.

'Bibliotecas padrão'

    'threading': possibilita a criação e manipulação de threads em geral, as quais foram essenciais para o funcionamento do programa.
    're': usada para compilar uma expressão regular, responsável pela tokenização dos textos obtidos pelo twitter.
    'json': permite que jsons sejam manipulados facilmente no ambiente python (principalmente como dicionários).
    'counter (de collections)': permite a contagem de tokens, a fim de verificar suas frequências.
    'webbrowser': permite o controle de utilização de browsers. 

'Bibliotecas externas'

    'tkinter': para gerar a interface gráfica, bem como o controle de suas utilidades.
    'tweepy': para obter os dados a serem analisados.
    'vincent': permite a conversão de dados em formato dicionário do python em um formato inteligível para a biblioteca D3.js do javascript, 
    muito boa para vizualização de dados. 

'Arquivos HTML'

    'chart.html':  para comparar a quantidade de tokens mais frequentes.
    'map.html': para visualizar a densidade de tweets geograficamente. 
