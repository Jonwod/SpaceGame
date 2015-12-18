#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "AsteroidField.h"
#include "BotPilot.h"
#include "BotHandler.h"
#include "VisualEffectHandler.h"
#include "FollowCam.h"
#include "OblistHandler.h"
#include "Attachment.h"
#include "SpaceGameHUD.h"
#include "CircleCollisions.h"
#define PI 3.14159265

sf::Clock frameclock;
double ftime=0.00001;

sf::Vector2i screenSize = sf::Vector2i(1800, 1000);
float offX=0;
float offY=0;

int main()
{
    
    sf::RenderWindow gamewindow(sf::VideoMode(screenSize.x, screenSize.y), "SFMLgame");
    gamewindow.setKeyRepeatEnabled(false);
    
    SolidObject::targetWindow = &gamewindow;
    
    sf::Texture BackgroundTexture;
    BackgroundTexture.setRepeated(true);
    sf::Sprite BackgroundSprite;
    if (!BackgroundTexture.loadFromFile("Assets/Spacebackground.png"))
        std::cout<<"ERROR!!! Failed to load file Spacebackground.png";
    BackgroundSprite.setTexture(BackgroundTexture);
    BackgroundSprite.setColor(sf::Color(255, 255, 255, 255));
    unsigned int mapSizeX=1000000;
    unsigned int mapSizeY=1000000;
    BackgroundSprite.setTextureRect(sf::IntRect(0,0, mapSizeX, mapSizeY));
    BackgroundSprite.setPosition(sf::Vector2f(0, 0));
    
#include "ObjectCreation.h"
    
    //HUD
    SpaceGameHUD hud(Ship1);
    
    
    sf::View MainView;
    MainView.reset(sf::FloatRect(0, 0, screenSize.x, screenSize.y));
    MainView.setViewport(sf::FloatRect(0,0 ,1.0f, 1.0f));
    sf::Vector2f campos(0,0);
    campos=Ship1.getPosition()-sf::Vector2f(screenSize.x/2, screenSize.y/2);
    MainView.reset(sf::FloatRect(campos.x,campos.y,screenSize.x, screenSize.y));
    gamewindow.setFramerateLimit(60);
    MainView.zoom(1);
    

    while (gamewindow.isOpen())
    {

        ftime=frameclock.restart().asSeconds();
        
        gamewindow.draw(BackgroundSprite);
        
        sf::Event event;
        while (gamewindow.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    gamewindow.close();
                    break;
            }
        }
        
        
        collisionHandler();
        if(!Ship1.isDestroyed())
            Ship1.getInput();
        Ship1.update();
        if(Ship1.isDestroyed())
        {
            sf::Text DeathMsg("You Died", arial, 72);
            DeathMsg.setColor(sf::Color(147, 23, 23, 198));
            DeathMsg.setPosition(Ship1.getPosition());
            gamewindow.draw(DeathMsg);
        }
        
        //teststart


        if(Bot::BotList.size() > 0)
            BotHandler();
        for(auto i=SolidObject::ObList.begin()+1 ; i!=SolidObject::ObList.end() ;)
        {
            if((*i)->isDestroyed()==false)
            {
                (*i)->update();
                i++;
            }
            else if((*i)->isDestroyed()==true)
            {
                i=SolidObject::ObList.erase(i);
            }
        }
        if(VisualEffect::VEffectList.size()>0)
            visualEffectHandler();
        cameraUpdate(screenSize,MainView,  Ship1);
        hud.update(MainView, screenSize, Ship1);
        gamewindow.display();
      //  gamewindow.clear();
    }
    return 0;
}