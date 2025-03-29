#include "MeshRenderer.h"

#include <iostream>

#include "RenderAPIDataTypes.h"


namespace Factory {

	namespace FactoryEngine {

        using namespace RenderAPI;

		namespace LowLevelGraphics {

			MeshRenderData::MeshRenderData(Mesh* meshData) : meshData(meshData) {
				vertexArray = nullptr;
				vertexBuffer = nullptr;
				indexBuffer = nullptr;
			}

            MeshRenderData::~MeshRenderData() {
                delete vertexArray;
				delete vertexBuffer;
				delete indexBuffer;
            }

			void MeshRenderData::TransferData() {
				vertexArray = RenderingAPI::CreateVertexArray(std::vector<VertexArrayAttribute>());
				vertexBuffer = RenderingAPI::CreateBuffer(BufferType::ARRAY_BUFFER, BufferUsagePattern::STATIC_DRAW);
				indexBuffer = RenderingAPI::CreateBuffer(BufferType::ELEMENT_ARRAY_BUFFER, BufferUsagePattern::STATIC_DRAW);

                vertexArray->Bind();

				vertexBuffer->SetData(&(meshData->vertices)[0], meshData->vertices.size() * sizeof(Vertex));
				vertexBuffer->Bind();

				indexBuffer->SetData(&(meshData->indices)[0], meshData->indices.size() * sizeof(unsigned int));
                indexBuffer->Bind();

				vertexArray->AddAttribute(VertexArrayAttribute(0, 3, DataType::FLOAT, false, 3 * sizeof(float), (void*)0));

				vertexArray->Unbind();
				vertexBuffer->Unbind();
				indexBuffer->Unbind();
			}

            void MeshRenderData::Render() {
				vertexArray->Bind();
				RenderingAPI::DrawElements(PrimitiveType::TRIANGLES, meshData->indices.size(), DataType::UNSIGNED_INT, 0);
				vertexArray->Unbind();
            }

		}

		void MeshRenderer::SetMesh(Mesh* meshData) {
			meshRenderData = new LowLevelGraphics::MeshRenderData(meshData);
			meshRenderData->TransferData();
		}


		MeshRenderer::~MeshRenderer() {
			delete meshRenderData;
		}

		void MeshRenderer::Render() {
			meshRenderData->Render();
		}

		void MeshRenderer::Update() {
			Render();
		}

	}

}