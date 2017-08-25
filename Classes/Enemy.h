#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Enemy :public Character {
	int attacktimes;
public:
	Animation*left;//向左走的动画
	Animation*right;//向右走的动画
	Animation*ahead;//向前走的动画
	Animation*back;//向后走的动画
	Enemy();
	double getDistance();
	void move();
};
#endif

