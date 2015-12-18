//
//  ObjectCreation.h
//  SpaceGame
//
//  Created by Jonathan Wood on 13/09/2014.
//  Copyright (c) 2014 Jonathan Wood. All rights reserved.
//

#ifndef SpaceGame_ObjectCreation_h
#define SpaceGame_ObjectCreation_h

#include "PlayerSpaceCraft.h"
#include "FollowCam.h"
#include "OblistHandler.h"
#include "BotPilot.h"
#include "AsteroidField.h"

//arial font
sf::Font arial;
arial.loadFromFile("Assets/Arial.ttf");

//FASE
sf::Texture FASEsheet;
if(!FASEsheet.loadFromFile("Assets/FASEsheet.png"))
    std::cout<<"COULDNT FIND FASEsheet  PNG"<<std::endl;
DestroyEffect FASE(3, 4, FASEsheet, 0.4);

//Materials
sf::SoundBuffer steelSoundBuffer;
if(!steelSoundBuffer.loadFromFile("Assets/steelSound.ogg"))
    std::cout<<"Error loading steelSound.ogg"<<std::endl;
sf::Sound steelSound;
steelSound.setBuffer(steelSoundBuffer);
steelSound.setMinDistance(64);
steelSound.setAttenuation(0.5);
Material steel(steelSound);
sf::SoundBuffer rockSoundBuffer;
if(!rockSoundBuffer.loadFromFile("Assets/rockSound.ogg"))
std::cout<<"Error loading rockSound.ogg"<<std::endl;
sf::Sound rockSound;
rockSound.setBuffer(rockSoundBuffer);
Material rock(rockSound);

//Slug spark
sf::Texture slugSparkSheet;
if(!slugSparkSheet.loadFromFile("Assets/slugSparkSheet.png"))
    std::cout<<"ERROR LOADING slugSparkSheet.png"<<std::endl;
DestroyEffect slugSpark(3, 2,slugSparkSheet, 1.0/60.0);

//railGun1 creation
sf::Texture railGun1Texture;
if (!railGun1Texture.loadFromFile("Assets/RailGun1.png"))
std::cout<<"ERROR!! Could not load file RailGun1.png"<<std::endl;
railGun1Texture.setSmooth(true);
sf::Sprite railGun1Sprite;
railGun1Sprite.setTexture(railGun1Texture);
sf::SoundBuffer bangBuffer;
if(!bangBuffer.loadFromFile("Assets/Gunshot.ogg"))
std::cout<<"Error loading Band.ogg"<<std::endl;
sf::Sound bang;
bang.setBuffer(bangBuffer);
bang.setMinDistance(64);
bang.setAttenuation(0.5);
#define q sf::Vector2f
std::vector<sf::Vector2f> railGun1LinePoints{q(0,4), q(11, 4), q(33,6), q(33,13), q(11, 15), q(0, 15), q(0, 4)};
#undef q
RailGun railGun1("RailGun1" ,5, 5, 0.9, sf::Vector2f(20, 10) , railGun1Sprite, FASE ,railGun1LinePoints, 34, 300, sf::Vector2f(33, 9), 5000, 400, bang, steel, 0.2);
//slug1 creation
sf::Texture slug1Texture;
if (!slug1Texture.loadFromFile("Assets/slug1.png"))
std::cout<<"ERROR!! Could not load file slug1.png"<<std::endl;
slug1Texture.setSmooth(true);
sf::Sprite slug1Sprite;
slug1Sprite.setTexture(slug1Texture);
#define q sf::Vector2f
std::vector<sf::Vector2f> slug1LinePoints{q(0,0), q(5, 0), q(5, 2), q(0, 2), q(0, 0)};
#undef q
Slug slug1("slug1", 1.3, 1.1, 0.5, sf::Vector2f(2, 1), slug1Sprite, slugSpark, steelSound ,slug1LinePoints, 300, 800, steel);
railGun1.setAmmo(slug1);

//Ship1 creation
sf::Texture Ship1Texture;
if (!Ship1Texture.loadFromFile("Assets/Ship1.png"))
    std::cout<<"ERROR!! Could not load file Ship1.png"<<std::endl;
