//
//  SneakyButtonSkinnedBase.h
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#ifndef __SneakyButtonSkinnedBase__
#define __SneakyButtonSkinnedBase__

#include "SneakyButton.h"

class SneakyButtonSkinnedBase : public CCLayer
{
public:
    CREATE_FUNC(SneakyButtonSkinnedBase);
    
    virtual ~SneakyButtonSkinnedBase();
    
    /**
     *  初始化
     *
     *  @return 初始化是否成功
     */
    bool init();
    
    /**
     *  监控函数
     */
    void watchSelf();
    
    /**
     *  setter函数
     */
    void setContentSize(CCSize s);
    void setDefaultSprite(CCSprite* aSprite);
    void setActivatedSprite(CCSprite* aSprite);
    void setDisabledSprite(CCSprite* aSprite);
    void setPressSprite(CCSprite* aSprite);
    void setButton(SneakyButton* aButton);
    
private:
    CC_SYNTHESIZE_READONLY(CCSprite *, defaultSprite, DefaultSprite);
	CC_SYNTHESIZE_READONLY(CCSprite *, activatedSprite, ActivatedSprite);
	CC_SYNTHESIZE_READONLY(CCSprite *, disabledSprite, DisabledSprite);
	CC_SYNTHESIZE_READONLY(CCSprite *, pressSprite, PressSprite);
	CC_SYNTHESIZE_READONLY(SneakyButton *, button, Button);
};

#endif /* defined(__SneakyButtonSkinnedBase__) */
