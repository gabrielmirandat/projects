SDL como uma biblioteca ligada dinamicamente. Uma biblioteca ligada dinamicamente tem 3 partes:
    "Os arquivos de cabeçalho (Library.h)
    "Os arquivos de biblioteca (Library.lib para Windows ou libLibrary.a para * nix)
    "Os arquivos binários (Library.dll para Windows ou Library.so para * nix)
    
    'SDL1.2 -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer'
        #include <SDL/SDL.h>
        #include <SDL/SDL_image.h>
        #include <SDL/SDL_ttf.h>
        #include <SDL/SDL_mixer.h>
    
    
    'SDL2.0 -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer'
	#include<SDL2/SDL.h>
        #include <SDL2/SDL_image.h>	//Setamos SDL_image para carregar imagens PNG e economizar espaço 
        #include <SDL2/SDL_ttf.h>
        #include <SDL2/SDL_mixer.h>
        
        'Basics' 25
        'Otimização de surface e alongamento suave' 134
        'PNGs com SDL_image' 161
        'Carregando textura e renderizando' 179
	
	
#SDL2 basics
    //Main definida
    int main( int argc, char* args[] )

    //A janela em que estaremos renderizando
    SDL_Window* window = NULL;
    
    // Uma SDL_Surface é apenas uma imagem 2D.Uma imagem 2D pode ser carregado a partir de um arquivo ou pode ser a imagem dentro de uma janela.
    //Uma superfície SDL é apenas um tipo de dados de imagem que contém os pixels de uma imagem junto com todos os dados necessários para renderizá-la. 
    //Superfícies SDL usam software de renderização que significa que ele usa a CPU para renderizar.
    //Surface contida na janela.
    SDL_Surface* screenSurface = NULL;
    //A imagem que vamos carregar e mostrar na tela. 
    SDL_Surface* gHelloWorld = NULL;
    
    //Initializa SDL.Você não pode chamar as funções SDL sem inicializar SDL primeiro.Inicia somente sistema de vídeo. Quando há um erro, SDL_Init retorna -1.
    //Quando há um erro, queremos printar no console o que aconteceu, caso contrário a aplicação apenas dá um flash e sai. SDL_GetError retorna o último erro 
    //produzido por uma função SDL.
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { 
      printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); 
    }
    
    //Com SDL_CreateWindow criamos uma janela. O primeiro argumento define a legenda da janela. Os próximos dois argumentos defininem a posição X e Y onde a
    //janela é criada. Os próximos dois argumentos defininem largura e altura da janela. O último argumento são as flags de criação. SDL_WINDOW_SHOWN garante 
    //que a janela é mostrada quando ela é criada.
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    
    //Geta surface da janela, para podermos desenhar nela.Queremos mostrar imagens dentro da janela e, a fim de fazer isso é preciso obter a imagem dentro da janela.
    screenSurface = SDL_GetWindowSurface( window );
    
    //Preenche a surface de branco 
    SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
    
    //Update a surface para que possa ver tudo o que desenhou. Sem ela não é possível ver nada. Lembre que há dois buffers, com esta função passamos o que está no buffer
    //traseiro para o frontal.
    SDL_UpdateWindowSurface( window );
    
    //Espera por dois segundos 
    SDL_Delay( 2000 );
    
    //Destroi janela para liberar memória
    SDL_DestroyWindow( window );
    window = NULL;
    
    //Sair do SDL 
    SDL_Quit();
    
    //SDL_LoadBMP leva no caminho de um arquivo bmp e retorna a superfície carregada. Retorna NULL em caso de erro
    //Carrega imagem
    gHelloWorld = SDL_LoadBMP( "02_getting_an_image_on_the_screen/hello_world.bmp" );
    
    //Desaloca surface. Nós colamos a superfície carregada na superfície da tela usando SDL_BlitSurface.O que blitting faz é pegar uma superfície de origem 
    //e carimbar uma cópia do mesmo na superfície do destino.
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL; 
    
    //Apica a imagem.  
    SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );
    
    //Jogos exigem que você lide com a entrada do usuário. Você pode fazer isso com SDL usando o sistema de manipulação de eventos - event handling system.
    //Declaramos uma union SDL_Event. Um SDL event é algo como apertar um botão, movimento de mouse, apertar um botão de joystick, etc. 
    //SDL_PollEvent vai continuar a tomar eventos da fila até que ela esteja vazia. Quando a fila está vazia, SDL_PollEvent retornará 0 (só que sempre tem eventos!). 
    //Então, o que este pedaço de código faz é tomar eventos da fila de eventos até que ela esteja vazia. Se um evento da fila de eventos é um evento SDL_QUIT 
    //(que é o caso quando o usuário aperta X para fora da janela), vamos escolher o sinalizador sair para true para que possamos sair do aplicativo.
    SDL_Event e;
    //Main loop ou loop do jogo. O que ela faz é manter o processamento da fila de eventos até que ela esteja vazia.
    while( !quit ) {
      //Manipular eventos na fila
      while( SDL_PollEvent( &e ) != 0 ) {                   //O que SDL_PollEvent faz é pegar o evento mais recente da fila de eventos e colocar os dados do evento 
	//Se usuário requer sair do programa                // no SDL_Event passado para a função
	if( e.type == SDL_QUIT ) { 
	  quit = true; 
	}		 
      }
    }
    
    //Constantes de teclas do teclado 
    enum KeyPressSurfaces { 
      KEY_PRESS_SURFACE_DEFAULT,
      KEY_PRESS_SURFACE_UP, 
      KEY_PRESS_SURFACE_DOWN, 
      KEY_PRESS_SURFACE_LEFT, 
      KEY_PRESS_SURFACE_RIGHT,
      KEY_PRESS_SURFACE_TOTAL 
    };
    
    //Então vamos lidar com um evento SDL_KEYDOWN. Este evento acontece sempre que você pressionar uma tecla no teclado.
    //Usário pressionou uma tecla 
    else if( e.type == SDL_KEYDOWN ) { 
      //Seleciona surfaces de acordo com a tecla pressionada 
      switch( e.key.keysym.sym ) {                                          //Dentro do evento SDL tem um evento Keyboard SDL, que contém as informações para o evento-chave. 
	case SDLK_UP:                                                       //Dentro deste existe um keysym SDL, que contém as informações sobre a chave que foi pressionada. 
	  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_UP ];      //Dentro da keysym contém o SDL Keycode que identifica a tecla que foi pressionada.
	  break; 
	case SDLK_DOWN: 
	  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DOWN ]; 
	  break; 
	case SDLK_LEFT: 
	  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_LEFT ]; 
	  break; 
	case SDLK_RIGHT: 
	  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_RIGHT ];
	  break; 
	default:
	  gCurrentSurface = gKeyPressSurfaces[ KEY_PRESS_SURFACE_DEFAULT ]; 
	  break; 
      }
    }
    
