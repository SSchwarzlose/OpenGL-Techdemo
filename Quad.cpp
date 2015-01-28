#include "Quad.hpp"


Quad::Quad(void)
{
}


Quad::~Quad(void)
{
}

void Quad::drawQuad()
{
	glBegin(GL_QUADS);

	glVertex3f(0, 0, 0);
	glVertex3f(0.2f, 0, 0);
	glVertex3f(0.2f, 0.2f, 0);
	glVertex3f(0, 0.2f, 0);

	glEnd();
}

void Quad::drawTexturedQuad()
{
	glBegin(GL_QUADS);

	glTexCoord2f(0,0);
	glVertex3f(0, 0, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.2f, 0, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.2f, 0.2f, 0);
	glTexCoord2f(0, 1);
	glVertex3f(0, 0.2f, 0);

	glEnd();
}
