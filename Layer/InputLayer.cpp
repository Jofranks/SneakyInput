//
//  InputLayer.cpp
//  air
//
//  Created by peter on 14-10-10.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#include "InputLayer.h"


bool InputLayer::init()
{
    fireTime = 0.0f;

    this->addFireButton();
    this->addJoyStick();
    this->scheduleUpdate();
    return true;
}

void InputLayer::update(float delta)
{
    cocos2d::CCPoint velocity = joysitck->getVelocity();
    if (velocity.x != 0 || velocity.y != 0) {
        CCLOG("joyStick: [%f, %f]", velocity.x, velocity.y);
    }
    
    fireTime += delta;
    
    if (fireButton->getIsActive()) {
        CCLOG("firebutton is action %f", fireTime);
    }
}

void InputLayer::addFireButton()
{
    float buttonRadius = 80;
    cocos2d::CCSize screenSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    fireButton = new SneakyButton();
    fireButton->autorelease();
    fireButton->initWithRect(cocos2d::CCRectZero);
    fireButton->setRadius(80);
    fireButton->setIsToggleable(false);
    fireButton->setIsHoldable(true);
    
    
    cocos2d::CCSprite* idle = cocos2d::CCSprite::create("b1.png");
    cocos2d::CCSprite* press = cocos2d::CCSprite::create("b2.png");
    cocos2d::CCSprite* active = cocos2d::CCSprite::create("b2.png");
    
    SneakyButtonSkinnedBase* skinFireButton = new SneakyButtonSkinnedBase();
    skinFireButton->autorelease();
    skinFireButton->init();
    skinFireButton->setButton(fireButton);
    skinFireButton->setDefaultSprite(idle);
    skinFireButton->setPressSprite(press);
    skinFireButton->setActivatedSprite(active);
    skinFireButton->setPosition(ccp(screenSize.width - buttonRadius, buttonRadius));
    this->addChild(skinFireButton);
    
}



void InputLayer::addJoyStick()
{
    float stickRadius = 90;
    
    joysitck = new SneakyJoystick();
    joysitck->initWithRect(cocos2d::CCRectMake(0, 0, stickRadius, stickRadius));
    joysitck->setAutoCenter(true);
    joysitck->setHasDeadzone(true);
    joysitck->setDeadRadius(10);
    
    //
    cocos2d::CCSprite* back = cocos2d::CCSprite::create("j1.png");
    cocos2d::CCSprite* thumb = cocos2d::CCSprite::create("j2.png");
    
    SneakyJoystickSkinnedBase* skinStick = new SneakyJoystickSkinnedBase();
    skinStick->init();
    skinStick->setJoystick(joysitck);
    skinStick->setBackgroundSprite(back);
    skinStick->setThumbSprite(thumb);
    skinStick->setPosition(ccp(stickRadius * 1.5f, stickRadius * 1.5f));
    this->addChild(skinStick);
}
