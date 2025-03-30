#include "Texture.h"

#include <glad/glad.h>


namespace GLRenderAPI {

	GLTexture::GLTexture(unsigned char* data, int width, int height, int colorChannels)
		: width(width),
		height(height),
		colorChannels(colorChannels) {
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		GLenum format = GL_RGB;
		switch (colorChannels) {
		case 1:
			format = GL_RED;
			break;
		case 3:
			format = GL_RGB;
			break;
		case 4:
			format = GL_RGBA;
			break;
		}

		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		GLenum err;
		while ((err = glGetError()) != GL_NO_ERROR) {
			std::cerr << "OpenGL Error: " << err << std::endl;
		}

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	GLTexture::~GLTexture() {
		glDeleteTextures(1, &id);
	}

	void GLTexture::Bind(int unit) {
		//glActiveTexture(GL_TEXTURE0 + unit);
		currentUnit = unit;
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void GLTexture::Unbind() {
		//glActiveTexture(GL_TEXTURE0 + currentUnit);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
