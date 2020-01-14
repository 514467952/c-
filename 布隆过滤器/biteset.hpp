#pragma once
#include<vector>
#include<iostream>
using namespace std;
namespace LXY
{
	class bitset
	{
	public:
		bitset(size_t bitCount)
			:_set(bitCount / 8 + 1)
			, _bitCount(bitCount)
		{}
		//置1操作
		void set(size_t which)
		{
			//如果位集合给出100个比特位，那么你给100，就表示不了，范围为0~99
			if (which >= _bitCount)
				return;
			//计算对应的字节
			size_t index = (which >> 3);//除以8
			size_t pos = which % 8;

			//先将1移到对应的比特位上，再或上对应位上的数字
			_set[index] |= (1 << pos);
		}
		//置0操作
		void reset(size_t which)
		{
			if (which >= _bitCount)
				return;
			//计算对应的字节
			size_t index = (which >> 3);//除以8
			size_t pos = which % 8;

			//先将1的取反0移到对应的比特位上，再与上对应位上的数字
			_set[index] &= ~(1 << pos);
		}

		//检测which比特位是否为1
		bool test(size_t which)
		{
			if (which >= _bitCount)
				return false;
			//计算对应的字节
			size_t index = (which >> 3);//除以8
			size_t pos = which % 8;

			//与上1不等于0就代表存在
			return 0 != (_set[index] & (1 << pos));
		}
		//返回比特位总的个数
		size_t size()
		{
			return _bitCount;
		}

		//返回为1的比特位的总数
		size_t count()
		{
			//查表
			int bitCnttable[256] = {
				0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 3, 3, 4, 2,
				3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3,
				3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3,
				4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4,
				3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5,
				6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4,
				4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5,
				6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5,
				3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 3,
				4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 5, 5, 6, 5, 6, 6, 7, 5, 6,
				6, 7, 6, 7, 7, 8 };
			size_t szcount = 0;
			for (size_t i = 0; i < _set.size(); ++i)
				szcount += bitCnttable[_set[i]];
			return szcount;
		}
	public:
		std::vector<unsigned char> _set;
		size_t _bitCount;
	};
}