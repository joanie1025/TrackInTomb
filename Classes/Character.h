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
	int direction;//1Ϊ�ϣ�2Ϊ�£�3Ϊ��4Ϊ��
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

