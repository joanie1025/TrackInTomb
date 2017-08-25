#include"Enemy.h"
#include<cmath>
//方向1为上，2为下，3为左，4为右
extern Leader*leader;//leader为全局变量，可跨文件
Enemy::Enemy() {
	Animation*left=nullptr;//向左走的动画
	Animation*right = nullptr;//向右走的动画
	Animation*ahead = nullptr;//向前走的动画
	Animation*back = nullptr;//向后走的动画
				   /*************************
				   *
				   *
				   *
				   *此处可构建动画
				   *
				   *
				   *
				   **************************/
	attacktimes = 2;
}
double Enemy::getDistance() {
	double distance = sqrt((leader->getPosition().x - this->getPosition().x)*(leader->getPosition().x - this->getPosition().x) +
		(leader->getPosition().y - this->getPosition().y)*(leader->getPosition().y - this->getPosition().y));
	return distance;
}
void Enemy::move() {
	int distance = this->getDistance();
	Vec2 direction = Vec2((leader->getPosition().x - this->getPosition().x) / distance * 5,
		(leader->getPosition().y - this->getPosition().y)*(leader->getPosition().y - this->getPosition().y) / distance * 5) + this->getPosition();
	float y = atan2(leader->getPosition().x - this->getPosition().x, leader->getPosition().y - this->getPosition().y);
	Animation*action;
	if (y > 45 && y < 135) {
		if (left != nullptr)
			action = ahead;
		this->changeDirection(1);
	}
	else if ((y >= 0 && y <= 45) || (y <= 360 && y > 315)) {
		if (left != nullptr)
			action = right;
		this->changeDirection(4);
	}
	else if (y > 225 && y <= 315) {
		if (left != nullptr)
			action = back;
		this->changeDirection(2);
	}
	else {
		if (left != nullptr)
			action = left;
		this->changeDirection(3);
	}
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, direction);//四张图片 每两帧一张
	if (action != nullptr) {
		FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)action, 1));
		this->runAction(Spawn::create(ac1, move, NULL));
	}
	else
		this->runAction(ac1);
}