#version 130

in vec3 vPosition;
in vec3 vNormals;
in vec2 vTextures;

// Output data ; will be interpolated for each fragment.
varying vec2 UV;
varying vec3 Position_worldspace;
varying vec3 Normal_cameraspace;
varying vec3 EyeDirection_cameraspace;
varying vec3 LightDirection_cameraspace;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform vec3 LightPosition_worldspace;

void main( void ) {


  gl_Position = projection * view * model * vec4(vPosition,1.0);
   
   
  // Position of the vertex, in worldspace : M * position
  Position_worldspace = (model * vec4(vPosition,1)).xyz;
	
  // Vector that goes from the vertex to the camera, in camera space.
  // In camera space, the camera is at the origin (0,0,0).
  vec3 vertexPosition_cameraspace = ( view * model * vec4(vPosition,1)).xyz;
  EyeDirection_cameraspace = vec3(0,0,0) - vertexPosition_cameraspace;

  // Vector that goes from the vertex to the light, in camera space. M is ommited because it's identity.
  vec3 LightPosition_cameraspace = ( view * vec4(LightPosition_worldspace,1)).xyz;
  LightDirection_cameraspace = LightPosition_cameraspace + EyeDirection_cameraspace;
	
  // Normal of the the vertex, in camera space
  Normal_cameraspace = ( view * model * vec4(vNormals,0)).xyz; // Only correct if ModelMatrix does not scale the model ! Use its inverse transpose if not.
	
  // UV of the vertex. No special space for this one.
  UV = vTextures;

}