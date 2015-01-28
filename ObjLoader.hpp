#ifndef OBJLOADER_HPP_
#define OBJLOADER_HPP_

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <glm.hpp>
#include <glimg\glimg.h>
#include <glload\gl_load.hpp>
#include <vector>
#include <stdio.h>

class ObjLoader
{
public:
    ObjLoader(void);
    virtual ~ObjLoader(void);

public:
    void loadObj(const char* filename, std::vector<glm::vec3> &vertices, std::vector<glm::vec3> &normals, std::vector<glm::vec2> &uvs);
    void loadTexture();
    void loadVBOData(std::vector<glm::vec3> &vertices, std::vector<glm::vec2> &uvs);

    GLuint textureID;
    GLuint vertexBufferID;
    GLuint uvBufferID;

};

#endif