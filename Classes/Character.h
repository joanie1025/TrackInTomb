#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "cocos2d.h"
using namespace cocos2d;
class Character :public Sprite {
	double attackDistance;
	double getAttackDistance;
	int blood;
	int bloodlimit;
	int attackvalue;
	int direction;//1为上，2为下，3为左，4为右
public:
	Character();
	bool getAttacked(int);
	void addblood(int);
	//void setPosition(Vec2&);
	void changeDirection(int);
	int getDirection();
	void changeAttackValue(int);
};
#endif

