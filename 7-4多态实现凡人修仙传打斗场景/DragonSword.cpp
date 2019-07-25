#include"DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "屠龙宝刀";
	this->SuckRate = 20;
	this->holdRate = 30;
	this->critRate = 35;
}

int DragonSword::getBaseDamage()
{
	return this->m_BaseDamage;
}

int DragonSword::getSuckBlood()
{
	if (isTrigger(SuckRate))
	{
		return  this->m_BaseDamage*0.5;    //按照武器基础伤害一半吸血
	}
	return 0;
}

bool DragonSword::getHold()
{
	if (isTrigger(holdRate))
	{
		return true;
	}
	return false;
}

bool DragonSword::getCrit()
{
	if (isTrigger(critRate))
	{
		return true;
	}
	return false;
}

bool DragonSword::isTrigger(int rate)
{
	//通过isTrigger判断是否触发特效
	//随机一个0~100的数字
	//rand()%100 是0~99之间的随机数 +1后是1~100之间的一个随机数
	//如果产生的随机数比设定的概率值小则发生，否则不发生
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;

}