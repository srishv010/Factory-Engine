#include "Utilities.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace Factory {

	namespace Utilities {

		std::string ReadFile(std::string path) {
			std::string text;
			std::ifstream file;

			file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
			try {
				file.open(path);
				std::stringstream stream;

				stream << file.rdbuf();

				file.close();

				text = stream.str();
			}
			catch (std::ifstream::failure e) {
				std::cout << "ERROR::FILE_NOT_SUCCESFULLY_READ" << std::endl;
			}

			return text;
		}

		unsigned char* ReadImage(const char* path, int* width, int* height, int* colorChannels) {
			stbi_set_flip_vertically_on_load(true);
			unsigned char* data = stbi_load(path, width, height, colorChannels, 0);
			if (!data)
				std::cout << "Failed to load image: " << path << std::endl;
			return data;
		}

	}

}
