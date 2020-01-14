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
		//��1����
		void set(size_t which)
		{
			//���λ���ϸ���100������λ����ô���100���ͱ�ʾ���ˣ���ΧΪ0~99
			if (which >= _bitCount)
				return;
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);//����8
			size_t pos = which % 8;

			//�Ƚ�1�Ƶ���Ӧ�ı���λ�ϣ��ٻ��϶�Ӧλ�ϵ�����
			_set[index] |= (1 << pos);
		}
		//��0����
		void reset(size_t which)
		{
			if (which >= _bitCount)
				return;
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);//����8
			size_t pos = which % 8;

			//�Ƚ�1��ȡ��0�Ƶ���Ӧ�ı���λ�ϣ������϶�Ӧλ�ϵ�����
			_set[index] &= ~(1 << pos);
		}

		//���which����λ�Ƿ�Ϊ1
		bool test(size_t which)
		{
			if (which >= _bitCount)
				return false;
			//�����Ӧ���ֽ�
			size_t index = (which >> 3);//����8
			size_t pos = which % 8;

			//����1������0�ʹ������
			return 0 != (_set[index] & (1 << pos));
		}
		//���ر���λ�ܵĸ���
		size_t size()
		{
			return _bitCount;
		}

		//����Ϊ1�ı���λ������
		size_t count()
		{
			//���
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