#Otimização de surface e alongamento suave
Até agora temos blitting nossas imagens crua. Uma vez que só estava mostrar uma imagem, isso não importa. Quando você está fazendo um jogo, blitting 
imagens cruas causam processamento desnecessário. Iremos convertê-los para um formato otimizado para acelerá-los.SDL2 também tem um novo recurso para 
superfícies SDL chamado Soft Stretching (alongamento suave), que permite que você blit uma imagem redimensionada para um tamanho diferente. Neste tutorial vamos dar
uma imagem de metade do tamanho da tela e esticá-lo para o tamanho total.

    //Converte surface to formato da tela 
    //Veja quando você carrega um bitmap, é normalmente carregado em um formato de 24 bits já que a maioria bitmaps são 24bit. A maioria, se não todos, 
    //displays modernos não são 24bit por padrão. Se nós blit uma imagem que é de 24 bits para uma imagem de 32 bits, SDL irá convertê-lo cada vez que 
    //a imagem é blitted. Então, o que vamos fazer quando uma imagem é carregada é convertê-lo para o mesmo formato que a tela de forma que nenhuma conversão 
    //precise ser feita a cada blit
    optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, NULL );
    //Libera a surface não otimizada
    SDL_FreeSurface( loadedSurface );
    
    //SDL2 tem uma nova função dedicada a blit imagens para um tamanho diferente: SDL_BlitScaled. Como blitting imagens de antes, SDL_BlitScaled leva em 
    //uma superfície de origem para blit na superfície do destino. Ele também leva em uma SDL_Rect destino que define a posição e o tamanho da imagem que
    //você está blitting.Portanto, se queremos ter uma imagem que é menor do que a tela e torná-la do tamanho da tela, você faz o destino largura / altura
    //para ser a largura / altura da tela.
    //Apply the image stretched 
    SDL_Rect stretchRect; 
    stretchRect.x = 0; 
    stretchRect.y = 0; 
    stretchRect.w = SCREEN_WIDTH; 
    stretchRect.h = SCREEN_HEIGHT;
    SDL_BlitScaled( gStretchedSurface,NULL,gScreenSurface,&stretchRect);
    
#PNGs com SDL_image
    //Agora que estamos usando SDL_image, precisamos inicializar. Aqui queremos inicializar SDL_image com PNG carregamento, então nós passamos nas bandeiras PNG
    //carregamento em IMG_Init. IMG_Init retorna as bandeiras que carregaram com êxito. Se as bandeiras que são retornados não contêm as bandeiras que pedimos, 
    //isso significa que há um erro. Quando há um erro com SDL_image, você começa cadeia de erro com IMG_GetError em oposição a SDL_GetError.
    //Inicializa carregamento PNG 
    int imgFlags = IMG_INIT_PNG; 
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) { 
      printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() ); 
      success = false; 
    } else { 
      //Geta surface da janela 
      gScreenSurface = SDL_GetWindowSurface( gWindow );
      
    //Agora ele usa IMG_Load em oposição a SDL_LoadBMP. IMG_Load pode carregar diversos tipos de formato que você pode descobrir sobre na documentação SDL_image.
      //Carrega imagem do caminho especificado 
      SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    //Quit SDL subsystems 
      IMG_Quit();
      
#Carregando textura e renderizando
Uma nova adição ao SDL2 é a biblioteca de renderizar textura. Ela nos dá renderização baseada em hardware rápida e flexível. Usaremos esta nova técnica.
    //Carrega imagem individual como se fosse uma textura
    SDL_Texture* loadTexture( std::string path ); 
    //A janela renderizadora. Quando lidamos com texturas SDL precisamos de um SDL_Renderer para colocá-lo na tela
    SDL_Renderer* gRenderer = NULL; 
    //Currente textura sendo mostrada 
    SDL_Texture* gTexture = NULL;
    //Cria renderizador para janela para podermos renderizar nela.
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    //Inicializa cor de renderização 
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    //Cria textura dos pixels da surface, ou seja, cria textura da surface loadedSurface
    newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
    //Nos desfazemos da antiga surface 
    SDL_FreeSurface( loadedSurface );
    //Libera imagem carregada texturizada 
    SDL_DestroyTexture( gTexture );
    gTexture = NULL;
    //Destroi renderizador 
    SDL_DestroyRenderer( gRenderer );
    gRenderer = NULL;
    //Limpa a tela. Esta função preenche a tela com a cor que foi o último set com SDL_SetRenderDrawColor.
    SDL_RenderClear( gRenderer ); 
    //Renderiza a texture na tela.Com a tela apagada, renderizamos a textura com SDL_RenderCopy
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    //Atualiza tela. Com a textura renderizada, ainda temos que atualizar a tela, mas desde que não estamos usando SDL_Surfaces para renderizar não podemos usar 
    //SDL_UpdateWindowSurface. Em vez disso, temos que usar SDL_RenderPresent 
    SDL_RenderPresent( gRenderer );
 
#Renderizando Geometrias
Junto com a nova API texturização, SDL tem novas chamadas de renderização primitivos como parte de sua API de renderização. Então, se você precisar de algumas formas 
básicas prestados e você não quer criar gráficos adicionais para eles, SDL pode poupar o esforço. 
    //Renderiza quadrado vermelho preenchido 
    SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 }; // (x position, y position, width, and height)
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0x00, 0x00, 0xFF );  // R is the red component, G is green, B is blue, and A is alpha
    SDL_RenderFillRect( gRenderer, &fillRect );
    //Renderiza quadrado verde delineado 
    SDL_Rect outlineRect = { SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3 }; 
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF ); 
    SDL_RenderDrawRect( gRenderer, &outlineRect ); 
    //Desenha linha azul horizontal
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0xFF, 0xFF ); 
    SDL_RenderDrawLine( gRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2 );
    //Desenha linha vertical amarela pontilhada
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0x00, 0xFF ); 
    for( int i = 0; i < SCREEN_HEIGHT; i += 4 ) { 
      SDL_RenderDrawPoint( gRenderer, SCREEN_WIDTH / 2, i ); 
      
    } //Update screen 
    SDL_RenderPresent( gRenderer );
    
