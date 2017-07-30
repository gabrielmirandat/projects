#include <GL/glew.h>
#include <math.h>
#include "../include/Angel.h"
#include "../include/objloader.hpp"
#include "../include/txtloader.hpp"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

typedef Angel::vec4 point4;

std::vector<glm::vec3> vertices;
std::vector<glm::vec2> uvs;
std::vector<glm::vec3> normals;
glm::vec3 lightPos = glm::vec3(4,4,4);	//posição da luz

GLint width  = 1000;
GLint height = 800;
float incr = -0.45;
std::vector<int> vetor_angulos;

GLuint modelLoc; 	//objeto
mat4 Model;
GLuint projLoc; 	//projeção perspectiva
mat4 Projection;
GLuint viewLoc; 	//câmera
mat4 View;
GLuint LightID;		//luz


//-- camera
vec4 eye;	//ponto
vec4 at;	//ponto
vec4 up;	//vetor
float eyex = 0.5;
float eyey = 0.0;
float eyez =-2.0;
float atx = 0.0;
float aty = 0.0;
float atz = 0.0;
float upx = 0.0;
float upy = 1.0;
float upz = 0.0;

GLfloat angulo = 0;
float ang_pos;
bool movendo = true;
float raio;
GLuint theta; // The location of the "theta" shader uniform variable

// Texture object and storage for texture_aviao image
GLuint texture_aviao;

//The music that will be played
Mix_Music *music = NULL;

void mydisplay( void );
void init( void );
void objeto(void );
void idle( void );
void myReshape(int ,int );
void myKey(unsigned char, int, int);
void myKeyDir(int, int, int);

int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
  glutInitWindowSize( width, height );
  glutCreateWindow( "Redemoinho" );
  
  objeto(); 
  
  glutDisplayFunc( mydisplay );
  glutIdleFunc( idle );
  glutReshapeFunc( myReshape );
  glutKeyboardFunc(myKey);
  glutSpecialFunc(myKeyDir);

  glewInit();
  
  // Inicia SDL e SDL_mixer
  SDL_Init(SDL_INIT_AUDIO);
  Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 );

  init();

  glutMainLoop();
  
  //Free the music
  Mix_FreeMusic( music );
  //Quit SDL_mixer
  Mix_CloseAudio();
  //Quit SDL
  SDL_Quit();
}

void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  for(int i = 0; i <= 19; i++){
    Model = RotateY(vetor_angulos[i]*(-angulo)) * Translate(0.53,incr,0.0) * Scale(0.0003,0.0003,0.0003);
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    Model = RotateY(vetor_angulos[i+20]*(-angulo)) *Translate(0.15,incr + 0.01,0.0) * Scale(0.0003,0.0003,0.0003);
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    Model = RotateY(vetor_angulos[i+40]*(-angulo)) *Translate(0.7,incr + 0.02,0.0) * Scale(0.0003,0.0003,0.0003);
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    Model = RotateY(vetor_angulos[i+60]*(-angulo)) *Translate(0.33,incr + 0.03,0.0) * Scale(0.0003,0.0003,0.0003);
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    Model = RotateY(vetor_angulos[i+80]*(-angulo)) *Translate(0.6,incr + 0.04,0.0) * Scale(0.0003,0.0003,0.0003);
    glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
    glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
    
    incr = incr + 0.05;
    glUniform1f( theta, angulo);
  }
  incr = -0.45;
  
  //-- camera
  eye = vec4(eyex,eyey,eyez, 1);	//ponto
  at  = vec4( atx, aty, atz, 1);	//ponto
  up  = vec4( upx, upy, upz, 0);	//vetor

  View = LookAt(eye, at, up);
  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);

  //-- projecao
  Projection = Perspective(60.0f, 1.0f*width/height, 0.1f, 10.0f);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projection);
  
  glutSwapBuffers();
}

void objeto(void ){
  
  // Read our .obj file
  bool res = loadOBJ("../content/objects/aviao3.obj", vertices, uvs, normals);
}

void myReshape(int screen_width, int screen_height) {
   width  = screen_width;
   height = screen_height;
   glViewport(0, 0, width, height);
}


void idle ( void ) {
  if(movendo==true) angulo += .10;

  glutPostRedisplay();
}

