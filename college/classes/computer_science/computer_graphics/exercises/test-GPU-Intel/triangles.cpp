#include <stdio.h> //para abrir e manipular os arquivos
#include <iostream>

using namespace std;

#include <GL/glew.h>
#include <GL/freeglut.h>

typedef struct {
    GLenum       type;
    const char*  filename;
    GLuint       shader;
} ShaderInfo;

char* readShaderSource(const char* shaderFile) {
    FILE* fp = fopen(shaderFile, "r");

    if ( fp == NULL ) {  return NULL; }
 
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0L, SEEK_SET);
    char* buf = new char[size + 1];
    fread(buf, 1, size, fp);

    buf[size] = '\0';
    fclose(fp);

    return buf;
}




// Create a GLSL program object from vertex and fragment shader files
GLuint
InitShader(const char* vShaderFile, const char* fShaderFile) {
  struct Shader {
	const char*  filename;
	GLenum       type;
	GLchar*      source;
  }  shaders[2] = {
	{ vShaderFile, GL_VERTEX_SHADER, NULL },
	{ fShaderFile, GL_FRAGMENT_SHADER, NULL }
  };

  GLuint program = glCreateProgram();
    
  for ( int i = 0; i < 2; ++i ) {
    Shader& s = shaders[i];
    s.source = readShaderSource( s.filename );
    if ( shaders[i].source == NULL ) {
      std::cerr << "Failed to read " << s.filename << std::endl;
      exit( EXIT_FAILURE );
    }

    GLuint shader = glCreateShader( s.type );
    glShaderSource( shader, 1, (const GLchar**) &s.source, NULL );
    glCompileShader( shader );

    GLint  compiled;
    glGetShaderiv( shader, GL_COMPILE_STATUS, &compiled );
    if ( !compiled ) {
      std::cerr << s.filename << " failed to compile:" << std::endl;
      GLint  logSize;
      glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &logSize );
      char* logMsg = new char[logSize];
      glGetShaderInfoLog( shader, logSize, NULL, logMsg );
      std::cerr << logMsg << std::endl;
      delete [] logMsg;

      exit( EXIT_FAILURE );
    }

    delete [] s.source;

    glAttachShader( program, shader );
  }

  /* link  and error check */
  glLinkProgram(program);

  GLint  linked;
  glGetProgramiv( program, GL_LINK_STATUS, &linked );
  if ( !linked ) {
    std::cerr << "Shader program failed to link" << std::endl;
    GLint  logSize;
    glGetProgramiv( program, GL_INFO_LOG_LENGTH, &logSize);
    char* logMsg = new char[logSize];
    glGetProgramInfoLog( program, logSize, NULL, logMsg );
    std::cerr << logMsg << std::endl;
	delete [] logMsg;

	exit( EXIT_FAILURE );
  }

  /** use program object */
  glUseProgram(program);

  return program;
}



#define BUFFER_OFFSET(x)  ((const void*) (x))



enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };
enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

/*
  Rotina de Inicialização
*/

void init (void) {
  glClearColor(0, 0.5, 0, 0);

  glGenVertexArrays (NumVAOs, VAOs);
  glBindVertexArray (VAOs[Triangles]);

  GLfloat vertices[NumVertices][2] = {
    {-0.90, -0.90}, // Triangle 1
    { 0.85, -0.90},
    {-0.90,  0.85},
    { 0.90, -0.85}, // Triangle 2
    { 0.90,  0.90},
    {-0.85,  0.90}
  };

  glGenBuffers (NumBuffers, Buffers);
  glBindBuffer (GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
  glBufferData (GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


  GLuint program = InitShader( "triangles.vert", "triangles.frag");
  glUseProgram (program);

  glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  glEnableVertexAttribArray(vPosition);

}

/* Rotina associada ao display */

void display (void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBindVertexArray(VAOs[Triangles]);
  glDrawArrays(GL_TRIANGLES, 0, NumVertices);

  glutSwapBuffers();

}

/*  Programa Principal  */

int main (int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
  
  /*
  // Para rodar na minha controladora Intel não posso
  // usar "contextos" nem os "Profiles"
  // Nos shaders, eu tive que especificar a versão 130

  glutInitContextVersion(3, 3);
  glutInitContextProfile(GLUT_CORE_PROFILE);
  glutInitContextProfile(GLUT_FORWARD_COMPATIBLE);
  */

  glutInitWindowSize(800, 800);
  glutCreateWindow("Shader Based Triangles");

  GLenum err = glewInit();
 
  if ( GLEW_OK != err ) {
    cerr << "Erro: " << glewGetErrorString(err) << endl;
    exit(EXIT_FAILURE);
  }
  else {
    cout <<"\tUsando glew " << glewGetString(GLEW_VERSION)<<endl;
    cout <<"\tVendedor: " << glGetString(GL_VENDOR)<<endl;
    cout <<"\tRenderizador: " << glGetString(GL_RENDERER)<<endl;
    cout <<"\tVersao: " << glGetString(GL_VERSION)<<endl;
    cout <<"\tGLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION)<<endl;

  }
  

  init();

  glutDisplayFunc(display);

  glutMainLoop();

}


