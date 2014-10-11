//
//  SneakyJoystickSkinnedBase.h
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#ifndef __SneakyJoystickSkinnedBase__
#define __SneakyJoystickSkinnedBase__

#include "SneakyJoystick.h"

class SneakyJoystickSkinnedBase : public CCLayer
{
public:
    CREATE_FUNC(SneakyJoystickSkinnedBase);
    
    virtual ~SneakyJoystickSkinnedBase();
    
    /**
     *  初始化
     *
     *  @return 初始化是否成功
     */
    bool init();
    
	/**
	 *  setter 方法
	 *
	 *  @param s 参数
	 */
	void setContentSize(cocos2d::CCSize s);
	void setBackgroundSprite(cocos2d::CCSprite *aSprite);
	void setThumbSprite(cocos2d::CCSprite *aSprite);
	void setJoystick(SneakyJoystick *aJoystick);
private:
    /**
     *  更新位置
     *
     *  @param delta 时间参数
     */
    void updatePositions(cocos2d::CCTime delta);
    
    
    CC_SYNTHESIZE_READONLY(cocos2d::CCSprite *, backgroundSprite, BackgroundSprite);
	CC_SYNTHESIZE_READONLY(cocos2d::CCSprite *, thumbSprite, ThumbSprite);
	CC_SYNTHESIZE_READONLY(SneakyJoystick *, joystick, Joystick);

};

#endif /* defined(__SneakyJoystickSkinnedBase__) */
