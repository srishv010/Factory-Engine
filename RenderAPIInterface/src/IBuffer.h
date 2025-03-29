#pragma once

#include "RenderAPIDataTypes.h"


namespace RenderAPIInterface {

	class Buffer {
	public:
		virtual void SetData(void* data, size_t size) = 0;
		virtual void Bind() = 0;
		virtual void Unbind() = 0;
	};

}