void myKey(unsigned char key, int x, int y){
  ang_pos = atan2(abs(eyez),abs(eyex));
  raio = sqrt(eyez*eyez + eyex*eyex); 
  
  if(raio >= 0.03){
    if(key=='w' || key == 'W'){
      if(eyex>0 && eyez<0){	//1 quadrante
	eyex = eyex - 0.02*(cos(ang_pos));
	eyez = eyez + 0.02*(sin(ang_pos));
      }
      if(eyex<0 && eyez<0){	//2 quadrante
	eyex = eyex + 0.02*(cos(ang_pos));
	eyez = eyez + 0.02*(sin(ang_pos));
      }
      if(eyex<0 && eyez>0){	//3 quadrante
	eyex = eyex + 0.02*(cos(ang_pos));
	eyez = eyez - 0.02*(sin(ang_pos));
      }
      if(eyex>0 && eyez>0){	//4 quadrante
	eyex = eyex - 0.02*(cos(ang_pos));
	eyez = eyez - 0.02*(sin(ang_pos));
      }
    
      //Mix_VolumeMusic(int volume);
    }
    
    if(key=='s' || key == 'S'){
      if(eyex>0 && eyez<0){	//1 quadrante
	eyex = eyex + 0.02*(cos(ang_pos));
	eyez = eyez - 0.02*(sin(ang_pos));
      }
      if(eyex<0 && eyez<0){	//2 quadrante
	eyex = eyex - 0.02*(cos(ang_pos));
	eyez = eyez - 0.02*(sin(ang_pos));
      }
      if(eyex<0 && eyez>0){	//3 quadrante
	eyex = eyex - 0.02*(cos(ang_pos));
	eyez = eyez + 0.02*(sin(ang_pos));
      }
      if(eyex>0 && eyez>0){	//4 quadrante
	eyex = eyex + 0.02*(cos(ang_pos));
	eyez = eyez + 0.02*(sin(ang_pos));
      }
      
      //Mix_VolumeMusic(int volume);
    }
  }
  
  if(key=='a' || key == 'A'){
    if(eyex>0 && eyez<0){	//1 quadrante
      eyex = eyex + 0.02;
      eyez = eyez + 0.02;
    }
    if(eyex<0 && eyez<0){	//2 quadrante
      eyex = eyex + 0.02;
      eyez = eyez - 0.02;
    }
    if(eyex<0 && eyez>0){	//3 quadrante
      eyex = eyex - 0.02;
      eyez = eyez - 0.02;
    }
    if(eyex>0 && eyez>0){	//4 quadrante
      eyex = eyex - 0.02;
      eyez = eyez + 0.02;
    }
  }
  
  if(key=='d' || key == 'D'){
    if(eyex>0 && eyez<0){	//1 quadrante
      eyex = eyex - 0.02;
      eyez = eyez - 0.02;
    }
    if(eyex<0 && eyez<0){	//2 quadrante
      eyex = eyex - 0.02;
      eyez = eyez + 0.02;
    }
    if(eyex<0 && eyez>0){	//3 quadrante
      eyex = eyex + 0.02;
      eyez = eyez + 0.02;
    }
    if(eyex>0 && eyez>0){	//4 quadrante
      eyex = eyex + 0.02;	
      eyez = eyez - 0.02;
    }
  }  
  
  if(key==13){
    movendo = (movendo == true? false:true );
    //If the music is paused
    if( Mix_PausedMusic() == 1 ){
       //Resume the music
       Mix_ResumeMusic();
    }else{
       //Pause the music
       Mix_PauseMusic();
    }
    
  }
  if (key == 27) exit(0);
}
  
void myKeyDir(int key, int x, int y){
  if(key==GLUT_KEY_UP)	eyey += 0.02;
  if(key==GLUT_KEY_DOWN)eyey -= 0.02; 
}

void init( void ) {
  srand(time(NULL));
  //-- inicializa vetor_angulos
  for (int i =0; i < 100; i++){
    int b = rand() % 70 + 1;
    vetor_angulos.push_back(b);
  }

  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "shd.vert", "shd.frag" );
  glUseProgram( program );

  loadTXT("../content/textures/newspaper_texture2811.jpg", texture_aviao, width, height);
  
  glActiveTexture( GL_TEXTURE0 );
  
  //Load the music
  music = Mix_LoadMUS( "../content/sounds/wind2.wav" );
  Mix_PlayMusic( music, -1 );
  
  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  // Load it into a VBO
  GLuint vertexbuffer;
  glGenBuffers(1, &vertexbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

  GLuint uvbuffer;
  glGenBuffers(1, &uvbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
  
  GLuint normalbuffer;
  glGenBuffers(1, &normalbuffer);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

  
  // 1rst attribute buffer : vertices
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray(vPosition);
  glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  glVertexAttribPointer(
			vPosition,           // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			BUFFER_OFFSET(0)          // array buffer offset
  );

  // 2nd attribute buffer : UVs
  GLuint vTextures = glGetAttribLocation( program, "vTextures" );
  glEnableVertexAttribArray(vTextures);
  glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
  glVertexAttribPointer(
			vTextures,                        // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			BUFFER_OFFSET(0)                  // array buffer offset
  );

  // 3rd attribute buffer : normals
  GLuint vNormals = glGetAttribLocation( program, "vNormals" );
  glEnableVertexAttribArray(vNormals);
  glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
  glVertexAttribPointer(
			vNormals,    // The attribute we want to configure
			3,                            // size
			GL_FLOAT,                     // type
			GL_FALSE,                     // normalized?
			0,                            // stride
			BUFFER_OFFSET(0)                      // array buffer offset
  );
  
  modelLoc = glGetUniformLocation( program, "model" );			//objeto
  projLoc  = glGetUniformLocation( program, "projection" );		//projeção
  viewLoc  = glGetUniformLocation( program, "view" );			//câmera
  theta = glGetUniformLocation( program, "theta" );			//ângulo
  LightID = glGetUniformLocation(program, "LightPosition_worldspace");
  
  // Set the value of the fragment shader texture sampler variable
  //   ("texture") to the the appropriate texture unit. In this case,
  //   zero, for GL_TEXTURE0 which was previously set by calling
  //   glActiveTexture().
  glUniform1i( glGetUniformLocation(program, "textura_aviao"), 0 );	//textura do avião
  glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);		//luz

  glEnable(GL_DEPTH_TEST);
  // Cull triangles which normal is not towards the camera
  //glEnable(GL_CULL_FACE);
  // Accept fragment if it closer to the camera than the former one
  glDepthFunc(GL_LESS); 

  glClearColor( 0.0, 0.2, 1.0, 1.0 );
  
}