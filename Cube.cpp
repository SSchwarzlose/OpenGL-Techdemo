#include "Cube.hpp"


Cube::Cube(void)
{
}


Cube::~Cube(void)
{
}

void Cube::drawCube()
{
	glBegin(GL_QUADS);
	  // Top face
      //glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex3f( 0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f,  0.1f);
      glVertex3f( 0.1f, 0.1f,  0.1f);
 
      // Bottom face
      //glColor3f(1.0f, 0.5f, 0.0f); 
      glVertex3f( 0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
 
      // Front face
      //glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3f( 0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f, -0.1f, 0.1f);
      glVertex3f( 0.1f, -0.1f, 0.1f);
 
      // Back face
      //glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f( 0.1f,  0.1f, -0.1f);
 
      // Left face
      //glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(-0.1f,  0.1f,  0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
 
      // Right face
      //glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(0.1f,  0.1f, -0.1f);
      glVertex3f(0.1f,  0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f, -0.1f);
	glEnd();	
}

void Cube::drawColoredCube()
{
    glBegin(GL_QUADS);
	   // Top face
      glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex3f( 0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f,  0.1f);
      glVertex3f( 0.1f, 0.1f,  0.1f);
 
      // Bottom face
      glColor3f(1.0f, 0.5f, 0.0f); 
      glVertex3f( 0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
 
      // Front face
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3f( 0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f, -0.1f, 0.1f);
      glVertex3f( 0.1f, -0.1f, 0.1f);
 
      // Back face
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f( 0.1f,  0.1f, -0.1f);
 
      // Left face
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(-0.1f,  0.1f,  0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
 
      // Right face
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(0.1f,  0.1f, -0.1f);
      glVertex3f(0.1f,  0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f, -0.1f);
	glEnd();	
}

void Cube::drawBackfaceCube()
{
    glCullFace(GL_FRONT);
    glBegin(GL_QUADS);
	   // Top face
      glColor3f(0.0f, 1.0f, 0.0f); 
      glVertex3f( 0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f, -0.1f);
      glVertex3f(-0.1f, 0.1f,  0.1f);
      glVertex3f( 0.1f, 0.1f,  0.1f);
 
      // Bottom face
      glColor3f(1.0f, 0.5f, 0.0f); 
      glVertex3f( 0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
 
      // Front face
      glColor3f(1.0f, 0.0f, 0.0f); 
      glVertex3f( 0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f,  0.1f, 0.1f);
      glVertex3f(-0.1f, -0.1f, 0.1f);
      glVertex3f( 0.1f, -0.1f, 0.1f);
 
      // Back face
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex3f( 0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f( 0.1f,  0.1f, -0.1f);
 
      // Left face
      glColor3f(0.0f, 0.0f, 1.0f); 
      glVertex3f(-0.1f,  0.1f,  0.1f);
      glVertex3f(-0.1f,  0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f, -0.1f);
      glVertex3f(-0.1f, -0.1f,  0.1f);
 
      // Right face
      glColor3f(1.0f, 0.0f, 1.0f);
      glVertex3f(0.1f,  0.1f, -0.1f);
      glVertex3f(0.1f,  0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f,  0.1f);
      glVertex3f(0.1f, -0.1f, -0.1f);
	glEnd();	

    glCullFace(GL_BACK);
}
