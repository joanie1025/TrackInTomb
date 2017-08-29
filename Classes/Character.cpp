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
    return false;//»ÀŒÔ «∑ÒÀ¿Õˆ
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
    if (kind == 0)//¥¥Ω®∂‘œÛŒ™÷˜Ω«
    {
        mySprite = Sprite::create("res/ahead_h/1.png");
        attackDistance = 15;
        blood = 15;
        bloodlimit = 15;
        attackvalue = 2;
        direction = 0;//ƒ¨»œ≥Ø”“
        mySprite->setPosition(Vec2(origin.x, origin.y));
    }
    else if (kind == 1)//¥¥Ω®∂‘œÛŒ™µ–»À
    {   mySprite = cocos2d::Sprite::create("res/Up/1.png");
        attackDistance = 10;
        blood = 4;
        bloodlimit = 4;
        attackvalue = 1;
        direction = 0;//ƒ¨»œ≥Ø”“
        mySprite->setPosition(Vec2(origin.x, origin.y));
    }
    else if (kind == 2) {
        mySprite = cocos2d::Sprite::create("res/back_f/1.png");
        direction = 0;
        mySprite->setPosition(Vec2(origin.x+visibleSize.width/2, origin.y+ visibleSize.width / 2));
    }
    else if (kind == 3) {
        mySprite = cocos2d::Sprite::create("res/back_b/1.png");
        attackDistance = 10;
        blood = 4;
        bloodlimit = 4;
        attackvalue = 2;
        direction = 0;//ƒ¨»œ≥Ø”“
        mySprite->setPosition(Vec2(origin.x, origin.y));
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
void Character::setPosition(const Vec2& position) {
    mySprite->setPosition(position);
}
const Vec2& Character::getPosition() {
    return mySprite->getPosition();
}
void Character::setTexture(const std::string& filename) {
    mySprite->setTexture(filename);
}
const Size& Character::getContentSize() {
    return mySprite->getContentSize();
}
const Action* Character::runAction(Action* action) {
    return mySprite->runAction(action);
}
void Character::stopActionByTag(int tag) {
    mySprite->stopActionByTag(tag);
}
Character::~Character() {
}
