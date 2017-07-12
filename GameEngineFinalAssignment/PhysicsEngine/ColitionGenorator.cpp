//
//  ColitionGenorator.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#include "ColitionGenorator.h"

ColitionGenorator::ColitionGenorator(){ }
void ColitionGenorator::resolve()
{

}
GroundColitionGenorator::GroundColitionGenorator(std::vector<Particle> &p): particles(p){ }
void GroundColitionGenorator::resolve()
{
    for (int i = 0; i < particles.size(); i++)
    {
        if (particles[i].Position().y-particles[i].getRadius() < 0.0)
        {
            particles[i].setPosition(particles[i].Position().x, particles[i].getRadius(),particles[i].Position().z);
            particles[i].setVelocity(particles[i].Velocity().x,-particles[i].Velocity().y,particles[i].Velocity().z);
        }
    }
}

PToPColitionGenorator::PToPColitionGenorator(std::vector<Particle> &p): particles(p){ }
void PToPColitionGenorator::resolve()
{
    for (int i = 0; i < particles.size(); i++)
    {
        for (int j = i+1; j < particles.size(); j++)
        {
            float radi = particles[j].getRadius()+particles[i].getRadius();
            float distance = particles[j].Position().sub(particles[i].Position()).length();
            if (distance < radi)
            {
                ver3f distanceVer = particles[j].Position().sub(particles[i].Position());
                float distanceToMove =   radi - distance;
                float percentageToMove = distanceToMove/distance;
                
                particles[i].setPosition(particles[i].Position().sub(distanceVer.multi(percentageToMove)));
                pointToPointColition(particles[i],particles[j]);
            }
        }
    }
}
void PToPColitionGenorator::pointToPointColition(Particle &a,Particle &b)
{
    ver3f U1x,U1y,U2x,U2y,V1x,V1y,V2x,V2y;
    
    
    float m1, m2, x1, x2;
    ver3f v1, v2, v1x, v2x, v1y, v2y, x;
    
    x=a.Position().sub(b.Position());
    x.normalise();
    v1 = a.Velocity();
    x1 = x.dot(v1);
    v1x = x.multi(x1);
    v1y = v1.sub(v1x);
    m1 = 1.0;
    
    x = x.multi(-1.0);
    v2 = b.Velocity();
    x2 = x.dot(v2);
    v2x = x.multi(x2);
    v2y = v2.sub(v2x);
    m2 = 1.0;
    
    a.setVelocity(ver3f( v1x.multi(m1-m2).div(m1+m2).add(v2x.multi(2*m2)).div(m1+m2)).add (v1y) );
    b.setVelocity(ver3f( v1x.multi(2*m1).div(m1+m2).add(v2x.multi(m2-m1)).div(m1+m2)).add(v2y));
}