Ship1Texture.setSmooth(true);
sf::Sprite Ship1Sprite;
Ship1Sprite.setTexture(Ship1Texture);
sf::Texture Flamesheet1;
if(!Flamesheet1.loadFromFile("Assets/Flamesheet1.png"))
std::cout<<"ERROR!!!! Unable to load file Flamesheet1.png";
Flamesheet1.setSmooth(true);
sf::Sprite FlameSprite1;
FlameSprite1.setTexture(Flamesheet1);
sf::SoundBuffer FlameBuffer1;
sf::SoundBuffer nosoundbuffer;
sf::Sound nosound;
if(!nosoundbuffer.loadFromFile("Assets/nosound.ogg"))
std::cout<<"ERROR!!!!! Problem loading Flamesound1.ogg";
sf::Sound FlameSound1;
if(!FlameBuffer1.loadFromFile("Assets/Flamesound1.ogg"))
std::cout<<"ERROR!!!!! Problem loading Flamesound1.ogg";
FlameSound1.setBuffer(FlameBuffer1);
FlameSound1.setLoop(true);
FlameSound1.setVolume(40);
FlameSound1.setAttenuation(0.1);
float Ship1thrustarray[6] = {1000, 1000, 3000, 3000, 0, 0 };
sf::Sound FlameSound1array[6]={FlameSound1, FlameSound1, FlameSound1, FlameSound1, nosound, nosound};
#define q sf::Vector2f
std::vector<sf::Vector2f> Ship1LinePoints {q(20, 21), q(35, 9), q(53, 6), q(62, 2), q(75, 2), q(87, 6), q(106, 8), q(118, 15), q(126, 26), q(126, 29), q(118, 48), q(107, 55), q(85, 57), q(76, 61), q(64, 61), q(54, 57), q(36, 54), q(20,41), q(20, 21)};
#undef q
std::vector<WeaponSlot*> Ship1WeapSlots;
WeaponSlot Ship1WeapSlot1(sf::Vector2f(120, 32));   Ship1WeapSlots.push_back(&Ship1WeapSlot1);
WeaponSlot Ship1WeapSlot2(sf::Vector2f(86, 13));     Ship1WeapSlots.push_back(&Ship1WeapSlot2);
WeaponSlot Ship1WeapSlot3(sf::Vector2f(86, 51));    Ship1WeapSlots.push_back(&Ship1WeapSlot3);
PlayerSpaceCraft Ship1 ("Ship1" ,250 ,20, 0.9, sf::Vector2f(64,32) , Ship1Sprite, FASE, nosound ,Flamesheet1, Ship1LinePoints ,Ship1thrustarray,
                        FlameSound1array, Ship1WeapSlots, 16000, 700, steel);
Ship1.attachWeapon(railGun1, 0);
SolidObject::ObList.push_back(&Ship1);
Ship1.setPosition(mapSizeX/2+400, mapSizeY/2+100);

//enemyShipDestroyEffect creation
sf::Texture eShipDestroySheet;
eShipDestroySheet.loadFromFile("Assets/enemyShipDestroyEffect.png");
DestroyEffect enemyShipDestroyEffect(2, 2, eShipDestroySheet, 1.0/30.0);

//enemyShip creation
sf::Texture enemyShipTexture;
enemyShipTexture.loadFromFile("Assets/EnemyShip1.png");
enemyShipTexture.setSmooth(true);
sf::Sprite enemyShipSprite;
enemyShipSprite.setTexture(enemyShipTexture);
float enemyShipThrustArray[6] = {300, 300, 3000, 3000, 300, 300};
sf::Sound flameSound2array[6] = {FlameSound1, FlameSound1, FlameSound1, FlameSound1, FlameSound1, FlameSound1};
#define q sf::Vector2f
std::vector<sf::Vector2f> enemyShipLinePoints {q(0, 15), q(25, 0), q(90, 0), q(127, 19), q(127, 44), q(89, 63), q(25, 63), q(0, 47), q(0, 15)};
#undef q
std::vector<WeaponSlot*> enemyShipWeapSlots;
WeaponSlot enemyShipWeaponSlot1(sf::Vector2f(125, 22));         enemyShipWeapSlots.push_back(&enemyShipWeaponSlot1);
WeaponSlot enemyShipWeaponSlot2(sf::Vector2f(125, 41));          enemyShipWeapSlots.push_back(&enemyShipWeaponSlot2);
ModifiedSpaceCraft enemyShip("enemyShip" , 400, 25, 0.9, sf::Vector2f(64,32) , enemyShipSprite, enemyShipDestroyEffect, nosound ,Flamesheet1, enemyShipLinePoints,
                             enemyShipThrustArray, FlameSound1array, enemyShipWeapSlots, 20000, 700, steel);
