#version 130

in  vec3 vPosition;
in  vec4 vColor;
out vec4 color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform float theta;

void main( void ) {
   float angle = radians( theta );
   float c = cos( angle );
   float s = sin( angle );
   
   mat4 ry = mat4( c,   0.0,  s,   0.0,
                   0.0, 1.0,  0.0, 0.0, 
                  -s,   0.0,  c,   0.0,
                   0.0, 0.0,  0.0, 1.0 );

   gl_Position = projection * view * model * ry * vec4(vPosition, 1.0); 

   color = vColor;/* sin( angle );*/
}