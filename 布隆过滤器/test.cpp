#pragma once
#include"biteset.hpp"
#include<iostream>
#include"Common.hpp"
using namespace std;

//BloomFilter:位图+多个哈希
template<class T,class HF1 = Str2INT ,class HF2 = Str2INT2,class HF3 = Str2INT3,
				class HF4 =Str2INT4,class HF5 = Str2INT5>
//哈希函数给的越多，将来产生误报的概率就也就越小
class BloomFilter
{
public:
	BloomFilter(size_t size = 10)
		:_bt(10 * size)
		, _size(0)
	{}
	bool Insert(const T& data)
	{
		//HF1()(data)可能回越界，要%上位图的比特位数
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

	//检测是否存在，每个哈希函数都得检测
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

		//元素可能存在
		return true;
	}

	//存储多少个元素
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
	//坏人得名单
	BloomFilter<string>	bf;
	bf.Insert("欧阳锋");
	bf.Insert("欧阳克");
	bf.Insert("孙渭超");

	cout << bf.count() << endl;

	if (bf.IsIn("金轮法王"))
		cout << "坏人" << endl;
	else
		cout << "大侠" << endl;

	if (bf.IsIn("欧阳锋"))
		cout << "坏人" << endl;
	else
		cout << "大侠" << endl;
}

int main()
{
	TestBloomFilter();
	system("pause");
	return 0;
}