//
//  SneakyButton.h
//  air
//
//  Created by peter on 14-10-11.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#ifndef __SneakyButton__
#define __SneakyButton__

#include "SneakyMacros.h"

class SneakyButton : public CCNode, public CCTargetedTouchDelegate
{
public:
    virtual ~SneakyButton();
    
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
    
    bool initWithRect(CCRect rect);
    
	void limiter(float delta);
    
	/**
	 *  设置半径
	 *
	 *  @param r 半径参数
	 */
	void setRadius(float r);
    
    
private:
    CCPoint center;
	
	CC_SYNTHESIZE_READONLY(float, radius, Radius);
	float radiusSq;
	
	CCRect bounds;
	CC_SYNTHESIZE_READONLY(bool, active, IsActive);
    CC_SYNTHESIZE(bool, status, Status);
	CC_SYNTHESIZE_READONLY(bool, value, Value);
	CC_SYNTHESIZE(bool, isHoldable, IsHoldable);
	CC_SYNTHESIZE(bool, isToggleable, IsToggleable);
	CC_SYNTHESIZE(float, rateLimit, RateLimit);
};


#endif /* defined(__SneakyButton__) */
