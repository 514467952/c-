#pragma once
#include<string>
#include<iostream>
using namespace std;
class Str2INT
{
public:
	size_t operator()(const string& s)
	{
		return SDBMHash(s.c_str());
	}

	unsigned int SDBMHash( const char *str)
	{
		unsigned int hash = 0;
		while (*str)
		{
			// equivalent to: hash = 65599*hash + (*str++);
			hash = (*str++) + (hash << 6) + (hash << 16) - hash;
		}
		return (hash & 0x7FFFFFFF);
	}
};

class Str2INT2
{
public:
	size_t operator()(const string& s)
	{
		return RSHash(s.c_str());
	}

	unsigned int RSHash(const char *str)
	{
		unsigned int b = 378551;
		unsigned int a = 63689;
		unsigned int hash = 0;

		while (*str)
		{
			hash = hash * a + (*str++);
			a *= b;
		}

		return (hash & 0x7FFFFFFF);
	}
};

class Str2INT3
{
public:
	size_t operator()(const string& s)
	{
		return JSHash(s.c_str());
	}

	unsigned int JSHash(const char *str)
	{
		unsigned int hash = 1315423911;

		while (*str)
		{
			hash ^= ((hash << 5) + (*str++) + (hash >> 2));
		}

		return (hash & 0x7FFFFFFF);
	}
};

class Str2INT4
{
public:
	size_t operator()(const string& s)
	{
		return PJWHash(s.c_str());
	}
	// P. J. Weinberger Hash Function
	unsigned int PJWHash(const char *str)
	{
		unsigned int BitsInUnignedInt = (unsigned int)(sizeof(unsigned int)* 8);
		unsigned int ThreeQuarters = (unsigned int)((BitsInUnignedInt * 3) / 4);
		unsigned int OneEighth = (unsigned int)(BitsInUnignedInt / 8);
		unsigned int HighBits = (unsigned int)(0xFFFFFFFF) << (BitsInUnignedInt - OneEighth);
		unsigned int hash = 0;
		unsigned int test = 0;

		while (*str)
		{
			hash = (hash << OneEighth) + (*str++);
			if ((test = hash & HighBits) != 0)
			{
				hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
			}
		}

		return (hash & 0x7FFFFFFF);
	}
};

class Str2INT5
{
public:
	size_t operator()(const string& s)
	{
		return ELFHash(s.c_str());
	}
	// ELF Hash Function
	unsigned int ELFHash(const char *str)
	{
		unsigned int hash = 0;
		unsigned int x = 0;

		while (*str)
		{
			hash = (hash << 4) + (*str++);
			if ((x = hash & 0xF0000000L) != 0)
			{
				hash ^= (x >> 24);
				hash &= ~x;
			}
		}

		return (hash & 0x7FFFFFFF);
	}
};
