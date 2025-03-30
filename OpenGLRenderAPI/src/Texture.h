#pragma once

#include "IRenderAPI.h"


using namespace RenderAPIInterface;

namespace GLRenderAPI {

	class GLTexture : public Texture {
	private:
		unsigned int id;
		int currentUnit;
	public:
		int width, height, colorChannels;
		GLTexture(unsigned char* data, int width, int height, int colorChannels);
		~GLTexture();
		void Bind(int unit) override;
		void Unbind() override;
	};

}
