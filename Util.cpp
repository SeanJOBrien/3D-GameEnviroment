//
//  Util.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 03/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#include "Util.h"

ver3f::ver3f()
{
    x = 0.0;
    y = 0.0;
    z = 0.0;
}
ver3f::ver3f(float localX,float localY, float localZ)
{
    x = localX;
    y = localY;
    z = localZ;
}
ver3f::ver3f(ver3f const &vertex)
{
    x = vertex.x;
    y = vertex.y;
    z = vertex.z;
}
float ver3f::length()
{
    return sqrt(pow(x, 2)+pow(y, 2)+pow(z, 2));
}
void ver3f::normalise()
{
    x = x/length();
    y = y/length();
    z = z/length();
}
ver3f ver3f::normalised()
{
    return ver3f(x/length(),y/length(),z/length());
}
float ver3f::dot(ver3f vertex)
{
    return x*vertex.x + y*vertex.y + z*vertex.z;
}
ver3f ver3f::add(ver3f vertex)
{
    return ver3f(x+vertex.x,y+vertex.y,z+vertex.z);
}
ver3f ver3f::add(float scaler)
{
    return ver3f(x+scaler,y+scaler,z+scaler);
}
ver3f ver3f::sub(ver3f vertex)
{
    return ver3f(x-vertex.x,y-vertex.y,z-vertex.z);
}
ver3f ver3f::sub(float scaler)
{
    return ver3f(x-scaler,y-scaler,z-scaler);
}
ver3f ver3f::multi(ver3f vertex)
{
    return ver3f(x*vertex.x,y*vertex.y,z*vertex.z);
}
ver3f ver3f::multi(float scaler)
{
    return ver3f(x*scaler,y*scaler,z*scaler);
}
ver3f ver3f::div(ver3f vertex)
{
    return ver3f(x/vertex.x,y/vertex.y,z/vertex.z);
}
ver3f ver3f::div(float scaler)
{
    return ver3f(x/scaler,y/scaler,z/scaler);
}

