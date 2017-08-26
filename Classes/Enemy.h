#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Enemy :public Character {
	int attacktimes;
public:
	/*FiniteTimeAction*left1;//向左走的动画
	FiniteTimeAction*right1;//向右走的动画
	FiniteTimeAction*ahead;//向前走的动画
	FiniteTimeAction*back;//向后走的动画*/
	Enemy();
	double getDistance();
	void move();
	void changeDirection(int);
};
#endif

