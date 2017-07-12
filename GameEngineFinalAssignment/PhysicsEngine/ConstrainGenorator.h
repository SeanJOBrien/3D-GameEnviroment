//
//  ConstrainGenorator.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#ifndef __GameEngineFinalAssignment__ConstrainGenorator__
#define __GameEngineFinalAssignment__ConstrainGenorator__

#include <stdio.h>
#include "Particle.h"
#include "Util.h"
#include <vector>


class ConstrainGenorator {
public:
    ConstrainGenorator();
    void resolve();
};
class AnchoredEqualityConstrainGenorator : public ConstrainGenorator{
public:
    AnchoredEqualityConstrainGenorator(Particle &p, ver3f a, float distance);
    void resolve();
private:
    Particle &particle;
    ver3f anchor;
    float distance;
};

#endif /* defined(__GameEngineFinalAssignment__ConstrainGenorator__) */
