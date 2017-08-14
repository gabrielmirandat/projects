#version 130

in  vec4 vPosition;
//in vec4 vColor;
out vec4 SColor;
uniform mat4 gWorld;

uniform float theta;

void main( void ) {

   // Computa o seno e cosseno de theta
 
   float angle = radians( theta );
   float c = cos( angle );
   float s = sin( angle );


   //--------------------------------------------------------------
   // Matrizes de transformações
   mat4 tr1 = mat4(1.0,	  0.0,	0.0,	0.0,
                  0.0,	  1.0,	0.0,	0.0, 
                  0.0,	  0.0,	1.0,	0.0,
                  0.1,	  0.1,	0.0,	1.0);
   
   mat4 tr2 = mat4(1.0,	  0.0,	0.0,	0.0,
                  0.0,	  1.0,	0.0,	0.0, 
                  0.0,	  0.0,	1.0,	0.0,
                -0.60,  -0.60,	0.0,	1.0);
   
   
   mat4 rx = mat4(1.0,	0.0,	0.0,  	0.0,
                  0.0,    c,     -s,    0.0, 
		  0.0,	  s,	  c,    0.0,
		  0.0,	  0.0,	0.0,   1.0);
                
  mat4 ry = mat4(  c,	0.0,	  s,  	0.0,
                 0.0,   1.0,  	0.0,    0.0, 
		  -s,	0.0,	  c,    0.0,
		  0.0,	  0.0,	0.0,   1.0);
  
  mat4 rz = mat4(  c,	   -s,	0.0,  	0.0,
                    s,      c,  0.0,    0.0, 
		  0.0,	  0.0,	1.0,    0.0,
		  0.0,	  0.0,	0.0,   1.0);
   


   gl_Position = gWorld * vPosition;

   SColor = clamp(vPosition, 0.0, 1.0);

}