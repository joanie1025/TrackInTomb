#ifndef __FRIEND_H__
#define __FRIEND_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Friend :public Character {
public:
    Friend();
    double getDistance();
    void move();
    void changeDirection(int direction);
};
#endif


