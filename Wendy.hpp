#ifndef _WENDY_HPP_
#define _WENDY_HPP_

#include <GL\glew.h>
#include <GL\freeglut.h>
#include <glimg\glimg.h>
#include <glload\gl_load.hpp>
#include <glm.hpp>
#include <vector>

class Wendy
{
public:
	Wendy(void);
	virtual ~Wendy(void);

	void drawWendy(std::vector<glm::vec3>vertices, std::vector<glm::vec2> uvs);
	void drawWendy(std::vector<glm::vec3>vertices);
};

#endif