RailGun railGun2 = railGun1;
RailGun railGun3 = railGun1;
enemyShip.attachWeapon(railGun2, 0);
enemyShip.attachWeapon(railGun3, 1);
SolidObject::ObList.push_back(&enemyShip);
enemyShip.setPosition(mapSizeX/2+800, mapSizeY/2+100);

//hostileBot creation
BotPilot hostileBot;
Bot::BotList.push_back(& hostileBot);
hostileBot.assignShip(& enemyShip);
hostileBot.setTarget(Ship1);

//rock Destroy effect creation
sf::Texture rockDestroyEffectTexture;
rockDestroyEffectTexture.loadFromFile("Assets/rockDestroyEffect.png");
DestroyEffect rockDestroyEffect(2, 2, rockDestroyEffectTexture, 1.0/20.0);
//Rock creation
sf::Texture rockTexture;
if(!rockTexture.loadFromFile("Assets/Asteroid.png"))
std::cout<<"PROBLEM!!! couldn't load Asteroid.png"<<std::endl;
rockTexture.setSmooth(true);
sf::Sprite rockSprite;
rockSprite.setTexture(rockTexture);
#define q sf::Vector2f
std::vector<sf::Vector2f> RockLinePoints {q(1, 32), q(1, 21), q(21, 2), q(44, 0), q(59, 10), q(63, 17), q(60, 47), q(46, 62), q(23, 63), q(9, 53), q(1, 32)};
#undef q
SolidObject asteroid("rock" ,192, 7.8, 0.4, sf::Vector2f(32, 32), rockSprite, rockDestroyEffect , nosound ,RockLinePoints, 6800, 130, rock);
SolidObject::ObList.push_back(&asteroid);
asteroid.setPosition(mapSizeX/2+400, mapSizeY/2+0);
asteroid.setRotationalVelocity(50);

////LongGirder creation
//sf::Texture longGirdTexture;
//if(!longGirdTexture.loadFromFile("/Users/jonathanwood/Documents/Programming/C ++/Assets/LongGirder.png"))
//std::cout<<"UH OH! PROBLEM WITH GIRDER LOADING"<<std::endl;
//longGirdTexture.setSmooth(true);
//sf::Sprite longGirdSprite;
//longGirdSprite.setTexture(longGirdTexture);
//#define q sf::Vector2f
//std::vector<sf::Vector2f> LongGirdLinePoints{q(0, 0) , q(799, 0), q(799, 19), q(0, 19)};
//#undef q
//SolidObject LongGirder("Longgrider", 1000, 1000, 0.9, 400, 10, longGirdSprite, FASE ,LongGirdLinePoints, 18000, 400);
//obList.push_back(&LongGirder);
//LongGirder.image.setPosition(mapSizeX/2, mapSizeY/2-500);
//LongGirder.rotv=40;


//DangerBox creation
sf::Texture DangerBoxTexture;
if(!DangerBoxTexture.loadFromFile("Assets/DangerBox.png"))
std::cout<<"COULDNT FIND DANGER BOX PNG";
DangerBoxTexture.setSmooth(true);
sf::Sprite DangerBoxSprite;
DangerBoxSprite.setTexture(DangerBoxTexture);
#define q sf::Vector2f
std::vector<sf::Vector2f> DangerBoxLinePoints{q(0, 0) , q(639, 0), q(639, 399), q(0, 399), q(0, 0), q(47, 48), q(593, 48), q(590, 351), q(48, 350), q(47, 48)};
#undef q
SolidObject DangerBox("DangerBox", 2000, 1400, 0.8, sf::Vector2f(320, 200), DangerBoxSprite,FASE, nosound ,DangerBoxLinePoints, 70000, 430, steel);
SolidObject::ObList.push_back(&DangerBox);
DangerBox.setPosition(mapSizeX/2-300, mapSizeY/2+00);


//Asteroid field creation
AsteroidField asteroidField(asteroid, sf::IntRect(mapSizeX/2-2000, mapSizeY/2-2000, 5000, 5000));

#endif
