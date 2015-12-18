//
//  SolidObject.h
//  SpaceGame


#ifndef __SpaceGame__SolidObject__
#define __SpaceGame__SolidObject__
#define PI 3.14159265
#include <SFML/Window.hpp>
#include <cmath>
#include <string>
#include "VectorMaths.h"    //A collection functions for vector mathematics
#include "DestroyEffect.h"    //An animated sprite that plays when an instance of SolidObject is destroyed
#include "Material.h"              //Class that, at the moment, just contains an sf::Sound

class SolidObject{
public:
    static std::vector<SolidObject*> ObList;            // A vector of pointers to all instances of SolidObject, for collision checks, and updating position
    static double dt;                                                  // The time elapsed per frame, for physics updates
    static sf::RenderWindow * targetWindow;          // A pointer to the sf::RenderWindow being used, to avoid having to pass it as an argument to every update() funtion.
    
    std::string name;
    
    virtual void update();
    void applyDamage(long dmg);
    void applyNetForce(sf::Vector2f force);
    void applyNetForce(float forcex, float forcey);
    void applyForceAtGlobalPoint(sf::Vector2f force, sf::Vector2f point);
    void applyTorque(float torque);
    void destroy();
    bool isDestroyed();
    double getStructuralIntegrity();
    double getMaxStructuralIntegrity();
    double getStructuralStrength();
    float getElasticity();
    double getKineticEnergy();
    sf::Vector2f getPosition();
    double getRotation();
    double getRotationInRadians();
    sf::Vector2f getCenterOfMass();
    sf::Vector2f getVelocity();
    double getRotationalVelocity();
    double getRotationalVelocityInRadians();
    double getMass();
    double getMomentOfInertia();
    sf::Sprite getSprite();
    std::vector<sf::Vector2f> getCollisionLinePoints();
    sf::Vector2u getSize();
    Material getMaterial();
    int getFramesSinceLastCollision();
    void move(sf::Vector2f displacement);
    void move(float x, float y);
    void setRotation(double rotation);
    void setPosition(sf::Vector2f posit);
    void setPosition(float positX, float positY);
    void setVelocity(sf::Vector2f newV);
    void setVelocity(double newVx, double newVy);
    void setRotationalVelocity(double );
    void setCollided(bool yesno);
    SolidObject(std::string nam, double mass, double momentOfInertia, float elasticity, sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect destroyEffect,
                        sf::Sound destroySound, std::vector<sf::Vector2f> LinePoints, long structuralIntegrity, unsigned int structuralStrength, Material & material);
    SolidObject(){};

protected:
    double _mass;
    double _momentOfInertia;
    float _elasticity;      //ranges from 0 to 1
    sf::Vector2f _velocity;
    double _rotationalVelocity;
    sf::Vector2f _centerOfMass;
    sf::Vector2u _size;
    double _maxStructuralIntegrity;                   // Max "HP"
    double _structuralIntegrity;         //Energy absorbed before breaking
    double _structuralStrength;    // determines how much damage occurs on collision, currently based off of ultimate tensile strength
    Material * _material;
    std::vector<sf::Vector2f> _collisionLinePoints;              //A collection of points, which are transformed to global co-ordinates and used to construct lines for collision detection
    //_collisionLinePoints must be with respect to top left of sprite and in order of connection.
    
    sf::Sprite _sprite;
    DestroyEffect _destroyAnimation;
    void playDestroyAnimation();
    sf::Sound _destroySound;
    bool _destroyed=false;
    bool _collided=false;                              //if collided last frame
    int _noCollideCount=0;                          //number of frames since a collision
    void updateCollisionData();
    void updatePosition();
    void updateStatus();
    
    //Units
    //Are multiplied by relevent constructor arguments, so that if I decide to change the scale, I don't have to pass huge numbers to the constructor
    const static int massUnits = 1000;                //kg
    const static int momentOfInertiaUnits = 100000000;  //kgm^2
    const static int torqueUnits = 100000000;                   //Nm
    const static int forceUnits = 100000;                    //N
    const static int velocityUnits = 1;                       //m/s
    const static int distanceUnits = 1;                      //m                                (1 metre per pixel)
    const static int structuralIntegrityUnits = 50000;
    const static int structuralStrengthUnits = 1;
};

#endif /* defined(__SpaceGame__SolidObject__) */
