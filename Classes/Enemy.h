#ifndef __ENEMY_H__
#define __ENEMY_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Enemy :public Character {
	int attacktimes;
public:
	
	Enemy();
	double getDistance();
	void move();
	void changeDirection(int);
};
#endif

