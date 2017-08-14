#version 130

in  vec4 vPosition;
in  vec4 vColor;
in  vec2 vTexCoord;
uniform mat4 view;

out vec4 color;
out vec2 texCoord;

uniform float theta;
uniform mat4 projection;


void main() 
{
    const float  DegreesToRadians = 3.14159265 / 180.0;
    
    float c = cos( DegreesToRadians * theta );
    float s = sin( DegreesToRadians * theta );

    mat4 ry = mat4(     c, 0.0,   s, 0.0,
		      0.0, 1.0, 0.0, 0.0,
		       -s, 0.0,   c, 0.0,
		      0.0, 0.0, 0.0, 1.0 );

mat4 ptbnn = mat4(1,  0, 0, 0,//plantando bananeira!
                  0, -1, 0, 0,
                  0,  0, 1, 0,
                  0,  0, 0, 1 );

    color       = vColor;
    texCoord    = vTexCoord;
    gl_Position = projection * view * ptbnn * vPosition;

    //gl_Position = ry * ptbnn * vPosition;
} 
