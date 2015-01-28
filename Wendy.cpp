#include "Wendy.hpp"


Wendy::Wendy(void)
{
}


Wendy::~Wendy(void)
{
}

void Wendy::drawWendy(std::vector<glm::vec3> vertices)
{
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();
}

void Wendy::drawWendy(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs)
{
	glBegin(GL_TRIANGLES);
	for (unsigned int i = 0; i < vertices.size(); i++)
	{
		glTexCoord2f(uvs[i].x, uvs[i].y);
		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
	}
	glEnd();
}
