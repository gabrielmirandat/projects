#include <GL/glew.h>
#include <GL/freeglut.h>
#include "../../include/Angel.h"

// Recursive subdivision of triangle to form Sierpinski gasket
using namespace Angel;

typedef vec4 point4;
const int NumTimesToSubdivide = 5;
const int NumTriangles = 729;
// 3^5 triangles generated
const int NumVertices = 3 * NumTriangles;
vec2 points[NumVertices];
int Index = 0;

void triangle( const vec2& a, const vec2& b, const vec2& c ) {
  points[Index++] = a;
  points[Index++] = b;
  points[Index++] = c;
}

void divide_triangle( const vec2& a, const vec2& b,
  const vec2& c, int count ) {
  if ( count > 0 ) {
    //compute midpoints of sides
    vec2 v0 = ( a + b ) / 2.0;
    vec2 v1 = ( a + c ) / 2.0;
    vec2 v2 = ( b + c ) / 2.0;
    //subdivide all but middle triangle
    divide_triangle( a, v0, v1, count - 1 );
    divide_triangle( c, v1, v2, count - 1 );
    divide_triangle( b, v2, v0, count - 1 );
  }else {
    triangle( a, b, c );
    // draw triangle at end of recursion
  }
}

void display( void ) {
  glClear( GL_COLOR_BUFFER_BIT );
  glDrawArrays( GL_TRIANGLES, 0, NumTriangles );
  glFlush( );
}

void init( void ) {
  vec2 vertices[3] = { vec2( -1.0, -1.0 ),
  vec2( 0.0, 1.0 ),
  vec2( 1.0, -1.0 ) };
  // Subdivide the original triangle
  divide_triangle( vertices[0], vertices[1], vertices[2],
  NumTimesToSubdivide );
  // Load shaders and use the resulting shader program
  GLuint program = InitShader( "shader.vert", "shader.frag" );
  glUseProgram( program );
  // Create a vertex array object
  GLuint vao;
  glGenVertexArrays( 1, &vao );
  glBindVertexArray( vao );
  // Create and initialize a buffer object
  GLuint buffer;
  glGenBuffers( 1, &buffer );
  glBindBuffer( GL_ARRAY_BUFFER, buffer );
  glBufferData( GL_ARRAY_BUFFER, sizeof(points), points,
  GL_STATIC_DRAW );
  // Initialize the vertex position attribute from the vertex shader
  GLuint loc = glGetAttribLocation( program, "vPosition" );
  glEnableVertexAttribArray( loc );
  glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0,
  BUFFER_OFFSET(0) );
  glClearColor( 1.0, 1.0, 1.0, 1.0 );
  // white background
}

int main( int argc, char **argv ) {
  glutInit( &argc, argv );
  glutInitDisplayMode( GLUT_RGBA );
  glutInitWindowSize( 1024, 1024 );
  glutCreateWindow( "Sierpinski Gasket 2D" );
  glewInit( );
  init( );
  glutDisplayFunc( display );
  glutMainLoop( );
}