#include "MeshRenderer.h"
#include <glad/glad.h>

#include <iostream>

namespace Factory {

	namespace FactoryEngine {

		namespace LowLevelGraphics {

			MeshRenderData::MeshRenderData(Mesh* meshData) : meshData(meshData) { }
            MeshRenderData::~MeshRenderData() {
                glDeleteVertexArrays(1, &vertexArray);
                glDeleteBuffers(1, &vertexBuffer);
                glDeleteBuffers(1, &indexBuffer);
            }

			void MeshRenderData::TransferData() {
                glGenVertexArrays(1, &vertexArray);
                glGenBuffers(1, &vertexBuffer);
                glGenBuffers(1, &indexBuffer);

                glBindVertexArray(vertexArray);

                glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
                glBufferData(GL_ARRAY_BUFFER, meshData->vertices.size() * sizeof(Vertex), &(meshData->vertices)[0], GL_STATIC_DRAW);

                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
                glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshData->indices.size() * sizeof(unsigned int), &(meshData->indices)[0], GL_STATIC_DRAW);

                glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
                glEnableVertexAttribArray(0);

                glBindVertexArray(0);
                glBindBuffer(GL_ARRAY_BUFFER, 0);
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}

            void MeshRenderData::Render() {
                glBindVertexArray(vertexArray);
                glDrawElements(GL_TRIANGLES, meshData->indices.size(), GL_UNSIGNED_INT, 0);
                glBindVertexArray(0);
            }

		}

	}

}