#Viewport
Algumas vezes você quer apenas renderizar parte da tela para coisas como minimapas. Usando viewport você pode controlar onde renderizar na tela.  
    //Canto cima esquerdo viewport. Criamos o retângulo e passamos para a função SDL_RenderSetViewport().Qualquer renderização feita depois dessa chamada
    //será realizada dentro dessa região definida pela viewport e usará o sistemas de coordenadas da própria janela criada.
    SDL_Rect topLeftViewport; 
    topLeftViewport.x = 0; 
    topLeftViewport.y = 0; 
    topLeftViewport.w = SCREEN_WIDTH / 2; 
    topLeftViewport.h = SCREEN_HEIGHT / 2; 
    SDL_RenderSetViewport( gRenderer, &topLeftViewport );
    //Renderiza textura na tela 
    SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
    //Apenas atualiza janela 
    SDL_RenderPresent( gRenderer );
    
#Color Key
Como remover a cor de fundo ao aplicar uma surface. A estrutura SDL_Surface tem uma estrutura chamada Color_key, que é a cor que você não quer mostrar quando for anexar
uma surface.É o que usa quando se quer fundos transparentes.
    //Color_key a imagem. Primeiro argumento é a surface que a gente quer color_key, o segundo pergunta se queremos permitir color_key e o terceiro é o pixel que queremos
    //color_key. O melhor jeito de criar um pixel RGB é com SDL_MapRGB. O primeiro argumento é o formato que queremos o pixel, os últimos são as componentes R G e B. Aqui
    //mapeamos o cyano que é R0 G255 e B255.
    SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );
    //Renderiza definição de espaço e renderiza para a tela.Até agora, renderizàvamos imagens em tela todo e por isso não precisávamos especificar posição.Por isso 
    //chamàvamos SDL_RenderCopy com os últimos argumentos NULL. Mas quando queremos renderizar em um lugar específico, precisamos dizer quais as posições x,y,w,h.
    SDL_Rect renderQuad = { x, y, mWidth, mHeight };
    SDL_RenderCopy( gRenderer, mTexture, NULL, &renderQuad );

#Renderização cortada e sprites
Ás vezes você só quer renderizar parte da textura. Muitas vezes games preferem manter múltiplas imagens do mesmo sprite do que ter um monte de texturas. Usando renderização
cortada, podemos definir uma porção da textura a ser renderizada do que renderizar tudo.
    //Cena dos sprites 
    SDL_Rect gSpriteClips[ 4 ];
    //Em primeiro lugar, uma vez que você está cortando e você estiver usando as dimensões do retângulo de recorte em vez da textura, vamos definir a largura/altura do 
    //retângulo de destino (aqui chamado renderQuad) para o tamanho do retângulo de recorte.Em segundo lugar, vamos passar o retângulo de recorte para SDL_RenderCopy 
    //como o retângulo de origem. O retângulo de origem define que parte da textura você deseja renderizar. Quando o retângulo de origem é NULL, toda a textura é renderizada.
    //Seta espaço de renderização e renderiza na tela 
    SDL_Rect renderQuad = { x, y, mWidth, mHeight }; 
    //Seta dimensões do recorte do rendering 
    if( clip != NULL ) { 
      renderQuad.w = clip->w; 
      renderQuad.h = clip->h; } 
    //Renderiza na tela 
    SDL_RenderCopy( gRenderer, mTexture, clip, &renderQuad );
    
#Modulação de cor
Modulação de cor permite que você altere a cor de suas texturas renderizadas. Aqui nós estamos indo para modular uma textura usando várias cores.
    //Modula a textura, recebendo cores Uint8 (unsigned int 8 bits). Modulação de cor é apenas uma maneira de multiplicar uma cor em toda a textura.
    SDL_SetTextureColorMod( mTexture, red, green, blue );
    
#Modulação de alpha (que trabalha parecido com Modulação de cor) para controlar a transparência de uma textura
Aqui na função de carregar textura, estamos carregando a textura principal, que vamos misturar alpha e a textura de fundo. Enquanto a textura principal vai ficando
transparente, estaremos aptos a ver mais da textura de fundo. Como pode ver no código, depois de carregarmos a textura principal sucessivamente nós setamos SDL_BlendMode 
para misturar, então o misturamento está ativado. Desde que o fundo não vai ser transparente, não precisamos setar o misturamento nele.
    //Seta modo de mistura 
    void setBlendMode( SDL_BlendMode blending );
    //Seta Modulação de alpha 
    void setAlpha( Uint8 alpha );
    //Seta mistura de alpha padrão 
    gModulatedTexture.setBlendMode( SDL_BLENDMODE_BLEND );
     //Seta função de misturamento. Nos permite ativar o misturamento
    SDL_SetTextureBlendMode( mTexture, blending );
    //Modula a textura alpha. Nos permite setar a quantidade de alpha na textura mandada por argumento.
    SDL_SetTextureAlphaMod( mTexture, alpha );
    
#Sprites animados e Vsync
Várias imagens seguidas para dar efeito de animação. Desde que imagens em SDL2 são tipicamente SDL_Textures, animação em SDL é uma questão de mostrar diferentes partes 
de uma textura (ou texturas diferentes por inteiro), um após o outro.

    //Cria renderizador vsynced para jenelas.Neste tutorial (e tutoriais futuros), queremos usar o Sync Vertical. VSync permite à renderização atualizar ao mesmo tempo, 
    //como junto com suas atualizações do monitor durante o refresh vertical. Para este tutorial, que vai garantir que a animação não corra muito rápido. A maioria dos 
    //monitores executam em cerca de 60 quadros por segundo e esse é o pressuposto de que estamos fazendo aqui. Se você tem uma taxa de atualização do monitor diferente,
    //isso explicaria por que a animação está correndo muito rápido ou lento. 
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    //Seta cortes nos sprites
    gSpriteClips[ 0 ].x = 0; 
    gSpriteClips[ 0 ].y = 0;           ...
    gSpriteClips[ 0 ].w = 64;
    gSpriteClips[ 0 ].h = 205;
 
#Rotação e inversão
Hardware acelerado para renderização de textura no SDL2 nos dá a abilidade de rápida rotação e inversão.
    //Renderiza textura num dado ponto 
    void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE ); 
    //Renderiza para tela. Essa função funciona da mesma forma do SDL_RenderCopy original, mas com argumentos adicionais para a rotação e inversão. 
    SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
    //Tipo da inversão 
    SDL_RendererFlip flipType = SDL_FLIP_NONE;
    //Tipos na main
    case SDLK_q: 
      flipType = SDL_FLIP_HORIZONTAL; 
      break; 
    case SDLK_w: 
      flipType = SDL_FLIP_NONE; 
      break; 
    case SDLK_e: 
      flipType = SDL_FLIP_VERTICAL;
      break;

