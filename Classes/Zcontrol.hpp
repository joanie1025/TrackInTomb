//
//  Zcontrol.hpp
//  trackintomb
//
//  Created by 蒋颖 on 2017/8/25.
//
//

#ifndef Zcontrol_hpp
#define Zcontrol_hpp

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class Zcontrol{
public:
    Scene * loadScene;
    Scene * infoScene;
    Scene * startScene;
    Scene * gameFirst;

    
    void createLoadScene();
    
    void goInfoScene();
    void goStartScene();
    void goGameFirst();
};


#endif /* Zcontrol_hpp */
