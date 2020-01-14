#pragma once
#include"biteset.hpp"
#include<iostream>
#include"Common.hpp"
using namespace std;

//BloomFilter:λͼ+�����ϣ
template<class T,class HF1 = Str2INT ,class HF2 = Str2INT2,class HF3 = Str2INT3,
				class HF4 =Str2INT4,class HF5 = Str2INT5>
//��ϣ��������Խ�࣬���������󱨵ĸ��ʾ�Ҳ��ԽС
class BloomFilter
{
public:
	BloomFilter(size_t size = 10)
		:_bt(10 * size)
		, _size(0)
	{}
	bool Insert(const T& data)
	{
		//HF1()(data)���ܻ�Խ�磬Ҫ%��λͼ�ı���λ��
		size_t index1 = HF1()(data) % _bt.size();
		size_t index2 = HF2()(data) % _bt.size();
		size_t index3 = HF3()(data) % _bt.size();
		size_t index4 = HF4()(data) % _bt.size();
		size_t index5 = HF5()(data) % _bt.size();

		_bt.set(index1);
		_bt.set(index2);
		_bt.set(index3);
		_bt.set(index4);
		_bt.set(index5);
		_size++;
		return true;
	}

	//����Ƿ���ڣ�ÿ����ϣ�������ü��
	bool IsIn(const T&data)
	{
		size_t index = HF1()(data) % _bt.size();
		if (!_bt.test(index))
			return false;

		index = HF2()(data) % _bt.size();
		if (!_bt.test(index))
			return false;

		index = HF3()(data) % _bt.size();
		if (!_bt.test(index))
			return false;

		index = HF4()(data) % _bt.size();
		if (!_bt.test(index))
			return false;

		index = HF5()(data) % _bt.size();
		if (!_bt.test(index))
			return false;

		//Ԫ�ؿ��ܴ���
		return true;
	}

	//�洢���ٸ�Ԫ��
	size_t count()const
	{
		return _size;
	}
private:
	LXY::bitset _bt;
	size_t _size;
};

void TestBloomFilter()
{
	//���˵�����
	BloomFilter<string>	bf;
	bf.Insert("ŷ����");
	bf.Insert("ŷ����");
	bf.Insert("��μ��");

	cout << bf.count() << endl;

	if (bf.IsIn("���ַ���"))
		cout << "����" << endl;
	else
		cout << "����" << endl;

	if (bf.IsIn("ŷ����"))
		cout << "����" << endl;
	else
		cout << "����" << endl;
}

int main()
{
	TestBloomFilter();
	system("pause");
	return 0;
}