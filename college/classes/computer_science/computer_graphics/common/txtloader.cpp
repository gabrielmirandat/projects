#include "../include/txtloader.hpp"

void loadTXT(
	const char * path, 
	GLuint texture_obj,
	GLint width,
	GLint height)
{
    // Initialize texture_aviao objects
    glGenTextures( 1, &texture_obj );

    unsigned char* image =
      SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);

    glBindTexture( GL_TEXTURE_2D, texture_obj );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
		  GL_RGB, GL_UNSIGNED_BYTE, image );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );

    SOIL_free_image_data(image);
}