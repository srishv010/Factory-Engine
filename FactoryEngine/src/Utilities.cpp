#include "Utilities.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>

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

	}

}
