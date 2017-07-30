#include "../../include/Angel.h"
#include <SOIL/SOIL.h>

GLint width  = 512;
GLint height = 512;

const int  NumVertices  = 4;

typedef Angel::vec4 point4;
typedef Angel::vec4 color4;
GLuint projLoc; 	//projeção perspectiva
mat4 Projection;

GLuint viewLoc; 	//câmera
mat4 View;
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

float ang_pos;
float raio;

// Texture object and storage for texture image
GLuint texture;

// Vertex data arrays
point4  points[NumVertices] = {
  point4( -2.0, -2.0, 0.0, 1.0 ),
  point4(  2.0, -2.0, 0.0, 1.0 ),
  point4(  2.0,  2.0, 0.0, 1.0 ),
  point4( -2.0,  2.0, 0.0, 1.0 )
  //point4( -2.0,  2.0, 4.0, 1.0 ),
  //point4( -2.0, -2.0, 4.0, 1.0 ),
  //point4(  2.0, -2.0, 0.0, 1.0 ),
  //point4(  2.0, -2.0, 0.0, 1.0 ),
  
};
				     
color4  colors[NumVertices] = {
  color4(0,1,0,1), color4(0,1,0,1),
  color4(0,1,1,1), color4(0,1,1,1)
};


vec2    tex_coords[NumVertices] = {
  vec2 (0.0, 0.0),   vec2 (1.0, 0.0), 
  vec2 (1.0, 1.0),   vec2 (0.0, 1.0)
};

GLfloat  angle = 0.0;
GLuint   theta;
//----------------------------------------------------------------------------



//----------------------------------------------------------------------------

void init() {
    // Initialize texture objects
    glGenTextures( 1, &texture );

    int width, height;
    unsigned char* image =
      SOIL_load_image("txStormydays_back.bmp", &width, &height, 0, SOIL_LOAD_RGB);

    glBindTexture( GL_TEXTURE_2D, texture );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		  GL_RGB, GL_UNSIGNED_BYTE, image );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    SOIL_free_image_data(image);
    glActiveTexture( GL_TEXTURE0 );
 
    // Create a vertex array object
    GLuint vao;
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object
    GLuint buffer;
    glGenBuffers( 1, &buffer );
    glBindBuffer( GL_ARRAY_BUFFER, buffer );
    glBufferData( GL_ARRAY_BUFFER,
		  sizeof(points) + sizeof(colors) + sizeof(tex_coords),
		  NULL, GL_STATIC_DRAW );

    // Specify an offset to keep track of where we're placing data in our
    //   vertex array buffer.  We'll use the same technique when we
    //   associate the offsets with vertex attribute pointers.
    GLintptr offset = 0;
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(points), points );
    offset += sizeof(points);

    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(colors), colors );
    offset += sizeof(colors);
    
    glBufferSubData( GL_ARRAY_BUFFER, offset, sizeof(tex_coords), tex_coords );

    // Load shaders and use the resulting shader program
    GLuint program = InitShader( "quad.vert", "quad.frag" );
    glUseProgram( program );

    // set up vertex arrays
    offset = 0;
    GLuint vPosition = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( vPosition );
    glVertexAttribPointer( vPosition, 4, GL_FLOAT, GL_FALSE, 0,
			   BUFFER_OFFSET(offset) );
    offset += sizeof(points);

    GLuint vColor = glGetAttribLocation( program, "vColor" ); 
    glEnableVertexAttribArray( vColor );
    glVertexAttribPointer( vColor, 4, GL_FLOAT, GL_FALSE, 0,
			   BUFFER_OFFSET(offset) );
    offset += sizeof(colors);

    GLuint vTexCoord = glGetAttribLocation( program, "vTexCoord" );
    glEnableVertexAttribArray( vTexCoord );
    glVertexAttribPointer( vTexCoord, 2, GL_FLOAT, GL_FALSE, 0,
			   BUFFER_OFFSET(offset) );

    // Set the value of the fragment shader texture sampler variable
    //   ("texture") to the the appropriate texture unit. In this case,
    //   zero, for GL_TEXTURE0 which was previously set by calling
    //   glActiveTexture().
    glUniform1i( glGetUniformLocation(program, "texture"), 0 );

    theta = glGetUniformLocation( program, "theta" );

    Projection = glGetUniformLocation( program, "Projection" );
    
   projLoc  = glGetUniformLocation( program, "projection" );		//projeção
    
    viewLoc  = glGetUniformLocation( program, "view" );			//câmera

    glEnable( GL_DEPTH_TEST );
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_FRONT);

    glClearColor( .0, .0, .0, 1.0 );
}


//----------------------------------------------------------------------------

void display( void ) {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glUniform1f( theta, angle );

    glDrawArrays( GL_TRIANGLE_FAN, 0, NumVertices );
    
      
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


//----------------------------------------------------------------------------

void idle( void ) {
    angle += 0.1;

    if ( angle > 360.0 ) angle -= 360.0;
    
    glutPostRedisplay();
}

//----------------------------------------------------------------------------


void reshape( int w, int h ) {
  width = w;
  height = h;
  glViewport( 0, 0, width, height );

    GLfloat left = -2.0, right = 2.0;
    GLfloat top = 2.0, bottom = -2.0;
    GLfloat zNear = -20.0, zFar = 20.0;

    GLfloat aspect = GLfloat(width)/GLfloat(height);

    if ( aspect > 1.0 ) {
	left *= aspect;
	right *= aspect;
    }
    else {
	top /= aspect;
	bottom /= aspect;
    }

   // mat4 projection = Ortho( left, right, bottom, top, zNear, zFar );
   // glUniformMatrix4fv( Projection, 1, GL_TRUE, projection );

}
//----------------------------------------------------------------------------

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

  if (key == 27) exit(0);
}
  
void myKeyDir(int key, int x, int y){
  if(key==GLUT_KEY_UP)	eyey += 0.02;
  if(key==GLUT_KEY_DOWN)eyey -= 0.02; 
}



int main( int argc, char **argv ) {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( width, height );
    //glutInitContextVersion( 3, 2 );
    //glutInitContextProfile( GLUT_CORE_PROFILE );
    glutCreateWindow( "Outback" );

    glewInit();

    init();

    glutDisplayFunc( display );
    glutReshapeFunc( reshape );
    glutIdleFunc( idle );
      glutKeyboardFunc(myKey);
  glutSpecialFunc(myKeyDir);

    glutMainLoop();
    return 0;
}
