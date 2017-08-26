#include "cocos2d.h"
#include"Character.h"
using namespace cocos2d;
bool Character::getAttacked(int num) {
	if (blood - num < 0) {
		blood = 0;
		return true;
	}
	else
		blood -= num;
	return false;//
}
void Character::addblood(int num) {
	if (blood + num < bloodlimit)
		this->blood += num;
	else
		blood = bloodlimit;
}
void Character::changeDirection(int direction) {
	this->direction = direction;
}
void Character::changeAttackValue(int value) {
	attackvalue = value;
}
Character::Character(int kind) {
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (kind == 0)//
	{
		attackDistance = 15;
		blood = 15;
		bloodlimit = 15;
		attackvalue = 2;
		direction = 0;//
		this->setPosition(Vec2(origin.x, origin.y));
	}
	else if (kind == 1)//
	{
		attackDistance = 10;
		blood = 4;
		bloodlimit = 4;
		attackvalue = 1;
		direction = 0;//
		this->setPosition(Vec2(origin.x, origin.y));
	}
	else if (kind == 2) {
		direction = 0;
		this->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+ visibleSize.width / 2));
	}
}
int Character::getDirection() {
	return direction;
}
int Character::getblood() {
	return blood;
}
int Character::getAttackValue() {
	return attackvalue;
}
int Character::getAttackDistance() {
	return attackDistance;
}
