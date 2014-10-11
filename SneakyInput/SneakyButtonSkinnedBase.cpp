//
//  SneakyButtonSkinnedBase.cpp
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#include "SneakyButtonSkinnedBase.h"

SneakyButtonSkinnedBase::~SneakyButtonSkinnedBase()
{
    if (defaultSprite)
	{
		defaultSprite->release();
		defaultSprite = NULL;
	}
	if (activatedSprite)
	{
		activatedSprite->release();
		activatedSprite = NULL;
	}
	if (disabledSprite)
	{
		disabledSprite->release();
		disabledSprite = NULL;
	}
	if (pressSprite)
	{
		pressSprite->release();
		pressSprite = NULL;
	}
	if (button)
	{
		button->release();
		button = NULL;
	}
}

bool SneakyButtonSkinnedBase::init()
{
    bool bRet = CCLayer::init();
    if (bRet) {
        this->defaultSprite     = NULL;
		this->activatedSprite   = NULL;
		this->disabledSprite    = NULL;
		this->pressSprite       = NULL;
		this->button            = NULL;
		
        this->schedule(schedule_selector(SneakyButtonSkinnedBase::watchSelf));
    }
    return bRet;
}

void SneakyButtonSkinnedBase::watchSelf()
{
    if (!this->button->getStatus()){
		if(disabledSprite){
			disabledSprite->setVisible(true);
		}
		else {
			disabledSprite->setVisible(false);
		}
	}
	else {
		if(!this->button->getIsActive()) {
			pressSprite->setVisible(false);
			if(this->button->getValue() == 0) {
				activatedSprite->setVisible(false);
				if(defaultSprite) {
					defaultSprite->setVisible(true);
				}
			}
			else {
				activatedSprite->setVisible(true);
			}
		} else {
			defaultSprite->setVisible(false);
			if(pressSprite) {
				pressSprite->setVisible(true);
			}
		}
	}
}

void SneakyButtonSkinnedBase::setContentSize(CCSize s)
{
    CCLayer::setContentSize(s);
    defaultSprite->setContentSize(s);
    button->setRadius(s.width / 2);
}

void SneakyButtonSkinnedBase::setDefaultSprite(CCSprite* aSprite)
{
    if(defaultSprite) {
		if(defaultSprite->getParent()) {
            defaultSprite->getParent()->removeChild(defaultSprite, true);
        }
	}
	defaultSprite = aSprite;
	if(aSprite) {
        this->addChild(defaultSprite, 0);
        this->setContentSize(defaultSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setActivatedSprite(CCSprite* aSprite)
{
    if(activatedSprite) {
		if(activatedSprite->getParent()) {
            activatedSprite->getParent()->removeChild(activatedSprite, true);
        }
	}
	activatedSprite = aSprite;
	if(aSprite){
        this->addChild(activatedSprite, 1);
        this->setContentSize(activatedSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setDisabledSprite(CCSprite* aSprite)
{
    if(disabledSprite) {
		if(disabledSprite->getParent()) {
            disabledSprite->getParent()->removeChild(disabledSprite, true);
        }
	}
	disabledSprite = aSprite;
	if(aSprite) {
        this->addChild(disabledSprite, 2);
        this->setContentSize(disabledSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setPressSprite(CCSprite* aSprite)
{
    if(pressSprite) {
		if(pressSprite->getParent()) {
            pressSprite->getParent()->removeChild(pressSprite, true);
        }
	}
	pressSprite = aSprite;
	if(aSprite) {
        this->addChild(pressSprite, 3);
        this->setContentSize(pressSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setButton(SneakyButton* aButton)
{
    if(button) {
		if(button->getParent()) {
            button->getParent()->removeChild(button, true);
        }
	}
	button = aButton;
	if(aButton) {
        this->addChild(button, 4);
		
		if(defaultSprite) {
            button->setRadius(defaultSprite->getContentSize().width / 2);
        }
	}
}