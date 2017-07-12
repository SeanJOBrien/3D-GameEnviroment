//
//  GameEngine.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 03/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#ifndef GameEngineFinalAssignment_GameEngine_h
#define GameEngineFinalAssignment_GameEngine_h

#include <math.h>
#include <fstream>
#include <vector>
#include "AdvancedModel.h"
#include "Particle.h"
#include "ColitionGenorator.h"
#include "ForceGenorator.h"
#include "ConstrainGenorator.h"
using namespace std;

#define GL_PI 3.1415

AdvancedModel *model;
float eyeX, eyeY, eyeZ = 0;
float rotX, rotY, rotZ = 0;
float dist = 50;
float verX, verY, verZ = 0;
std::vector<Particle> particles;
GroundColitionGenorator *gcg;
PToPColitionGenorator *ptp;
GravityForceGenorator *gfg;
std::vector<AnchoredEqualityConstrainGenorator> aecg;
int mode = 1;
bool multiView = false;
int demoMode = 0;
float oldStartTime = 0.0;
int main(int argc, char* argv[]);
void setupRC(void);
void renderScene(void);
void update(void);
void specialKeys(int key, int x, int y);
void reset();
void floor();

#endif
