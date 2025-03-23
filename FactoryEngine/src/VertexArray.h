#pragma once

#include <vector>

#include <glad/glad.h>

#include "Core.h"
#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

		namespace RenderAPI {

			struct FACTORY_API VertexArrayAttribute {
				unsigned int index;
				int size;
				DataType type;
				bool normalized;
				int stride;
				const void* pointer;

				VertexArrayAttribute(
					unsigned int index,
					int size,
					DataType type,
					bool normalized,
					int stride,
					const void* pointer);
			};

			class FACTORY_API VertexArray {
			public:
				std::vector<VertexArrayAttribute> attributes;

				VertexArray(std::vector<VertexArrayAttribute> attributes);
				virtual void AddAttribute(VertexArrayAttribute attribute) = 0;
				virtual void Bind() = 0;
				virtual void Unbind() = 0;
			};

			namespace OpenGL {


				class GLVertexArray : public VertexArray {
				public:
					unsigned int index;

					GLVertexArray(std::vector<VertexArrayAttribute> attributes);
					~GLVertexArray();

					void AddAttribute(VertexArrayAttribute attribute) override;
					void Bind() override;
					void Unbind() override;
				};

			}

		}

	}

}
