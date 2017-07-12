//
//  Particle.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 14/12/2014.
//  Copyright (c) 2014 Yoshine LTD. All rights reserved.
//

#ifndef __GameEngineFinalAssignment__Particle__
#define __GameEngineFinalAssignment__Particle__

#ifdef WIN32
#include <GL/gl.h>
#include <GL/glu.h>
#include "freeglut.h"
#include <iostream>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Glut/glut.h>
#include <iostream>
#endif

#include <stdio.h>
#include "Util.h"

class Particle {
public:
    void update(float dt);
    void render();
    ver3f Position();
    ver3f Velocity();
    void setPosition(float x,float y, float z);
    void setVelocity(float x,float y, float z);
    void setPosition(ver3f p);
    void setVelocity(ver3f v);
    float getRadius();
    void setRadius(float r);
    Particle(float x,float y, float z, float r);
    Particle(ver3f v, float r);
private:
    ver3f position;
    ver3f velocity;
    float radius;
};

#endif /* defined(__GameEngineFinalAssignment__Particle__) */
