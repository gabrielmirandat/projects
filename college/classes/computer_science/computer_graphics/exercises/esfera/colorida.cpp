#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math.h>
#include "../../include/Angel.h"

typedef Angel::vec3 point3;
typedef Angel::vec4 color4;

/*
void mydisplay( void );
void init( void );
void idle( void );
*/

GLuint modelLoc; 
mat4 Model;
GLuint viewLoc; 
mat4 View;
GLuint projLoc; 
mat4 Projection;

GLfloat angulo = 0;
GLuint theta;

const GLuint slices = 50;	//fatias
const GLuint stacks = 50;	//pilhas
const int NumVertices = 2 * (slices + 1) * stacks;

point3 points[NumVertices];
vec4 colors[NumVertices];

int screen_width  = 800; 
int screen_height = 800;



GLuint sphere(float radius, int slices, int stacks) {
  GLuint vbo;
  int n = 2 * (slices + 1) * stacks;
  int i = 0, j = 0;

  
  for (float theta = -M_PI / 2; theta < M_PI / 2 - 0.0001; theta += M_PI / stacks) {
    for (float phi = -M_PI; phi <= M_PI + 0.0001; phi += 2 * M_PI / slices) {

      /*switch (j++ % 10) {
      case 0: case 5: case 7: colors[i] = vec4(0,1,0,1);
      break;
      case 1: case 3: colors[i] = vec4(0,0,1,1);
	break;
      case 2: case 8: case 6: case 4: colors[i] = vec4(1,0,0,1);
	break;
      }*/
      
      points[i++] = point3(cos(theta) * sin(phi), -sin(theta), cos(theta) * cos(phi));
      points[i++] = point3(cos(theta + M_PI / stacks) * sin(phi), -sin(theta + M_PI / stacks), cos(theta + M_PI / stacks) * cos(phi));
    }
  }
  
  //GLfloat aux = 0;
  for(i=0;i<NumVertices;i++){
    //aux += 5;
    colors[i] = vec4(1.0,1.0,1.0,1.0);
  }
  
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(points)+sizeof(colors), NULL, GL_STATIC_DRAW);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(points), points);
  glBufferSubData(GL_ARRAY_BUFFER, sizeof(points), sizeof(colors), colors);
  
  return vbo;
}



void myReshape(int width, int height) {
  screen_width = width;
  screen_height = height;
  glViewport(0, 0, screen_width, screen_height);
}


void idle ( void ) {
  angulo += .5;

  glutPostRedisplay();
}


void mydisplay( void ) {
  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glUniform1f( theta, angulo);

  Model = Translate(0, 0, -2);
  glUniformMatrix4fv(modelLoc, 1, GL_TRUE, Model);
  vec4 eye = vec4(0, -2,  0, 1);
  vec4 at  = vec4(0, 0, -2, 1);
  vec4 up  = vec4(0, 1,  0, 0);

  View = LookAt(eye, at, up);
  glUniformMatrix4fv(viewLoc, 1, GL_TRUE, View);

  Projection = Perspective(60.0f, 1.0f*screen_width/screen_height, 0.1f, 10.0f);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, Projection);



  glDrawArrays( GL_TRIANGLE_STRIP, 0, NumVertices);



  glutSwapBuffers();
}




void init( void ) {
  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "colorida.vert", "colorida.frag" );
  glUseProgram( program );

  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );


  GLuint sphereVBO = sphere(1, slices, stacks);
  glBindBuffer(GL_ARRAY_BUFFER, sphereVBO);


  // set up vertex arrays
  GLuint vPosition = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( vPosition );
  glVertexAttribPointer( vPosition, 3, GL_FLOAT, GL_FALSE, 0, 
          BUFFER_OFFSET(0) );

  GLuint vColor = glGetAttribLocation( program, "vColor" );
  glEnableVertexAttribArray( vColor );
  glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			 BUFFER_OFFSET(sizeof(points)) );
  

  modelLoc = glGetUniformLocation( program, "model" );
  viewLoc  = glGetUniformLocation( program, "view" );
  projLoc  = glGetUniformLocation( program, "projection" );
 

  theta = glGetUniformLocation( program, "theta" ); 
 

  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);

  glClearColor( .9, .9, .9, 1.0 );
}


int main (int argc, char** argv) {
  glutInit( &argc, argv);
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize( screen_height, screen_width);
  glutCreateWindow( "Esfera" );

  glutDisplayFunc( mydisplay );
  glutIdleFunc( idle );
  glutReshapeFunc( myReshape );
 

  glewInit();

  init();

  glutMainLoop();

}


