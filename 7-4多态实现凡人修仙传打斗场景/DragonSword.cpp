#include"DragonSword.h"

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "��������";
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
		return  this->m_BaseDamage*0.5;    //�������������˺�һ����Ѫ
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
	//ͨ��isTrigger�ж��Ƿ񴥷���Ч
	//���һ��0~100������
	//rand()%100 ��0~99֮�������� +1����1~100֮���һ�������
	//�����������������趨�ĸ���ֵС���������򲻷���
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;

}