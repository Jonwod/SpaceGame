//
//  Collide.cpp
//  SpaceGame
//
//  Created by Jonathan Wood on 10/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#include "Collide.h"
void damageResolve(SolidObject& obA, SolidObject& obB){
    double vRelative = fabs(magnitude(obA.getVelocity()-obB.getVelocity()));
    double totalKE= vRelative * (obA.getMass() + obB.getMass());
    double absorbedKE=totalKE-obA.getElasticity()*obB.getElasticity()*totalKE;
    double dmgA=(absorbedKE*obA.getStructuralStrength())/(obA.getStructuralStrength()+obB.getStructuralStrength());
    double dmgB=(absorbedKE*obB.getStructuralStrength())/(obA.getStructuralStrength()+obB.getStructuralStrength());
    
    obA.applyDamage(dmgA);
    obB.applyDamage(dmgB);
}

//void collide(SolidObject& obA, SolidObject& obB, sf::Vector2f collidePoint){
//    damageResolve(obA, obB);
//    float e = obA.getElasticity() * obB.getElasticity();
//    sf::Vector2f P = collidePoint;
//    sf::Vector2f rAP = P-obA.getPosition();
//    sf::Vector2f rBP = P-obB.getPosition();
//    
//    float wAi=(PI/180)*obA.getRotationalVelocity();
//    float wBi=(PI/180)*obB.getRotationalVelocity();;
//    float ma=obA.getMass();
//    float mb=obB.getMass();
//    
//    sf::Vector2f uA=obA.getVelocity()+sf::Vector2f(-wAi*rAP.y, wAi*rAP.x);
//    sf::Vector2f uB=obB.getVelocity()+sf::Vector2f(-wBi*rBP.y, wBi*rBP.x);
//    
//    obA.setVelocity((ma*uA.x+mb*uB.x+mb*e*(uB.x-uA.x))/(ma+mb), (ma*uA.y+mb*uB.y+mb*e*(uB.y-uA.y))/(ma+mb));
//    obB.setVelocity((ma*uA.x+mb*uB.x+ma*e*(uA.x-uB.x))/(ma+mb), (ma*uA.y+mb*uB.y+ma*e*(uA.y-uB.y))/(ma+mb));
//    
//    sf::Vector2f jA=obA.getVelocity()*ma - uA*ma;
//    sf::Vector2f jB=obB.getVelocity()*mb - uB*mb;
//    
//    obA.setRotationalVelocity(obA.getRotationalVelocity() + ((-rAP.y*jA.x - rAP.x*jA.y)/obA.getMomentOfInertia()));
//    obB.setRotationalVelocity(obB.getRotationalVelocity() + ((-rBP.y*jB.x-rAP.x*jB.y)/obB.getMomentOfInertia()));
//    
//    obA.setCollided(true);
//    obB.setCollided(true);
//    
//    obA.getMaterial().playImpactSoundAt(P);
//    obB.getMaterial().playImpactSoundAt(P);
//}

void collide(SolidObject& obA, SolidObject& obB, sf::Vector2f collidePoint){
    damageResolve(obA, obB);
    float e=0.8;
    sf::Vector2f vAi = obA.getVelocity();
    sf::Vector2f vBi = obB.getVelocity();
    float wAi = obA.getRotationalVelocityInRadians();
    float wBi = obB.getRotationalVelocityInRadians();
    sf::Vector2f P = collidePoint;
    sf::Vector2f rAP = P-obA.getPosition();
    sf::Vector2f rBP = P-obB.getPosition();
    sf::Vector2f vAP = vAi+sf::Vector2f(-wAi*rAP.y, wAi*rAP.x);
    sf::Vector2f vBP = vBi+sf::Vector2f(-wBi*rBP.y, wBi*rBP.x);
    sf::Vector2f vAB=vBP-vAP;
    
    sf::Vector2f normalVector = obA.getPosition() - obB.getPosition();
    
    sf::Vector2f n2unit(normalVector.x/magnitude(normalVector), normalVector.y/magnitude(normalVector));
    sf::Vector3f n3unit(n2unit.x, n2unit.y, 0);
    
    
    double jnumerator = -(1+e) * dotProduct(vAB, n2unit);
    double jdenominator = dotProduct(n2unit, n2unit)*(1/obA.getMass()+1/obB.getMass()) + (pow(dotProduct(rAP, n2unit), 2) / obA.getMomentOfInertia())
                                        + (pow(dotProduct(rBP, n2unit), 2) / obB.getMomentOfInertia());
    float j=jnumerator/jdenominator;                   //The impulse
    
    obA.setVelocity(vAi+multiply(float(-j/obA.getMass()), n2unit));
    obB.setVelocity(vBi+multiply(float(j/obB.getMass()), n2unit));
    obA.setRotationalVelocity( (180/PI) * (wAi + dotProduct(rAP, multiply(j, n2unit)) / obA.getMomentOfInertia()) );
    obB.setRotationalVelocity( (180/PI) * (wBi + dotProduct(rBP, multiply(j, n2unit)) / obB.getMomentOfInertia()) );
}

void seperate(SolidObject& obA, SolidObject& obB){
    float seperationSpeed=2;
    
    if(fabs(obA.getPosition().x - obB.getPosition().x)>fabs(obA.getPosition().y - obB.getPosition().y)){
        if(obA.getPosition().x<obB.getPosition().x){
            obA.move(-seperationSpeed, 0);
            obB.move(seperationSpeed, 0);
        }
        else{
            obA.move(seperationSpeed, 0);
            obB.move(-seperationSpeed, 0);
        }
    }
    else{
        if(obA.getPosition().y<obB.getPosition().y){
            obA.move(0, -seperationSpeed);
            obB.move(0, seperationSpeed);
        }
        else{
            obA.move(0, seperationSpeed);
            obB.move(0, -seperationSpeed);
        }
    }
}
