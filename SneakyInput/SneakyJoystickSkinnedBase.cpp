//
//  SneakyJoystickSkinnedBase.cpp
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#include "SneakyJoystickSkinnedBase.h"

SneakyJoystickSkinnedBase::~SneakyJoystickSkinnedBase()
{
    if (backgroundSprite)
	{
		backgroundSprite->release();
		backgroundSprite = NULL;
	}
	if (thumbSprite)
	{
		thumbSprite->release();
		thumbSprite = NULL;
	}
    
	if (joystick)
	{
		joystick->release();
		joystick = NULL;
	}
}

bool SneakyJoystickSkinnedBase::init()
{
    bool bRet = CCLayer::init();
    if (bRet) {
        this->backgroundSprite  = NULL;
		this->thumbSprite       = NULL;
		this->joystick          = NULL;
		
        this->schedule(schedule_selector(SneakyJoystickSkinnedBase::updatePositions));
    }
    return bRet;
}

void SneakyJoystickSkinnedBase::setContentSize(cocos2d::CCSize s)
{
    CCLayer::setContentSize(s);
	backgroundSprite->setContentSize(s);
	joystick->setJoystickRadius(s.width / 2);
}

void SneakyJoystickSkinnedBase::setBackgroundSprite(cocos2d::CCSprite *aSprite)
{
    if(backgroundSprite) {
		if(backgroundSprite->getParent())
        {
            backgroundSprite->getParent()->removeChild(backgroundSprite, true);
        }
	}
	backgroundSprite = aSprite;
	if(aSprite) {
        this->addChild(backgroundSprite, 0);
        this->setContentSize(backgroundSprite->getContentSize());
	}
}

void SneakyJoystickSkinnedBase::setThumbSprite(cocos2d::CCSprite *aSprite)
{
    if(thumbSprite){
		if(thumbSprite->getParent()) {
            thumbSprite->getParent()->removeChild(thumbSprite, true);
        }
	}
	thumbSprite = aSprite;
	if(aSprite){
        this->addChild(thumbSprite, 1);
        joystick->setThumbRadius(thumbSprite->getContentSize().width / 2);
	}
}

void SneakyJoystickSkinnedBase::setJoystick(SneakyJoystick *aJoystick)
{
    if(joystick){
		if(joystick->getParent()) {
            joystick->getParent()->removeChild(joystick, true);
        }
	}
	joystick = aJoystick;
	if(aJoystick) {
        this->addChild(joystick, 2);
		if(thumbSprite) {
            joystick->setThumbRadius(thumbSprite->getContentSize().width / 2);
        } else {
            joystick->setThumbRadius(0);
        }
		if(backgroundSprite) {
            joystick->setJoystickRadius(backgroundSprite->getContentSize().width / 2);
        }
	}
}


#pragma mark private
void SneakyJoystickSkinnedBase::updatePositions(cocos2d::CCTime delta)
{
    if(joystick && thumbSprite) {
        thumbSprite->setPosition(joystick->getStickPosition());
    }
}