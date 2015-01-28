#ifndef _CAMERA_HPP_
#define _CAMERA_HPP_

class Camera
{
public:
	Camera(void);
	virtual ~Camera(void);

	void sceneTracking(float& axisX, float& axisZ, float& lookAtX, float& lookAtZ);


	bool phase1;
	bool phase2;
	bool phase3;
	bool phase4;
    bool phase5;
    bool phase6;
};

#endif