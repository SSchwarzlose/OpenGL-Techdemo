#ifndef _QUAD_HPP_
#define _QUAD_HPP_

#include <GL\glew.h>
#include <GL\freeglut.h>

class Quad
{
public:
	Quad(void);
	virtual ~Quad(void);

	void drawQuad();
	void drawTexturedQuad();
};

#endif