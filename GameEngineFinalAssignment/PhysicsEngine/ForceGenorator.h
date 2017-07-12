//
//  ForceGenorator.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#ifndef __GameEngineFinalAssignment__ForceGenorator__
#define __GameEngineFinalAssignment__ForceGenorator__

#include <stdio.h>
#include "Particle.h"
#include "Util.h"
#include <vector>
class ForceGenorator {
public:
    ForceGenorator();
    void applyForce(float dt);
};
class GravityForceGenorator : public ForceGenorator{
public:
    GravityForceGenorator(std::vector<Particle> &p, ver3f f);
    void applyForce(float dt);
private:
    std::vector<Particle> &particles;
    ver3f force;
};
#endif /* defined(__GameEngineFinalAssignment__ForceGenorator__) */
