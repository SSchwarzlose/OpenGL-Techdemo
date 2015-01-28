#ifndef CUBE_HPP_
    #define CUBE_HPP_

#include <GL\glew.h>
#include <GL\freeglut.h>

class Cube
{
public:
    Cube(void);
    virtual ~Cube(void);

    void drawCube();
    void drawColoredCube();
	void drawQuad();
    void drawBackfaceCube();
};

#endif