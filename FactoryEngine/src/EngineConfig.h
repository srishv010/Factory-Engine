#pragma once

#include <filesystem>
#include <windows.h>
#undef CreateWindow

#include "Core.h"
#include "Utilities.h"


namespace Factory {

	namespace FactoryEngine {

		struct FACTORY_API EngineConfig {
			std::string renderAPIName;
		};

        EngineConfig GetEngineConfig(const char* configFilePath) {
            std::filesystem::path configPath = configFilePath;
            configPath = std::filesystem::absolute(configPath);
            std::string configPathString = configPath.string();
            const char* configFileAbsolutePath = configPathString.c_str();
            EngineConfig config;
            char renderAPIName[256];

            // Default values
            config.renderAPIName = "notfound";

            // Read renderAPIName
            GetPrivateProfileString(
                "Settings",               // Section name
                "renderAPIName",          // Key name
                config.renderAPIName.c_str(), // Default value
                renderAPIName,            // Buffer to store result
                sizeof(renderAPIName),    // Size of the buffer
                configFileAbsolutePath            // Path to the INI file
            );
            config.renderAPIName = renderAPIName;

            return config;
        }

	}

}
