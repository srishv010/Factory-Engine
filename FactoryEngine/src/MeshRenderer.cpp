#include "MeshRenderer.h"
#include <glad/glad.h>

#include <iostream>

namespace Factory {

	namespace FactoryEngine {

        using namespace RenderAPI;
        using namespace OpenGL;

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
				vertexArray = new GLVertexArray(std::vector<VertexArrayAttribute>());
				vertexBuffer = new GLBuffer(GL_ARRAY_BUFFER, GL_STATIC_DRAW);
				indexBuffer = new GLBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW);

                vertexArray->Bind();

				vertexBuffer->SetData(&(meshData->vertices)[0], meshData->vertices.size() * sizeof(Vertex));
				vertexBuffer->Bind();

				indexBuffer->SetData(&(meshData->indices)[0], meshData->indices.size() * sizeof(unsigned int));
                indexBuffer->Bind();

				vertexArray->AddAttribute(VertexArrayAttribute(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0));

				vertexArray->Unbind();
				vertexBuffer->Unbind();
				indexBuffer->Unbind();
			}

            void MeshRenderData::Render() {
				vertexArray->Bind();
                glDrawElements(GL_TRIANGLES, meshData->indices.size(), GL_UNSIGNED_INT, 0);
				vertexArray->Unbind();
            }

		}

		MeshRenderer::MeshRenderer(Mesh* meshData) {
			meshRenderData = new LowLevelGraphics::MeshRenderData(meshData);
			meshRenderData->TransferData();
		}

		MeshRenderer::~MeshRenderer() {
			delete meshRenderData;
		}

		void MeshRenderer::Render() {
			meshRenderData->Render();
		}

	}

}