#Fontes ttf (TrueTypeFonts)
A maneira SDL_ttf funciona é que você cria uma nova imagem a partir de uma fonte e cor. Para a nossa classe textura tudo o que significa é que nós vamos estar carregando 
a nossa imagem de texto processado por SDL_ttf em vez de um arquivo.
    //Fonte global usada 
    TTF_Font *gFont = NULL;
    //Renderiza surface de texto.Carregamos uma superfície usando TTF_RenderText_Solid. Isso cria uma superfície de cor sólida a partir da fonte, texto e cor dada.
    SDL_Surface* textSurface = TTF_RenderText_Solid( gFont, textureText.c_str(), textColor );
    //Inicializa SDL_ttf 
    if( TTF_Init() == -1 ) { ...}
    //Abre a fonte 
    gFont = TTF_OpenFont( "16_true_type_fonts/lazy.ttf", 28 );
    //Libera fonte global 
    TTF_CloseFont( gFont ); 
    gFont = NULL;
    //Sai dos subsistemas SDL 
    TTF_Quit(); 
    IMG_Quit(); 
    SDL_Quit();
    
#Eventos com mouse
Tal como com as teclas, SDL tem estruturas de eventos para tratar eventos de mouse, como o movimento do mouse, botões do mouse, pressioná-lo e soltá-lo. 
    //Constantes p/ teclas
    const int BUTTON_WIDTH = 300; 
    const int BUTTON_HEIGHT = 200; 
    const int TOTAL_BUTTONS = 4; 
    
    enum LButtonSprite { 
      BUTTON_SPRITE_MOUSE_OUT = 0, 
      BUTTON_SPRITE_MOUSE_OVER_MOTION = 1, 
      BUTTON_SPRITE_MOUSE_DOWN = 2,
      BUTTON_SPRITE_MOUSE_UP = 3, 
      BUTTON_SPRITE_TOTAL = 4 
    };
    //Posição do topo esquerdo.  
    SDL_Point mPosition; 
    //Se evento do mouse aconteceu
    if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP ) {
      //Geta posição do mouse  
      int x, y; 
      SDL_GetMouseState( &x, &y ); 
    }
    
#Estados de chave
Como vimos no tutorial de entrada do mouse, há maneiras de se obter o estado dos dispositivos de entrada (mouse, teclado, etc), sem o uso de eventos. Neste tutorial, 
vamos refazer o tutorial entrada do teclado usando estados-chave (ou key states), em vez de eventos.
    
    //Manipulador de evento. Uma coisa importante a saber sobre como SDL manipula key states é que você ainda precisa de um loop de evento. Internamente no SDL, keystates são
    //atualizados quando SDL_PollEvent() é chamada, então certifique-se que você colocou todos os eventos na fila antes de checar key states.
    SDL_Event e;
    //Seta textura baseado no keystate currente.Primeiro temos um ponteiro para o array de estados-chave usando SDL_GetKeyboardState.O estado de todas as chaves são ordenados 
    //por SDL_Scancode. Scancode são como os valores SDL_Keycode, apenas scancodes são designados para trabalhar com teclados internacionais.
    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL ); 
    if( currentKeyStates[ SDL_SCANCODE_UP ] ) { 
      currentTexture = &gUpTexture; 
    }else if( currentKeyStates[ SDL_SCANCODE_DOWN ] ) { 
      currentTexture = &gDownTexture; 
    }else if( currentKeyStates[ SDL_SCANCODE_LEFT ] ) { 
      currentTexture = &gLeftTexture; 
    }else if( currentKeyStates[ SDL_SCANCODE_RIGHT ] ) { 
      currentTexture = &gRightTexture; 
    }else { 
      currentTexture = &gPressTexture; 
    }

