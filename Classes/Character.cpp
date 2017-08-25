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
	return false;//人物是否死亡
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
Character::Character() {
	attackDistance = 10;
	getAttackDistance = 5;
	blood = 10;
	bloodlimit = 10;
	attackvalue = 1;
	direction = 0;//默认朝右
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->setPosition(Vec2(origin.x, origin.y));
}
int Character::getDirection() {
	return direction;
}