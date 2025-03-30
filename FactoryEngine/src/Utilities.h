#pragma once

#include <string>

#include "Core.h"

namespace Factory {

	namespace Utilities {

		FACTORY_API std::string ReadFile(std::string path);

		FACTORY_API unsigned char* ReadImage(const char* path, int* width, int* height, int* colorChannels);

	}

}
