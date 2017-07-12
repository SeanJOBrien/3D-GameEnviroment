//
//  AdvancedModel.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 21/12/2014.
//  Copyright (c) 2014 Yoshine LTD. All rights reserved.
//

#ifndef __GameEngineFinalAssignment__AdvancedModel__
#define __GameEngineFinalAssignment__AdvancedModel__

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

#include <math.h>
using namespace std;
#include <fstream>
#include <vector>
#include <stdio.h>
#include "Util.h"

class AdvancedModel
{
public:
    std::vector<Vertex> vertices;
    std::vector<UVS> uvs;
    std::vector<Normals> normals;
    
    AdvancedModel(int index);
    void render(int mode);
    bool loadObj(const char * path);
};

#endif
