//
//  SolidObject.cpp
//  SpaceGame
#include "SolidObject.h"

 std::vector<SolidObject*> SolidObject::ObList {};
sf::RenderWindow * SolidObject::targetWindow = 0;
double SolidObject::dt = (1.0/60.0);

void SolidObject::applyDamage(long dmg){
    _structuralIntegrity -= dmg;
}
void SolidObject::applyNetForce(sf::Vector2f force){
    _velocity.x += dt * force.x  / (_mass );
    _velocity.y += dt * force.y  / (_mass );
}

void SolidObject::applyNetForce(float forceX, float forceY){
    _velocity.x += dt * forceX  / (_mass  );         
    _velocity.y += dt * forceY  / ( _mass );
}

void SolidObject::applyForceAtGlobalPoint(sf::Vector2f force, sf::Vector2f point){
    applyNetForce(force);
    applyTorque(crossProduct(point - _sprite.getPosition(), force));
}

void SolidObject::applyTorque(float torque){
    _rotationalVelocity += dt * (torque) / _momentOfInertia;
}

void SolidObject::destroy(){
    playDestroyAnimation();
    _destroySound.setPosition(_sprite.getPosition().x, _sprite.getPosition().y, 0);
    _destroySound.play();
    _destroyed=true;
}

bool SolidObject::isDestroyed(){
    return _destroyed;
}

double SolidObject::getStructuralIntegrity(){
    return _structuralIntegrity;
}

double SolidObject::getMaxStructuralIntegrity(){
    return _maxStructuralIntegrity;
}

double SolidObject::getStructuralStrength(){
    return _structuralStrength;
}

float SolidObject::getElasticity(){
    return _elasticity;
}

double SolidObject::getKineticEnergy(){
    return 0.5 * _mass * pow(magnitude(_velocity), 2) + 0.5 * _momentOfInertia * pow(_rotationalVelocity * (PI / 180), 2);
};

double SolidObject::getRotation(){
    return _sprite.getRotation();
};

double SolidObject::getRotationInRadians(){
    return _sprite.getRotation() * (PI/180);
}

sf::Vector2f SolidObject::getPosition(){
    return _sprite.getPosition();
}

void SolidObject::move(sf::Vector2f displacement){
    _sprite.move(displacement);
}

void SolidObject::move(float x, float y){
    _sprite.move(x, y);
}

void SolidObject::playDestroyAnimation(){
    _destroyAnimation.playEffect(getPosition(),  getVelocity());
}

void SolidObject::setRotation(double rotation){
    _sprite.setRotation(rotation);
}

void SolidObject::setPosition(sf::Vector2f posit){
    _sprite.setPosition(posit);
}

void SolidObject::setPosition(float x, float y){
    _sprite.setPosition(x, y);
}

sf::Vector2f SolidObject::getCenterOfMass(){
    return _centerOfMass;
}

sf::Vector2f SolidObject::getVelocity(){
    return _velocity;
}

double SolidObject::getRotationalVelocity(){
    return _rotationalVelocity;
}

double SolidObject::getRotationalVelocityInRadians(){
    return _rotationalVelocity * (PI/180);
}

double SolidObject::getMass(){
    return _mass;
}

double SolidObject::getMomentOfInertia(){
    return _momentOfInertia;
}

sf::Sprite SolidObject::getSprite(){
    return _sprite;
}

sf::Vector2u SolidObject::getSize(){
    return _size;
}

Material SolidObject::getMaterial(){
    return *_material;
}

std::vector<sf::Vector2f> SolidObject::getCollisionLinePoints(){
    return _collisionLinePoints;
}

int SolidObject::getFramesSinceLastCollision(){
    return _noCollideCount;
}

void SolidObject::setRotationalVelocity(double newWinDegrees){
    _rotationalVelocity = newWinDegrees;
}

void SolidObject::setCollided(bool yesno){
    _collided = yesno;
}

void SolidObject::setVelocity(sf::Vector2f newV){
    _velocity = newV;
}

void SolidObject::setVelocity(double newVx, double newVy){
    _velocity.x = newVx;
    _velocity.y = newVy;
}

void SolidObject::update(){
    updateCollisionData();
    updatePosition();
    updateStatus();
    targetWindow->draw(_sprite);
}

SolidObject::SolidObject(std::string nam, double mass, double momentOfInertia, float elasticity, sf::Vector2f centerOfMass, sf::Sprite sprite, DestroyEffect destroyAnimation,
                                        sf::Sound destroySound, std::vector<sf::Vector2f> LinePoints, long structuralIntegrity, unsigned int structuralStrength, Material & material)
{
    name = nam;
    _mass = mass * massUnits;
    _momentOfInertia = momentOfInertia * momentOfInertiaUnits;
    _elasticity = elasticity;
    _centerOfMass = centerOfMass;
    _sprite = sprite;
    _destroyAnimation = destroyAnimation;
    _destroySound = destroySound;
    _collisionLinePoints = LinePoints;
    _structuralIntegrity = structuralIntegrity * structuralIntegrityUnits;
    _structuralStrength = structuralStrength * structuralStrengthUnits;
    _material = &material;
    
    _maxStructuralIntegrity = _structuralIntegrity;
    _size = sprite.getTexture()->getSize();
    _sprite.setOrigin(centerOfMass);
    _velocity = sf::Vector2f(0,0);
    _rotationalVelocity = 0;
};



void SolidObject::updateCollisionData(){
    if(_collided){
        _noCollideCount=0;
        _collided=false;
    }
    else{
        ++_noCollideCount;
    }
}

void SolidObject::updatePosition(){
    _sprite.move(_velocity.x * dt, _velocity.y * dt);
    _sprite.rotate(_rotationalVelocity * dt);
}

void SolidObject::updateStatus(){
    if(getStructuralIntegrity() <= 0)
        destroy();
}