#Gamepads e joysticks
Assim como com a entrada do mouse e do teclado, SDL tem a capacidade de ler a entrada de um controlador de joystick / gamepad / jogo. Neste tutorial vamos estar fazendo 
uma rotação seta com base na entrada de um joystick.

    //Joystick analógico zona morta.A forma como lida com SDL sticks analógicos em um controlador de jogo é que ele converte a sua posição em um número entre -32768 a 32767.
    //Isso significa um leve toque poderia relatar uma posição de 1000. Queremos ignorar toques leves, por isso, queremos criar uma zona morta, onde a entrada do joystick é 
    //ignorado. É por isso que nós definimos esta constante e vamos ver como ele funciona mais tarde.
    const int JOYSTICK_DEAD_ZONE = 8000;
    //Manipulador do controlador de jogo 1 
    SDL_Joystick* gGameController = NULL;
    //Inicializa SDL. Agora precisamos inicializar o subsistema joystick ou leitura de joystick não vai funcionar.
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK ) < 0 )
    //Checa por joysticks 
      if( SDL_NumJoysticks() < 1 ){ ..}
      else { 
	//Carrega joystick. Chamamos SDL_JoystickOpen para abrir o joystick no índice 0. Após o joystick é aberto, ele agora irá relatar eventos para a fila de eventos SDL.
	gGameController = SDL_JoystickOpen( 0 );
    //Fecha o controlador do jogo 
    SDL_JoystickClose( gGameController ); 
    gGameController = NULL;
    //Para esta demonstração, nós queremos manter o controle da direção x e y. Se o x é igual a -1, o joystick na posição x está apontando para a esquerda. Se é +1, a 
    //posição x é apontando para a direita. A posição y para joysticks tem positiva sendo cima e negativa sendo baixo, então y = 1 é para cima e y = -1 é baixo. Se x ou y é 0,
    //que significa que está na zona morta e fica no centro.
    else if( e.type == SDL_JOYAXISMOTION ) { 
      //Movimentação no controlador 0 
      if( e.jaxis.which == 0 ) { 
	//Movimentação no eixo x 
	if( e.jaxis.axis == 0 ) { 
	  //Esquerdo ou zona morta
	  if( e.jaxis.value < -JOYSTICK_DEAD_ZONE ) { 
	    xDir = -1; 
	  } 
	  //Direito ou zona morta 
	  else if( e.jaxis.value > JOYSTICK_DEAD_ZONE ) { 
	    xDir = 1; 
	  } else { 
	    xDir = 0; 
	  } 
	}
      //Movimentação no eixo y 
      else if( e.jaxis.axis == 1 ) { 
	//Abaixo ou zona morta 
	if( e.jaxis.value < -JOYSTICK_DEAD_ZONE ) { 
	  yDir = -1; 
	} 
	//Acima ou zona morta 
	else if( e.jaxis.value > JOYSTICK_DEAD_ZONE ) { 
	  yDir = 1; 
	}else { 
	  yDir = 0; 
	} 
      } 
    } 
  }
    //Calcula ângulo 
    double joystickAngle = atan2( (double)yDir, (double)xDir ) * ( 180.0 / M_PI ); 
    //Corrige ângulo 
    if( xDir == 0 && yDir == 0 ) { joystickAngle = 0; }
 
#Feedback da força
Agora que sabemos como usar joysticks com SDL, podemos usar a nova API haptics para fazer o controle mexer.
    //Manipulador do controlador 1 com feedback de força. Um dispositivo háptico é algo que dá algum tipo de feedback ao físico. Neste caso, faz o estrondo do controlador. 
    //O tipo de dados para um dispositivo háptico é intuitivamente chamado SDL_haptic. 
    SDL_Joystick* gGameController = NULL; 
    SDL_Haptic* gControllerHaptic = NULL;
    //Inicia haptic subsystem
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC ) < 0 )
    //Geta dispositivo haptic do controlador. 
    gControllerHaptic = SDL_HapticOpenFromJoystick( gGameController );
    //Inicializa o vibrador 
    if( SDL_HapticRumbleInit( gControllerHaptic ) < 0 )
    //Fecha controlador de jogo com o haptic 
    SDL_HapticClose( gControllerHaptic ); 
    SDL_JoystickClose( gGameController ); 
    gGameController = NULL; 
    gControllerHaptic = NULL;
    //Joystick butão foi pressionado
    else if( e.type == SDL_JOYBUTTONDOWN ) { 
      //Play rumble at 75% strenght for 500 milliseconds 
      if( SDL_HapticRumblePlay( gControllerHaptic, 0.75, 500 ) != 0 )
	
#Efeitos de som e música
    //A música que será tocada
    Mix_Music *gMusic = NULL;
    //Os efeitos de som que serão usados
    Mix_Chunk *gScratch = NULL; 
    Mix_Chunk *gHigh = NULL; 
    Mix_Chunk *gMedium = NULL; 
    Mix_Chunk *gLow = NULL;
    //Inicializa áudio 
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
    //Inicializa o SDL_mixer 
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    //Captura algum erro do SDL_mixer
    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    //Carrega música 
    gMusic = Mix_LoadMUS( "21_sound_effects_and_music/beat.wav" );
    //Carrega efeito de som
    gScratch = Mix_LoadWAV( "21_sound_effects_and_music/scratch.wav" );
    //Libera efeito de som 
    Mix_FreeChunk( gScratch );
    //Libera a música 
    Mix_FreeMusic( gMusic );
    //Sai do SDL_mixer 
    Mix_Quit();
    //Toca efeito de som gHigh
    Mix_PlayChannel( -1, gHigh, 0 );
    //Se não tem nenhuma música tocando
    if( Mix_PlayingMusic() == 0 ) { 
      //Toca a música
      Mix_PlayMusic( gMusic, -1 );
    //Se a música está pausada
    if( Mix_PausedMusic() == 1 ) { 
      //Continua a música 
      Mix_ResumeMusic();
    //Pausa a música 
    Mix_PauseMusic();
    //Para a música 
    Mix_HaltMusic();
    
#Timing
Outra parte importante de qualquer tipo de API de jogo é a capacidade de lidar com o tempo.
    //Inicializar de tempo currente. 
    Uint32 startTime = 0;
    //Reseta tempo de início no clique de retorno. Há uma função chamada SDL_GetTicks que retorna o tempo desde que o programa começou em milissegundos
    else if( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN){ 
      startTime = SDL_GetTicks(); 
    }
    
#Timers Avançados
É hora de fazer um que pode iniciar / parar / pausa.
    //O tempo do relógio quando o temporizador começou 
    Uint32 mStartTicks; 
    //O tempo guardado quando o timer foi pausado 
    Uint32 mPausedTicks;
    
#Calculando Frame Rate
Vamos usar o timer para medir fps.

#Nivelando Frame Rate


#Movimento
Agora que sabemos como processar, manipular a entrada, e lidar com o tempo, agora podemos saber tudo o que precisamos para mover as coisas na tela. Aqui vai fazer 
um ponto básico se mover.
    //Se você está se perguntando por que estamos verificando se a repetição das teclas é 0, é porque repetição das teclas é ativado por padrão e se você pressionar e 
    //segurar a tecla irá reportar múltiplas teclas pressionadas. Isso significa que temos de verificar se a imprensa chave é o primeiro, porque nos importamos somente 
    //quando a tecla foi pressionada pela primeira vez.
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
   
#Detecção de colisão
Esta forma de detecção de colisão é chamado de teste do eixo de separação onde tentamos encontrar um eixo onde os objetos estão separados. Se não houver eixo de separação, 
em seguida, os objectos estão colidindo.
    
#Detecção de colisão por pixel

#Detecção de colisão circular
Verificando colisão entre dois círculos é fácil. Tudo que você tem a fazer é verificar se a distância entre o centro de cada círculo é menor do que a soma de seus raios (raios 
é o plural de raio). Para box / círculo colisão, você tem que encontrar o ponto na caixa de colisão que está mais próximo do centro do círculo. Se este ponto é menor do que
o raio do círculo, existe uma colisão.

#Scrolling
Até agora lidamos apenas com os níveis do tamanho da tela. Com a rolagem, você pode navegar através de níveis de qualquer tamanho, tornando tudo em relação a uma câmera.
O princípio básico da rolagem é que você tem um retângulo que funciona como uma câmera,e então você só torna o que está na câmera, que geralmente envolve tornar as coisas 
em relação à câmera ou apenas mostrando partes de objetos no interior da câmara.
    //Desde que o level não é mais do mesmo tamanho da tela, precisamos ter um set separado de constantes para definir o tamanho do level
    //As dimensões do level
    const int LEVEL_WIDTH = 1280; 
    const int LEVEL_HEIGHT = 960; 
    //As dimensões da tela 
    const int SCREEN_WIDTH = 640; 
    const int SCREEN_HEIGHT = 480;
    
    //Mostra o ponto relativo à camera 
    gDotTexture.render( mPosX - camX, mPosY - camY );
    
    //A área da câmera 
    SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
    
    //Centraliza a camera em cima do ponto 
    camera.x = ( dot.getPosX() + Dot::DOT_WIDTH / 2 ) - SCREEN_WIDTH / 2; 
    camera.y = ( dot.getPosY() + Dot::DOT_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;
    
#Scrolling fundos
Muitas vezes em jogos você pode querer um fundo infinito ou looping. Com rolagem fundos, você pode alternar um fundo que vai durar para sempre.
Tudo o que temos a fazer é tornar duas iterações do fundo ao lado do outro e movê-los um pouco a cada quadro. Quando o fundo chegar ao fim completamente, você pode 
redefinir o movimento:
    //Offset do fundo 
    int scrollingOffset = 0;
    
    //Scroll fundo.Atualizando a posição do fundo de rolagem está apenas diminuindo a posição x e se a posição x é menor do que a largura do fundo que significa que o 
    //fundo foi completamente fora da tela ea posição precisa ser reposto.
    --scrollingOffset; 
    if( scrollingOffset < -gBGTexture.getWidth() ) { 
      scrollingOffset = 0; 
    }

#Entrada de texto e manipular clipboard
Obtendo entrada de texto a partir do teclado é uma tarefa comum em jogos. Aqui nós vamos estar recebendo texto usando nova entrada de texto e manipulando clipboard do SDL2.
    //Seta texto como preto 
    SDL_Color textColor = { 0, 0, 0, 0xFF };
    
    //Permite entrada de texto 
    SDL_StartTextInput();

    //Manipula apagar
    if( e.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 ) { 
      //apaga último caractere
      inputText.pop_back(); 
      renderText = true; 
    }
    //Manipula copiar. GetModState() checa se control está sendo pressionado
    else if( e.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL ) { 
      SDL_SetClipboardText( inputText.c_str() ); //copia texto corrente para o clipboard 
    } //Manipula colar 
    else if( e.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL ) { 
      inputText = SDL_GetClipboardText(); //geta texto do clipboard
      renderText = true; 
    }
    
    //Evento de entrada de texto especial. Com entrada de texto ativada, suas entradas vão sempre gerar SDL_TextInputEvents qie simplificam coisas como shift e caps lock.
    else if( e.type == SDL_TEXTINPUT )
      
    //Retira entrada de texto 
    SDL_StopTextInput();
    
#Lendo e escrevendo em arquivos
Ser capaz de salvar e carregar dados é necessária para manter os dados entre sessões de jogo. SDL_RWops manipulação de arquivos nos permite fazer arquivo de plataforma 
cruzada IO para salvar os dados.   

    //Pontos de dados. Array de inteiros com sinal de 32 bits. Dados que estaremos carregando e salvando. Tamanho 10. 
    Sint32 gData[ TOTAL_DATA ];
    
    //Abre arquivo para leitura em binário
    SDL_RWops* file = SDL_RWFromFile( "33_file_reading_and_writing/nums.bin", "r+b" );
    
    //Cria arquivo pra escrita 
    file = SDL_RWFromFile( "33_file_reading_and_writing/nums.bin", "w+b" );
    
    //Inicializa dados 
    for( int i = 0; i < TOTAL_DATA; ++i ) {
      gData[ i ] = 0; 
      SDL_RWwrite( file, &gData[ i ], sizeof(Sint32), 1 ); //Escreve no arquivo de dados
    }

    //Fecha manipulador de arquivos 
    SDL_RWclose( file );
    
    //Carrega dados 
    for( int i = 0; i < TOTAL_DATA; ++i ) { 
      SDL_RWread( file, &gData[ i ], sizeof(Sint32), 1 ); //Lê dados do arquivo
    }
    
#Eventos de janelas
SDL também suporta janelas redimensionáveis. Quando você tem janelas redimensionáveis ​​há eventos adicionais para lidar com, que é o que vamos fazer aqui.

    LWindow::LWindow() { 
      //Inicializa janela não existente
      mWindow = NULL;
      mMouseFocus = false; 
      mKeyboardFocus = false; 
      mFullScreen = false;
      mMinimized = false; 
      mWidth = 0; 
      mHeight = 0; 
    }

    //Cria janela 
    mWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );
    
    //Evento da janela ocorreu 
    if( e.type == SDL_WINDOWEVENT )

    //Geta novas dimensões e repinta a mudança no tamanho da janela 
    case SDL_WINDOWEVENT_SIZE_CHANGED: 
	mWidth = e.window.data1; 
	mHeight = e.window.data2;
    //Repinta o exposto
    case SDL_WINDOWEVENT_EXPOSED:
	
    //Mouse entered window 
    case SDL_WINDOWEVENT_ENTER:
	mMouseFocus = true; 
	updateCaption = true;
	break; 
    //Mouse left window 
    case SDL_WINDOWEVENT_LEAVE: 
	mMouseFocus = false; 
	updateCaption = true; 
	break; 
    //Window has keyboard focus 
    case SDL_WINDOWEVENT_FOCUS_GAINED: 
	mKeyboardFocus = true; 
	updateCaption = true; 
	break;
    //Window lost keyboard focus 
    case SDL_WINDOWEVENT_FOCUS_LOST: 
	mKeyboardFocus = false;
	updateCaption = true;
	break;
    //Window minimized 
    case SDL_WINDOWEVENT_MINIMIZED: 
      mMinimized = true; 
      break; 
    //Window maxized 
    case SDL_WINDOWEVENT_MAXIMIZED:
      mMinimized = false; 
      break; 
    //Window restored 
    case SDL_WINDOWEVENT_RESTORED: 
      mMinimized = false;
      break;
      
    //Se a legenda precisa ser atualizado, nós carregamos um fluxo de string com os dados atualizados e atualizar a legenda com SDL_SetWindowTitle.
    SDL_SetWindowTitle( mWindow, caption.str().c_str() );
    
    //Seta janela FullScreen
    SDL_SetWindowFullscreen( mWindow, SDL_FALSE );
    
#Vários monitores
Outra nova característica pura com SDL 2 é a capacidade de lidar com múltiplos monitores. Aqui nós vamos fazer o nosso salto entre monitores.

    //Agarra identificadores das janelas
    mWindowID = SDL_GetWindowID( mWindow ); 
    mWindowDisplayID = SDL_GetWindowDisplayIndex( mWindow );
    
    // Se um evento foi detectada para esta janela
    if( e.type == SDL_WINDOWEVENT && e.window.windowID == mWindowID )
	case SDL_WINDOWEVENT_MOVED: mWindowDisplayID = SDL_GetWindowDisplayIndex( mWindow );
	//Janela apareceu 
	case SDL_WINDOWEVENT_SHOWN:
	//Janela desapareceu 
	case SDL_WINDOWEVENT_HIDDEN:
	    //...
    //Move janela p/ o centro do próximo monitor 
    SDL_SetWindowPosition( mWindow, gDisplayBounds[ mWindowDisplayID ].x + ( gDisplayBounds[ mWindowDisplayID ].w - mWidth ) / 2,
			   gDisplayBounds[ mWindowDisplayID ].y + ( gDisplayBounds[ mWindowDisplayID ].h - mHeight ) / 2 );
    //Seta filtragem de textura para linear 
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
    //Geta numero de monitores 
    gTotalDisplays = SDL_GetNumVideoDisplays();
    //Geta cantos de cada monitor 
    gDisplayBounds = new SDL_Rect[ gTotalDisplays ]; 
    for( int i = 0; i < gTotalDisplays; ++i )
      SDL_GetDisplayBounds( i, &gDisplayBounds[ i ] );
    
# Motores de partículas
As partículas são apenas mini-animações.
    //As partículas 
    Particle* particles[ TOTAL_PARTICLES ]; 
    
# Tiling
Tiling é uma maneira de fazer os níveis de partes reutilizáveis ​​de tamanho uniforme. Neste tutorial, vamos estar fazendo um nível de 1280x960 porte de fora apenas um conjunto 
de azulejos de tamanho 160x120.

# Manipulação de textura
Para fazer efeitos gráficos, muitas vezes requer acesso pixel. Neste tutorial vamos estar alterando pixels de uma imagem para o fundo branco.

    //Cria textura em branco streamable. Para nos permitir a capacidade de editar a textura, temos que carregar nossas texturas de forma diferente. Quando criamos texturas 
    //de superfícies antes, eles tinham o SDL_TextureAccess padrão de SDL_TEXTUREACCESS_STATIC, o que significa que não podemos mudá-lo depois que ele for criado. A fim de 
    //ser capaz de editar pixels da textura, temos de criar a textura com SDL_TEXTUREACCESS_STREAMING. 
    newTexture = SDL_CreateTexture( gRenderer, SDL_GetWindowPixelFormat( gWindow ), SDL_TEXTUREACCESS_STREAMING, formattedSurface->w, formattedSurface->h );
    //Bloqueia textura para manipulação
    SDL_LockTexture( newTexture, NULL, &mPixels, &mPitch );
    //Desbloqueia textura para atualizar 
    SDL_UnlockTexture( newTexture ); 
    mPixels = NULL;
    
#Fontes de bitmap
Algumas vezes fontes TTF são flexíveis o suficiente. Desde que renderização de texto é apenas renderização de imagens de caracteres, podemos usar fontes bitmap para processar 
texto. Fontes bitmap trabalham tomando uma folha de sprite de glifos (imagens de caracteres), tornando-os, a fim de formar strings na tela.
    
    //Converte surface para formato do monitor 
    SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat( loadedSurface, SDL_PIXELFORMAT_RGBA8888, NULL );
    //Permite mistura na textura
    SDL_SetTextureBlendMode( newTexture, SDL_BLENDMODE_BLEND );
    
#Transmissão de textura
Algum dia nós queremos tornar os dados de pixel de uma fonte que não seja um bitmap como uma webcam. Usando fluxo de textura podemos renderizar pixels de qualquer fonte.

#Renderização na textura
Por vários efeitos, é necessário poder renderizar uma cena para uma textura. Aqui estaremos renderizando uma cena para uma textura para dar efeito de rotação.

    bool LTexture::createBlank( int width, int height, SDL_TextureAccess access ) { 
      //Cria textura não-inicializada 
      mTexture = SDL_CreateTexture( gRenderer, SDL_PIXELFORMAT_RGBA8888, access, width, height );
    //Cria alvo de renderização 
    SDL_SetRenderTarget( gRenderer, mTexture );

#Movimento de frame independente
Se você quer ser capaz de lidar com taxas de quadros instáveis ​​ou suportar múltiplas taxas de quadros, você pode definir o seu movimento com base no tempo para torná-lo 
  independente da taxa de quadros.
  
#Retorno do tempo
Executa uma função depois de esperar determinado tempo.Neste tutorial vamos fazer um programa simples que imprime ao console após um tempo definido.

    //Nossa função callback. A função callback precisa ter um número inteiro de 32 bits como seu primeiro argumento, um ponteiro nulo como seu segundo argumento, e tem que 
    //retornar um inteiro de 32 bits.
    Uint32 callback( Uint32 interval, void* param );
      //Printa callback message 
      printf( "Callback called back with message: %s\n", (char*)param );
    //Certifique-se de inicializar com SDL_INIT_TIMER para poder usar o timer
    if (SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
    //Seta callback 
    SDL_TimerID timerID = SDL_AddTimer( 3 * 1000, callback, "3 seconds waited!" );
    //Remove timer no caso do callback não ter sido chamado 
    SDL_RemoveTimer( timerID );
    
#Multithreading
Multithreading pode ser usado para fazer seu programa executar duas coisas ao mesmo tempo e tirar proveito de arquiteturas multi-threaded. Aqui nós vamos fazer um programa 
simples que gera para o console, enquanto o thread na main é executado. Não mexa com isto se não sabe: 
    O que é cache de coerência
    O que é cache alinhado
    Como SOs manipulam threads e processos
    Como usar um profiler
    
    //Usando SDL Threads
    #include <SDL_thread.h>
    //Nossa função teste de thread. Devem ser declaradas assim como as funções de callback 
    int threadFunction( void* data ); 
      //Printa incoming data 
      printf( "Running thread with value = %d\n", (int)data );
    //Executa o thread 
    int data = 101; 
    SDL_Thread* threadID = SDL_CreateThread( threadFunction, "LazyThread", (void*)data );
    //Remove temporizador no caso do callback não ser chamado 
    SDL_WaitThread( threadID, NULL ); 
    //Antes de entrar na main, executamos a função thread usando SDL_CreateThread. Esta chamada executará a função em primeiro argumento, dar-lhe o nome no segundo argumento 
    //(os nomes são usados ​​para identificá-lo para fins de depuração), e passar os dados do terceiro argumento.
    //O segmento irá então executar enquanto a thread main ainda está indo. No caso de o main loop terminar antes do thread, fazemos uma chamada para SDL_WaitThread para 
    //garantir que o segmento termina antes de o aplicativo fechar.

#Semáforos
O único multithreading que fizemos tinha o thread main e um segundo thread cada um fazendo sua própria tarefa. Na maioria dos casos, dois threads terão que compartilhar dados 
e com semáforos você pode prevenir dois threads de acidentalmente acessarem a mesma parte de dados de uma só vez. 
    //Semáforo para acesso de dados. Ele vai bloquear nosso buffer gData. Mesmo que só um int, precisamos ter certeza que só será acessado por um por vez.
    SDL_sem* gDataLock = NULL; 
    //O "buffer de dados" 
    int gData = -1;
    //Inicializa semáforo. Parâmetro é o valor inicial do semáforo, que controla quantas vezes o código pode passar pelo semáforo antes de bloquear.
    //Por exemplo, suponha que só queira 4 threads para rodar ao mesmo tempo porque você tem um hardware com 4 cores. Você daria ao semáforo o valor 4 para começar para
    //ter certeza que não mais que 4 threads vão rodar ao mesmo tempo.
    gDataLock = SDL_CreateSemaphore( 1 );
    //Libera semáforo 
    SDL_DestroySemaphore( gDataLock );
    gDataLock = NULL;
    //Bloqueia 
    SDL_SemWait( gDataLock );
    //"Trabalha" 
    gData = rand() % 256;
    //Desbloqueia 
    SDL_SemPost( gDataLock );
    
#Operações atômicas
Semáforos operam a nível de sistema operacional. Operações atômicas são um modo de bloquear dado num nível eficiente de CPU. Aqui estaremos bloqueando uma seção crítica usando
GPU spinlocks (loops de bloqueio).

    //Acesso de dados do spin lock, em vez de semáforo. Ao contrário, não precisam ser alocados nem desalocados.Mas lembre-se que os semáforos pode permitir o acesso para
    //além de um único segmento. Operações atômicas são para quando você quer um rigoroso estado bloqueado / desbloqueado.
    SDL_SpinLock gDataLock = 0; 
    //O "buffer de dados" 
    int gData = -1;
    //Bloqueia 
    SDL_AtomicLock( &gDataLock );
    //"Trabalha" 
    gData = rand() % 256;
    //Desbloqueia 
    SDL_AtomicUnlock( &gDataLock );

#Mutuxes e condições
Não só podemos bloquear seções críticas em threads, mas com mutuxes e condições é possível aos threads dizer a cada um para desbloquear.

    //O mutex de proteção 
    SDL_mutex* gBufferLock = NULL;
    //As condições 
    SDL_cond* gCanProduce = NULL; 
    SDL_cond* gCanConsume = NULL; 
    //O "buffer de dados" 
    int gData = -1;
    //Cria o mutex 
    gBufferLock = SDL_CreateMutex();
    //Cria as condições 
    gCanProduce = SDL_CreateCond(); 
    gCanConsume = SDL_CreateCond();
    //Destroi o mutex 
    SDL_DestroyMutex( gBufferLock ); 
    gBufferLock = NULL;
    //Destroi condições 
    SDL_DestroyCond( gCanProduce ); 
    SDL_DestroyCond( gCanConsume ); 
    gCanProduce = NULL; gCanConsume = NULL;
    //Bloqueia 
    SDL_LockMutex( gBufferLock );
    //Espera buffer ser limpado/preenchido
    SDL_CondWait( gCanProduce, gBufferLock );
    //Desbloqueia 
    SDL_UnlockMutex( gBufferLock );
    //Consumidor/produtor do sinal 
    SDL_CondSignal( gCanConsume );
    
#SDL e OpenGL 2
Um dos recursos mais poderosos do SDL é a sua capacidade de se combinar com OpenGL. Aqui nós vamos fazer uma demonstração básica do OpenGL usando-o de forma mais fácil.

    //Usando SDL OpenGL
    #include <SDL_opengl.h> 
    #include <GL\GLU.h>
    //contexto OpenGL
    SDL_GLContext gContext;
    //Usa OpenGL 2.1 
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 ); 
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    //Cria janela (OpenGL) 
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
    //Cria contexto 
    gContext = SDL_GL_CreateContext( gWindow );
    //Usa Vsync 
    if( SDL_GL_SetSwapInterval( 1 ) < 0 )
    //Initializa OpenGL 
    if( !initGL() )
    //Sem erro no OpenGL
    GLenum error = GL_NO_ERROR;
    //Inicializa matriz de projeção.Primeiro, inicializar a matriz de projeção que controla a perspectiva de trabalho em OpenGL. Nós inicializar-lo aqui por defini-la como
    //a matriz de identidade. Em seguida, fazer a mesma coisa com a matriz modelview que controla como os objetos prestados são vistos e colocados.
    glMatrixMode( GL_PROJECTION ); 
    glLoadIdentity(); 
    //Checka por erro
    error = glGetError();
    //Inicializa matriz modelview 
    glMatrixMode( GL_MODELVIEW ); 
    glLoadIdentity();
    //Inicializa cor de limpeza 
    glClearColor( 0.f, 0.f, 0.f, 1.f );
    //Limpa buffer de cor
    glClear( GL_COLOR_BUFFER_BIT ); 
    //Renderiza quadrado 
    if( gRenderQuad ) { 
      glBegin( GL_QUADS ); 
      glVertex2f( -0.5f, -0.5f ); 
      glVertex2f( 0.5f, -0.5f ); 
      glVertex2f( 0.5f, 0.5f ); 
      glVertex2f( -0.5f, 0.5f ); 
      glEnd(); 
    }
    //Update a tela 
    SDL_GL_SwapWindow( gWindow );
    
#SDL e OpenGL moderno
Com OpenGL3 houve uma grande revisão que fez tudo o shader baseado. Neste tutorial vamos estar prestando um quad usando OpenGL core moderno.

    // Inclui SDL OpenGL, GLEW (OpenGL Extension Wrangler) 
    #include <gl\glew.h> 
    #include <SDL_opengl.h> 
    #include <gl\glu.h>
    //Usa OpenGL 3.1 core
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );
    //Initializa GLEW 
    glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    //Cria sombra do vértice 
    GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER ); 
    //Seta fonte do vértice
    glShaderSource( vertexShader, 1, vertexShaderSource, NULL );
    //Compila fonte do vértice 
    glCompileShader( vertexShader );
    //Checka sombra do vértice por erros
    GLint vShaderCompiled = GL_FALSE; glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
    //Anexar sombra do vértice para programa
    glAttachShader( gProgramID, vertexShader );
    //Linka programa
    glLinkProgram( gProgramID ); 
    //Geta localização da sombra do vértice 
    gVertexPos2DLocation = glGetAttribLocation( gProgramID, "LVertexPos2D" );
    //Cria VBO 
    glGenBuffers( 1, &gVBO ); 
    glBindBuffer( GL_ARRAY_BUFFER, gVBO ); 
    glBufferData( GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );
    //Cria IBO 
    glGenBuffers( 1, &gIBO ); 
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );
    //Geta info log 
    glGetProgramInfoLog( program, maxLength, &infoLogLength, infoLog );
    //Geta info log 
    glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
    //Bind program 
    glUseProgram( gProgramID ); 
    //Permite posição do vértice 
    glEnableVertexAttribArray( gVertexPos2DLocation );
    //Seta dados do vertice
    glBindBuffer( GL_ARRAY_BUFFER, gVBO ); 
    glVertexAttribPointer( gVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL ); 
    //Seta índice dos dados e renderiza
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO ); 
    glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL ); 
    //Desabilita posição do vértice 
    glDisableVertexAttribArray( gVertexPos2DLocation ); 
    //Unbind program 
    glUseProgram( NULL );