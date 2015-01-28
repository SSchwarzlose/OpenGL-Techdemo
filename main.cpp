#include <GL\glew.h>
#include <GL\freeglut.h>
#include <glimg\glimg.h>
#include <glload\gl_load.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>

#include "ObjLoader.hpp"
#include "Cube.hpp"
#include "Wendy.hpp"
#include "Quad.hpp"
#include "Camera.hpp"

float axisX, axisZ, lookAtX, lookAtZ;

ObjLoader loader;
Cube cube;
Wendy wendy;
Quad quad;
Camera camera;

std::vector<glm::vec3> vertices;
std::vector<glm::vec3> normals;
std::vector<GLushort> texture;
std::vector<glm::vec2> uvs;

void Init()
{
    glClearColor(0, 0, 0, 1);
    glClearDepth(1);

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY);

    loader  = ObjLoader();
    cube  = Cube();
	wendy = Wendy();
	quad = Quad();
	camera = Camera();

    loader.loadObj("wendy_Scene.obj", vertices, normals, uvs);
    loader.loadTexture();
    loader.loadVBOData(vertices, uvs);

}

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBindTexture(GL_TEXTURE_2D, loader.textureID);

    glBindBuffer(GL_ARRAY_BUFFER, loader.vertexBufferID);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, loader.uvBufferID);
    glTexCoordPointer(2, GL_FLOAT, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

	

    glutSwapBuffers();
}

void Idle()
{
    glutPostRedisplay();
}

void Reshape(GLsizei width, GLsizei height)
{
    if (height < 1)
    {
        height = 1;
    }

    GLfloat aspect = (GLfloat)width / (GLfloat) height;

    glViewport(0,0,width,height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Tech Demo");
    glutDisplayFunc (Display);
    glutReshapeFunc(Reshape);
    glewInit();
    glutIdleFunc(Idle);
    Init();
    glutMainLoop();

    return 0;
}