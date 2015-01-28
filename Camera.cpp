#include "Camera.hpp"


Camera::Camera(void)
{
	phase1 = true;
	phase2 = false;
	phase3 = false;
	phase4 = false;
    phase5 = false;
    phase6 = false;
}


Camera::~Camera(void)
{
}

void Camera::sceneTracking(float &axisX, float &axisZ, float &lookAtX, float &lookAtZ)
{
    //Phase1: An Model ohne Textur vorbeifahren
    if (phase1 && axisZ <= 3 && axisX > -1.5 && lookAtX < 1)
	{
		axisZ += 0.01;
		axisX -= 0.003;
	}

    // Wechsel der ansicht auf Model mit Textur
	if (phase1 && axisZ >= 3 && lookAtX <= 1)
	{
		lookAtX += 0.01;
        if(lookAtX >=1)
        {
            phase1 = false;
            phase2 = true;
        }
	}

    // Phase 2: Fahrt vorbei an Model mit Textur
	if (phase2 && lookAtX >= 1 && lookAtX < 2 )
	{
        if(axisX < 2)
		    axisX += 0.01;
        if(axisZ > 1)
		    axisZ -= 0.004;
	}

    // Wechsel der Ansicht auf Quad ohne Textur
    if (phase2 && axisX >= 2 && axisZ <= 1)
    {
        if (lookAtX < 2)
        {
            lookAtX += 0.01;
            if(lookAtX >= 2)
            {
                phase2 = false;
                phase3 = true;
            }

        }
    }

    // Phase 3: Fahrt voebei an Quad ohne und mit Textur bis Cube ohne Textur
    if (phase3 && lookAtX >= 2 && axisX <= 4)
    {
        lookAtX += 0.003f;
        axisX += 0.003f;
    }

    // Fahrt hinter Cube ohne Textur
    if (phase3 && axisX >= 4 && axisZ <= 3)
    {
        axisX += 0.002;
        axisZ += 0.006;
        if (axisZ >= 3)
        {
            phase3 = false;
            phase4 = true;
        }
    }

    // Phase 4: Wechsel der Ansicht auf mehrfarbigen Cube
    if (phase4 && lookAtX <= 5)
    {
        lookAtX += 0.005;
    }

    // fahrt vorbei an farbigen cube
    if (phase4 && lookAtX >= 5 && axisX <= 7)
    {
        axisX += 0.01;
        if (axisX >= 6 && lookAtX <= 6)
        {
            lookAtX += 0.012;
        }
    }

    if (phase4 && axisX >= 7)
    {
        phase4 = false;
        phase5 = true;
    }

    if (phase5 && axisX >= 7 && axisZ >= 1)
    {
        axisZ -= 0.005;
        if (axisZ <= 1)
        {
            phase5 = false;
            phase6 = true;
        }
    }

    // Phase 5: Fahrt zur ausgangsposition
    if (phase6 && axisX >= 0 && axisZ >= 0)
    {
        if (lookAtX >= 0)
        {
            lookAtX -= 0.01;
        }
        axisX -= 0.01;
        axisZ -= 0.001;
    }
}
