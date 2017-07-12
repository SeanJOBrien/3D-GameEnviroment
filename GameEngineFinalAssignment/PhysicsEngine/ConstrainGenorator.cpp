//
//  ConstrainGenorator.cpp
//  GameEngineFinalAssignment
//
//  Created by Mr Yoshine on 04/01/2015.
//  Copyright (c) 2015 Yoshine LTD. All rights reserved.
//

#include "ConstrainGenorator.h"

ConstrainGenorator::ConstrainGenorator(){}
void ConstrainGenorator::resolve()
{
    
}

AnchoredEqualityConstrainGenorator::AnchoredEqualityConstrainGenorator(Particle &p, ver3f a,float d):particle(p), anchor(a), distance(d){}
void AnchoredEqualityConstrainGenorator::resolve()
{
    if (anchor.sub(particle.Position()).length() < distance)
    {
        ver3f distanceVer = anchor.sub(particle.Position());
        float currentDistance = (anchor.sub(particle.Position()).length());
        float distanceToMove =   distance - currentDistance;
        float percentageToMove = distanceToMove/currentDistance;
        
        particle.setPosition(particle.Position().sub(distanceVer.multi(percentageToMove)));
       // particle.setVelocity(particle.Velocity().add(((anchor.sub(particle.Position())).normalised()).div(30)));
        
    } else if((anchor.sub(particle.Position()).length() > distance)){
        ver3f distanceVer = anchor.sub(particle.Position());
        float currentDistance = (anchor.sub(particle.Position()).length());
        float distanceToMove =   currentDistance - distance;
        float percentageToMove = distanceToMove/currentDistance;
        
        particle.setPosition(particle.Position().add(distanceVer.multi(percentageToMove)));
        //particle.setVelocity(particle.Velocity().add(((anchor.sub(particle.Position())).normalised()).div(30)));
    }
}