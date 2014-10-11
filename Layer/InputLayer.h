//
//  InputLayer.h
//  air
//
//  Created by peter on 14-10-10.
//  Copyright (c) 2014年 qiuyang. All rights reserved.
//

#ifndef __air__InputLayer__
#define __air__InputLayer__

#include "cocos2d.h"
#include "SneakyButton.h"
#include "SneakyButtonSkinnedBase.h"
#include "SneakyJoystick.h"
#include "SneakyJoystickSkinnedBase.h"

class InputLayer: public cocos2d::CCLayer {
public:
    virtual bool init();
    
    virtual void update(float delta);
    
    void addFireButton();
    void addJoyStick();
    
    CREATE_FUNC(InputLayer);
private:
    SneakyButton*       fireButton;
    SneakyJoystick*     joysitck;
    float               fireTime;
};


#endif /* defined(__air__InputLayer__) */
