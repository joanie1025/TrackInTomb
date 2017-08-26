#include"Enemy.h"
#include<cmath>
//����1Ϊ�ϣ�2Ϊ�£�3Ϊ��4Ϊ��
extern Leader*leader;//leaderΪȫ�ֱ������ɿ��ļ�
Enemy::Enemy() :Character(1){
	/*left1=nullptr;//�����ߵĶ���(Animation����)
	right = nullptr;//�����ߵĶ���
    ahead = nullptr;//��ǰ�ߵĶ���
	back = nullptr;//����ߵĶ���*/
//     *****************************************
/*	Animation * animation = Animation::create();
	SpriteFrame * spriteFrame1 = SpriteFrame::create("1.png",Rect(0,0,56,160));
	SpriteFrame * spriteFrame2 = SpriteFrame::create("2.png", Rect(0, 0, 56, 160));
	SpriteFrame * spriteFrame3 = SpriteFrame::create("3.png", Rect(0, 0, 56, 160));
	SpriteFrame * spriteFrame4 = SpriteFrame::create("4.png", Rect(0, 0, 56,160));
		animation->addSpriteFrame(spriteFrame1);
		animation->addSpriteFrame(spriteFrame2);
		animation->addSpriteFrame(spriteFrame3);
		animation->addSpriteFrame(spriteFrame4);
        animation->setDelayPerUnit(0.1f);
	    animation->setRestoreOriginalFrame(true);
		Animate* action = Animate::create(animation);
		ahead = (FiniteTimeAction*)(RepeatForever::create(action));
		ahead->setTag(123);
		this->runAction(ahead);
		this->stopActionByTag(123);
		this->runAction(ahead);*/
		//****************************************************************************************
	    Animation * animation2 = Animation::create();
		SpriteFrame * spriteFrame5 = SpriteFrame::create("res/Up/1.png", Rect(0, 0, 50, 120));
		SpriteFrame * spriteFrame6 = SpriteFrame::create("res/Up/2.png", Rect(0, 0, 50, 120));
		SpriteFrame * spriteFrame7 = SpriteFrame::create("res/Up/3.png", Rect(0, 0, 50, 120));
		SpriteFrame * spriteFrame8 = SpriteFrame::create("res/Up/4.png", Rect(0, 0, 50, 120));
		animation2->addSpriteFrame(spriteFrame5);
		animation2->addSpriteFrame(spriteFrame6);
		animation2->addSpriteFrame(spriteFrame7);
		animation2->addSpriteFrame(spriteFrame8);
		animation2->setDelayPerUnit(0.1f);
		animation2->setRestoreOriginalFrame(true);
		Animate* action2 = Animate::create(animation2);
		FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
		back->setTag(123);
		this->runAction(back);
		/*Animation * animation3 = Animation::create();
		left1 = Animate::create(animation3);
		Animation * animation4 = Animation::create();
		left1 = Animate::create(animation4);
	    ahead = animation;
	    left = animation;
	    right = animation;
	    back = animation;*/
		/*Animate* action = Animate::create(ahead);
	    FiniteTimeAction *move = (FiniteTimeAction*)(RepeatForever::create(action));
		this->runAction(move);*/
				  // **************************
	attacktimes = 2;//��GameScene1�����޸ļ�ʱ�����
}
double Enemy::getDistance() {
	double distance = 0;
	distance = sqrt((leader->getPosition().x - this->getPosition().x)*(leader->getPosition().x - this->getPosition().x) +
		(leader->getPosition().y - this->getPosition().y)*(leader->getPosition().y - this->getPosition().y))-leader->getContentSize().width / 2 - getContentSize().width / 2;
	return distance;
}
void Enemy::move() {
	double distance = this->getDistance();
	if (distance>10) {
		Vec2 direction = Vec2((leader->getPosition().x - this->getPosition().x) / distance*3 ,
			(leader->getPosition().y - this->getPosition().y) / distance*3 );
		float x = this->getPosition().x - leader->getPosition().x;
		float y = this->getPosition().y - leader->getPosition().y;
		float t =0.0f;
		if(x!=0)
		t = y / x;
		log("%.2f",t);
		log("%.2f", x);
		//Animation*action = nullptr;
		//log("%.2f", test);
	   if (x>0 && t<1 && t>-1) {
			/*if (right != nullptr)
			action = right;*/
			this->changeDirection(4);//�ǵ�ȥ��
		}
		else if (x<0 && t>-1 && t<1) {
			this->changeDirection(3);//�ǵ�ȥ��
		}
		else if ((x==0&&y>0)||x>0 &&t>1||t<-1&&x<0) {
			/*if (ahead != nullptr)
				action = ahead;*/
			this->changeDirection(1);
		}
		else if (x==0&&y<0||x<0&&t>1||x>0&&t<-1) {
			this->changeDirection(2);
		}
		FiniteTimeAction*ac1 = MoveBy::create(0.4f, direction);//����ͼƬ ÿ��֡һ��
			this->runAction(ac1);
	}
    if(distance<(leader->getAttackDistance())&&(leader->attackdeter)==true) {
    		this->getAttacked(leader->getAttackValue());//���Ǽ�����Ѫ
	}
}
void Enemy::changeDirection(int direction) {
	if (this->getDirection() == direction) {}
	else {
		if (direction == 2) {
			Animation * animation2 = Animation::create();
			SpriteFrame * spriteFrame5 = SpriteFrame::create("res/Down/1.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame6 = SpriteFrame::create("res/Down/2.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame7 = SpriteFrame::create("res/Down/3.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame8 = SpriteFrame::create("res/Down/4.png", Rect(0, 0, 50, 120));
			animation2->addSpriteFrame(spriteFrame5);
			animation2->addSpriteFrame(spriteFrame6);
			animation2->addSpriteFrame(spriteFrame7);
			animation2->addSpriteFrame(spriteFrame8);
			animation2->setDelayPerUnit(0.1f);
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
			SpriteFrame * spriteFrame5 = SpriteFrame::create("res/Up/1.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame6 = SpriteFrame::create("res/Up/2.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame7 = SpriteFrame::create("res/Up/3.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame8 = SpriteFrame::create("res/Up/4.png", Rect(0, 0, 50, 120));
			animation2->addSpriteFrame(spriteFrame5);
			animation2->addSpriteFrame(spriteFrame6);
			animation2->addSpriteFrame(spriteFrame7);
			animation2->addSpriteFrame(spriteFrame8);
			animation2->setDelayPerUnit(0.1f);
			animation2->setRestoreOriginalFrame(true);
			Animate* action2 = Animate::create(animation2);
			FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
			Character::changeDirection(1);
			this->stopActionByTag(123);
			back->setTag(123);
			this->runAction(back);
		}
		else if (direction == 4) {
			Animation * animation2 = Animation::create();
			SpriteFrame * spriteFrame5 = SpriteFrame::create("res/Right/1.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame6 = SpriteFrame::create("res/Right/2.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame7 = SpriteFrame::create("res/Right/3.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame8 = SpriteFrame::create("res/Right/4.png", Rect(0, 0, 50, 120));
			animation2->addSpriteFrame(spriteFrame5);
			animation2->addSpriteFrame(spriteFrame6);
			animation2->addSpriteFrame(spriteFrame7);
			animation2->addSpriteFrame(spriteFrame8);
			animation2->setDelayPerUnit(0.1f);
			animation2->setRestoreOriginalFrame(true);
			Animate* action2 = Animate::create(animation2);
			FiniteTimeAction* back = (FiniteTimeAction*)(RepeatForever::create(action2));
			Character::changeDirection(4);
			this->stopActionByTag(123);
			back->setTag(123);
			this->runAction(back);
		}
		else if (direction == 3) {
			Animation * animation2 = Animation::create();
			SpriteFrame * spriteFrame5 = SpriteFrame::create("res/Left/1.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame6 = SpriteFrame::create("res/Left/2.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame7 = SpriteFrame::create("res/Left/3.png", Rect(0, 0, 50, 120));
			SpriteFrame * spriteFrame8 = SpriteFrame::create("res/Left/4.png", Rect(0, 0, 50, 120));
			animation2->addSpriteFrame(spriteFrame5);
			animation2->addSpriteFrame(spriteFrame6);
			animation2->addSpriteFrame(spriteFrame7);
			animation2->addSpriteFrame(spriteFrame8);
			animation2->setDelayPerUnit(0.1f);
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
