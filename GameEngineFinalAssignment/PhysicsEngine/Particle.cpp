//
//  Particle.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 14/12/2014.
//  Copyright (c) 2014 Yoshine LTD. All rights reserved.
//

#include "Particle.h"
void Particle::update(float dt)
{
    setPosition(position.add(velocity.multi(1/dt)));
}
void Particle::render()
{
    glPushMatrix();
        glTranslatef(position.x, position.y, position.z);
        glBegin(GL_TRIANGLE_STRIP);
            glutSolidSphere(radius, 20.0, 20.0);
        glEnd();
    glPopMatrix();
    glutPostRedisplay();
    
}
ver3f Particle::Position()
{
    return position;
}
ver3f Particle::Velocity()
{
    return velocity;
}
void Particle::setPosition(float x,float y, float z)
{
    position = ver3f(x,y,z);
}
void Particle::setVelocity(float x,float y, float z)
{
    velocity = ver3f(x,y,z);
}
float Particle::getRadius()
{
    return radius;
}
void Particle::setRadius(float r)
{
    radius = r;
}
void Particle::setPosition(ver3f p)
{
    position = p;
}
void Particle::setVelocity(ver3f v)
{
    velocity = v;
}
Particle::Particle(float x,float y, float z, float r)
{
    position = ver3f(x, y, z);
    radius = r;
}
Particle::Particle(ver3f v, float r)
{
    position = v;
    radius = r;
}