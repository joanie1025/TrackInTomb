#include"Friend.h"
extern Leader* leader;
Friend::Friend() :Character(2){
}
double Friend::getDistance() {
    double distance = 0;
    distance = sqrt((leader->getPosition().x - this->getPosition().x)*(leader->getPosition().x - this->getPosition().x) +
                    (leader->getPosition().y - this->getPosition().y)*(leader->getPosition().y - this->getPosition().y)) - leader->getContentSize().width / 2 + getContentSize().width / 2;
    return distance;
}
void Friend::move() {
    double distance = getDistance();
    if (distance>30) {
        Vec2 direction = Vec2((leader->getPosition().x - this->getPosition().x) / distance * 30,
                              (leader->getPosition().y - this->getPosition().y) / distance * 30);
        float x = this->getPosition().x - leader->getPosition().x;
        float y = this->getPosition().y - leader->getPosition().y;
        float t = 0.0f;
        if (x != 0)
            t = y / x;
        if (x>0 && t<1 && t>-1) {
            /*if (right != nullptr)
             action = right;*/
            this->changeDirection(4);//记得去掉
        }
        else if (x<0 && t>-1 && t<1) {
            this->changeDirection(3);//记得去掉
        }
        else if ((x == 0 && y>0) || x>0 && t>1 || t<-1 && x<0) {
            /*if (ahead != nullptr)
             action = ahead;*/
            this->changeDirection(1);
        }
        else if (x == 0 && y<0 || x<0 && t>1 || x>0 && t<-1) {
            this->changeDirection(2);
        }
        FiniteTimeAction*ac1 = MoveBy::create(1.0f, direction);//四张图片 每两帧一张
        this->runAction(ac1);
    }
}
void Friend::changeDirection(int direction) {
    if (this->getDirection() == direction) {}
    else {
        if (direction == 3) {
            Animation * animation2 = Animation::create();
            SpriteFrame * spriteFrame5 = SpriteFrame::create("res/left_f/1.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("res/left_f/2.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("res/left_f/3.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("res/left_f/4.png", Rect(0, 0, 80, 137));
            animation2->addSpriteFrame(spriteFrame5);
            animation2->addSpriteFrame(spriteFrame6);
            animation2->addSpriteFrame(spriteFrame7);
            animation2->addSpriteFrame(spriteFrame8);
            animation2->setDelayPerUnit(0.2f);
            animation2->setRestoreOriginalFrame(true);
            Animate* action2 = Animate::create(animation2);
            FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
            Character::changeDirection(2);
            this->stopActionByTag(123);
            back->setTag(123);
            this->runAction(back);
        }
        else if (direction == 1) {
            	Animation * animation2 = Animation::create();
             SpriteFrame * spriteFrame5 = SpriteFrame::create("res/ahead_f/01.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("res/ahead_f/02.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("res/ahead_f/03.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("res/ahead_f/04.png", Rect(0, 0, 80, 137));
             animation2->addSpriteFrame(spriteFrame5);
             animation2->addSpriteFrame(spriteFrame6);
             animation2->addSpriteFrame(spriteFrame7);
             animation2->addSpriteFrame(spriteFrame8);
             animation2->setDelayPerUnit(0.2f);
             animation2->setRestoreOriginalFrame(true);
             Animate* action2 = Animate::create(animation2);
             FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
             Character::changeDirection(1);
             this->mySprite->stopAllActionsByTag(333);
             back->setTag(123);
             this->runAction(back);
        }
        else if (direction == 4) {
           Animation * animation2 = Animation::create();
             SpriteFrame * spriteFrame5 = SpriteFrame::create("res/right_f/1.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame6 = SpriteFrame::create("res/right_f/2.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame7 = SpriteFrame::create("res/right_f/3.png", Rect(0, 0, 80, 137));
             SpriteFrame * spriteFrame8 = SpriteFrame::create("res/right_f/4.png", Rect(0, 0, 80, 137));
             animation2->addSpriteFrame(spriteFrame5);
             animation2->addSpriteFrame(spriteFrame6);
             animation2->addSpriteFrame(spriteFrame7);
             animation2->addSpriteFrame(spriteFrame8);
             animation2->setDelayPerUnit(0.2f);
             animation2->setRestoreOriginalFrame(true);
             Animate* action2 = Animate::create(animation2);
             FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
             Character::changeDirection(4);
             this->mySprite->stopAllActionsByTag(333);
             back->setTag(123);
             this->runAction(back);
        }
        else if (direction == 2) {
            Animation * animation2 = Animation::create();
            SpriteFrame * spriteFrame5 = SpriteFrame::create("res/back_f/1.png", Rect(0, 0, 80, 137));
            SpriteFrame * spriteFrame6 = SpriteFrame::create("res/back_f/2.png", Rect(0, 0, 80, 137));
            SpriteFrame * spriteFrame7 = SpriteFrame::create("res/back_f/3.png", Rect(0, 0, 80, 137));
            SpriteFrame * spriteFrame8 = SpriteFrame::create("res/back_f/4.png", Rect(0, 0, 80, 137));
            animation2->addSpriteFrame(spriteFrame5);
            animation2->addSpriteFrame(spriteFrame6);
            animation2->addSpriteFrame(spriteFrame7);
            animation2->addSpriteFrame(spriteFrame8);
            animation2->setDelayPerUnit(0.2f);
            animation2->setRestoreOriginalFrame(true);
            Animate* action2 = Animate::create(animation2);
            FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
            Character::changeDirection(3);
            this->stopActionByTag(123);
            back->setTag(123);
            this->runAction(back);
        }
    }
}
