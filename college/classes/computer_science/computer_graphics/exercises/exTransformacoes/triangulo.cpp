#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "../../include/Angel.h"

typedef Angel::vec4 point4;
//typedef Angel::vec4 color4;

void mydisplay( void );
void init( void );
void idle( void);


point4 points[12] = {
  point4( -0.25, -0.25, 0.0, 1.0 ),
  point4(  0.25, -0.25, 0.1, 1.0 ),
  point4(   0.0,  0.25, 0.0, 1.0 ),
  
  point4( -0.25, -0.25, 0.0, 1.0 ),
  point4(   0.0,  0.25, 0.0, 1.0 ),
  point4(  0.13,   0.0, -0.1, 1.0),

  point4(  0.13,   0.0, -0.1, 1.0),
  point4(   0.0,  0.25, 0.0, 1.0 ),
  point4(  0.25, -0.25, 0.1, 1.0 ),
  
  point4(  0.13,   0.0, -0.1, 1.0),
  point4( -0.25, -0.25, 0.0, 1.0 ),
  point4(  0.25, -0.25, 0.1, 1.0 )
  
};

point4 colors[12] = {
  point4( 0.0, 0.0, 1.0, 1.0 ),
  point4( 1.0, 0.0, 0.0, 1.0 ),
  point4( 0.0 ,1.0, 0.0, 1.0 ),
  
  point4( 0.0, 0.0, 1.0, 1.0 ),
  point4( 0.0 ,1.0, 0.0, 1.0 ),
  point4( 1.0 ,1.0, 0.0, 1.0 ),

  point4( 1.0 ,1.0, 0.0, 1.0 ),
  point4( 0.0 ,1.0, 0.0, 1.0 ),
  point4( 1.0, 0.0, 0.0, 1.0 ),
  
  point4( 1.0 ,1.0, 0.0, 1.0 ),
  point4( 0.0, 0.0, 1.0, 1.0 ),
  point4( 1.0, 0.0, 0.0, 1.0 )

  
};



GLfloat angulo = 0.0;
GLuint theta; // The location of the "theta" shader uniform variable


int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
  glutInitWindowSize( 800, 800 );
  glutCreateWindow( "Triangulo" );

  glutDisplayFunc( mydisplay );
  glutIdleFunc( idle );

  glewInit();

  init();

  glutMainLoop();

}


void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT );

  glUniform1f( theta, angulo);

  glDrawArrays( GL_TRIANGLES, 0, 12);

  glFlush();
}


void idle ( void ) {
  angulo += 0.15;

  glutPostRedisplay();
}



void init( void ) {

  //srand(time(NULL));

  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "tri.vert", "tri.frag" );
  glUseProgram( program );

  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );

  // Create and initalize a buffer object
  GLuint buffer;
  glGenBuffers( 1, &buffer );
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof(points) + sizeof(colors), 
                NULL, GL_STATIC_DRAW );
  glBufferSubData( GL_ARRAY_BUFFER, 0, sizeof(points), points);
  glBufferSubData( GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);

  // set up vertex arrays
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( vPosition );
  glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );

  GLuint vColor = glGetAttribLocation( program, "vColor" );
  glEnableVertexAttribArray( vColor );
  glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			 BUFFER_OFFSET(sizeof(points)) );

  theta = glGetUniformLocation( program, "theta" );

  glClearColor( 1.0, 1.0, 1.0, 1.0 );
}
