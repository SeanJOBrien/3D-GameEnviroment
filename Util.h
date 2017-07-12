//
//  Util.h
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 03/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#ifndef GameEngineFinalAssignment_Util_h
#define GameEngineFinalAssignment_Util_h
#include <math.h>

// Model Utilitys
struct Vertex
{
    float x;
    float y;
    float z;
};
struct Normals
{
    float x;
    float y;
    float z;
};
struct UVS
{
    float u;
    float v;
};

// Physic Utilitys
class ver3f {
public:
    float x;
    float y;
    float z;
    ver3f();
    ver3f(float x,float y, float z);
    ver3f(ver3f const &vertex);
    float length();
    float dot(ver3f vertex);
    ver3f add(ver3f vertex);
    ver3f add(float scaler);
    ver3f sub(ver3f vertex);
    ver3f sub(float scaler);
    ver3f multi(ver3f vertex);
    ver3f multi(float scaler);
    ver3f div(ver3f vertex);
    ver3f div(float scaler);
    void normalise();
    ver3f normalised();
    
    //~ver3f();
};


#endif
