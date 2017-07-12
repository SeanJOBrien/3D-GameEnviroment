//
//  ForceGenorator.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#include "ForceGenorator.h"
ForceGenorator::ForceGenorator(){ }
void ForceGenorator::applyForce(float dt)
{
    
}

GravityForceGenorator::GravityForceGenorator(std::vector<Particle> &p,ver3f f): particles(p),force(f){ }
void GravityForceGenorator::applyForce(float dt)
{
    for (int i = 0; i < particles.size(); i++) {
        particles[i].setVelocity(particles[i].Velocity().add(force.multi(1/dt)));
    }
}