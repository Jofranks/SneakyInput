//
//  SneakyJoyStick.h
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#ifndef __SneakyJoyStick__
#define __SneakyJoyStick__

#include "SneakyMacros.h"

class SneakyJoystick : public CCNode, public CCTargetedTouchDelegate
{
public:
    virtual ~SneakyJoystick();
    
    /**
     *  根据矩形初始化
     *
     *  @param rect 矩形
     *
     *  @return 初始化是否成功
     */
    bool initWithRect(CCRect rect);
    /**
     *  完全进入场景后开始执行
     */
    virtual void onEnterTransitionDidFinish();
    
	/**
	 *  退出当前layer时调用
	 */
	virtual void onExit();
    
    /**
     *  触摸开始
     *
     *  @return 返回false后面三个参数不需要了
     */
    virtual bool ccTouchBegan(CCTouch *touch, CCEvent *event);
    
	/**
	 *  移动
	 *
	 */
	virtual void ccTouchMoved(CCTouch *touch, CCEvent *event);
    
	/**
	 *  结束
	 *
	 */
	virtual void ccTouchEnded(CCTouch *touch, CCEvent *event);
    
    /**
     *  中途取消
     *
     */
    virtual void ccTouchCancelled(CCTouch *touch, CCEvent *event);
    
    /**
     *  setter函数
     *
     *  @param b 参数
     */
    void setIsDPad(bool b);
    void setJoystickRadius(float r);
    void setThumbRadius(float r);
    void setDeadRadius(float r);    

private:
    /**
     *  更新
     *
     *  @param point 
     */
    void updateVelocity(CCPoint point);
    
    
    
    CC_SYNTHESIZE_READONLY(CCPoint, stickPosition, StickPosition);
	CC_SYNTHESIZE_READONLY(float, degrees, Degrees);
	CC_SYNTHESIZE_READONLY(CCPoint, velocity, Velocity);
	CC_SYNTHESIZE(bool, autoCenter, AutoCenter);
	CC_SYNTHESIZE_READONLY(bool, isDPad, IsDPad);
	CC_SYNTHESIZE(bool, hasDeadzone, HasDeadzone);//Turns Deadzone on/off for joystick, always YES if ifDpad == YES
	CC_SYNTHESIZE(int, numberOfDirections, NumberOfDirections);//Used only when isDpad == YES
    
    
    CC_SYNTHESIZE_READONLY(float, joystickRadius, JoystickRadius);
	CC_SYNTHESIZE_READONLY(float, thumbRadius, ThumbRadius);
	CC_SYNTHESIZE_READONLY(float, deadRadius, DeadRadius); //Size of deadzone in joystick (how far you must move before input starts). Automatically set if isDpad == YES
	
	//Optimizations (keep Squared values of all radii for faster calculations) (updated internally when changing joy/thumb radii)
	float joystickRadiusSq;
	float thumbRadiusSq;
	float deadRadiusSq;
};

#endif /* defined(__SneakyJoyStick__) */
