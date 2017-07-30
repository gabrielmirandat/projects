5

Tudo em Qt é um Q_OBJECT.
Todos os objetos em Qt se deletam.
Selecione uma função e pressione F1 para ser levado a documentação da classe da função mostrando sobre a função.
'SINAL -> SLOT'

QCoreApplication a(argc, argv) - aplicação por si só.

return a.exec() - fica rodando esperando evento do usuário.

MainWindow w; - gerado da mainwindow.h, que inclui GUI mainwindow.ui, que usa o namespace Ui.

w.show();

ui->setupUi(this); - cria interface do usuário.

//posso ligar um sinal a quantos slots eu quiser
connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
	ui->progressBar,SLOT(setValue(int))); - faz a ligação de um sinal com um slot através de código.

disconnect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
	ui->progressBar,SLOT(setValue(int))); - disfaz a ligação de um sinal com um slot através de código.


'Botão'
 'mainwindow.cpp'
  'MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent, ui(new Ui:MainWindow))'     
      abaixo de ui->setupUi(this)..
      ui->pushButton->setText("Hello"); - seta nome dentro do botão
      setCentralWidget(ui->plainTextEdit); - diz que o Widget central é o plainTextEdit, faz o plainTextEdit cobrir toda a janela.
 'interface gráfica'
      em edit signals, arrastamos um sinal pro botão.
      em Configure Connection, podemos ligar o click do botão a uma ação na mainWindow.
      'o sinal é clicked() e o slot é close()'
      'sinal e slot conectados devem ter o mesmo número de parâmetros'
      'podemos ligar sinais a slots de qualquer coisa que esteja no painel/interface'
