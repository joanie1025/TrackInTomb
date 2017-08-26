#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "cocos2d.h"
using namespace cocos2d;
class Character :public Sprite {
	int attackDistance;
	int blood;
	int bloodlimit;
	int attackvalue;
	int direction;
public:
	Character(int);
	int getblood();
	bool getAttacked(int);
	void addblood(int);
	int getAttackValue();
	//void setPosition(Vec2&);
	void changeDirection(int);
	int getDirection();
	void changeAttackValue(int);
	int getAttackDistance();
};
#endif

