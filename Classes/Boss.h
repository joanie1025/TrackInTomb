#ifndef BOSS_H__
#define BOSS_H__
#include"Character.h"
#include"cocos2d.h"
#include"Leader.h"
using namespace cocos2d;
class Boss :public Character {
	int attacktimes;
public:
	Boss();
	double getDistance();
	void move();
	void changeDirection(int);
};
#endif
