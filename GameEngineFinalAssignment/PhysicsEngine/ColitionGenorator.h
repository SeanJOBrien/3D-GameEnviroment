//
//  ColitionGenorator.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#ifndef __GameEngineFinalAssignment__ColitionGenorator__
#define __GameEngineFinalAssignment__ColitionGenorator__

#include <stdio.h>
#include "Particle.h"
#include "Util.h"
#include <vector>

class ColitionGenorator {
public:
    ColitionGenorator();
    void resolve();
};
class GroundColitionGenorator : ColitionGenorator{
public:
    GroundColitionGenorator(std::vector<Particle> &p);
    void resolve();
private:
    std::vector<Particle> &particles;
};

class PToPColitionGenorator : ColitionGenorator{
public:
    PToPColitionGenorator(std::vector<Particle> &p);
    void resolve();
private:
    void pointToPointColition(Particle &a,Particle &b);
    std::vector<Particle> &particles;
};

#endif /* defined(__GameEngineFinalAssignment__ColitionGenorator__) */
