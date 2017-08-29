#ifndef __CHARACTER_H__
#define __CHARACTER_H__
#include "cocos2d.h"
using namespace cocos2d;
class Character  {
public:
    cocos2d::Sprite* mySprite;
private:
    int attackDistance;
    int blood;
    int bloodlimit;
    int attackvalue;
    int direction;//1Œ™…œ£¨2Œ™œ¬£¨3Œ™◊Û£¨4Œ™”“
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
    void setPosition(const Vec2&);
    const Vec2& getPosition();
    void setTexture(const std::string& filname);
    const Size& getContentSize();
    const Action* runAction(Action*);
    void stopActionByTag(int tag);
    ~Character();
};
#endif

