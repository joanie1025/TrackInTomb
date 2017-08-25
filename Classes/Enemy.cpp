#include"Enemy.h"
#include<cmath>
//����1Ϊ�ϣ�2Ϊ�£�3Ϊ��4Ϊ��
extern Leader*leader;//leaderΪȫ�ֱ������ɿ��ļ�
Enemy::Enemy() {
	Animation*left=nullptr;//�����ߵĶ���
	Animation*right = nullptr;//�����ߵĶ���
	Animation*ahead = nullptr;//��ǰ�ߵĶ���
	Animation*back = nullptr;//����ߵĶ���
				   /*************************
				   *
				   *
				   *
				   *�˴��ɹ�������
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
	FiniteTimeAction*ac1 = MoveBy::create(0.4f, direction);//����ͼƬ ÿ��֡һ��
	if (action != nullptr) {
		FiniteTimeAction *move = (FiniteTimeAction*)(Repeat::create((FiniteTimeAction*)action, 1));
		this->runAction(Spawn::create(ac1, move, NULL));
	}
	else
		this->runAction(ac1);
}