#pragma once


namespace RenderAPIInterface {

	class Texture {
	public:
		virtual void Bind(int unit) = 0;
		virtual void Unbind() = 0;
	};

}
