//
//  SneakyJoyStick.cpp
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#include "SneakyJoystick.h"

SneakyJoystick::~SneakyJoystick()
{
    
}

bool SneakyJoystick::initWithRect(CCRect rect)
{
    bool bRet = CCNode::init();
    if (bRet) {
        stickPosition           = CCPointZero;
		degrees                 = 0.0f;
		velocity                = CCPointZero;
		autoCenter              = true;
		isDPad                  = false;
		hasDeadzone             = false;
		numberOfDirections      = 4;
		
		this->joystickRadius    = rect.size.width/2;
		this->thumbRadius       = 32.0f;
		this->deadRadius        = 0.0f;
		
		//Cocos node stuff
        setPosition(rect.origin);
    }
    return bRet;
}


void SneakyJoystick::onEnterTransitionDidFinish()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}


void SneakyJoystick::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}


void SneakyJoystick::setIsDPad(bool b)
{
    isDPad = b;
	if(isDPad) {
		hasDeadzone         = true;
		this->deadRadius    = 10.0f;
	}
}

void SneakyJoystick::setJoystickRadius(float r)
{
    joystickRadius      = r;
	joystickRadiusSq    = r * r;
}

void SneakyJoystick::setThumbRadius(float r)
{
    thumbRadius         = r;
	thumbRadiusSq       = r * r;
}

void SneakyJoystick::setDeadRadius(float r)
{
    deadRadius          = r;
	deadRadiusSq        = r * r;
}

#pragma mark touch delegate
bool SneakyJoystick::ccTouchBegan(CCTouch *touch, CCEvent *event)
{
    CCPoint location = touch->getLocation();
	location = this->convertToNodeSpace(location);
	//Do a fast rect check before doing a circle hit check:
	if(location.x < -joystickRadius || location.x > joystickRadius || location.y < -joystickRadius || location.y > joystickRadius) {
		return false;
	} else {
		float dSq = location.x*location.x + location.y*location.y;
		if(joystickRadiusSq > dSq) {
            this->updateVelocity(location);
			return true;
		}
	}
	return false;
}

void SneakyJoystick::ccTouchMoved(CCTouch *touch, CCEvent *event)
{
    CCPoint location = touch->getLocation();
	location = this->convertToNodeSpace(location);
    this->updateVelocity(location);
}

void SneakyJoystick::ccTouchEnded(CCTouch *touch, CCEvent *event)
{
    CCPoint location = CCPointZero;
	if(!autoCenter){
		CCPoint location = touch->getLocation();
        location = this->convertToNodeSpace(location);
	}
    this->updateVelocity(location);
}

void SneakyJoystick::ccTouchCancelled(CCTouch *touch, CCEvent *event)
{
    this->ccTouchEnded(touch, event);
}

#pragma mark private
void SneakyJoystick::updateVelocity(CCPoint point)
{
    // Calculate distance and angle from the center.
	float dx    = point.x;
	float dy    = point.y;
	float dSq   = dx * dx + dy * dy;
	
	if(dSq <= deadRadiusSq) {
		velocity        = CCPointZero;
		degrees         = 0.0f;
		stickPosition   = point;
		return;
	}
    
	float angle = atan2f(dy, dx); // in radians
	if(angle < 0) {
		angle += SJ_PI_X_2;
	}
	
	if(isDPad) {
		float anglePerSector = 360.0f / numberOfDirections * SJ_DEG2RAD;
		angle = roundf(angle / anglePerSector) * anglePerSector;
	}
	
	float cosAngle = cosf(angle);
	float sinAngle = sinf(angle);
	
	// NOTE: Velocity goes from -1.0 to 1.0.
	if (dSq > joystickRadiusSq || isDPad) {
		dx = cosAngle * joystickRadius;
		dy = sinAngle * joystickRadius;
	}
	
	velocity = CCPointMake(dx / joystickRadius, dy / joystickRadius);
	degrees = angle * SJ_RAD2DEG;
	
	// Update the thumb's position
	stickPosition = ccp(dx, dy);
}