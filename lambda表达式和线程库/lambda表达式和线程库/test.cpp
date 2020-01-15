#include<iostream>
using namespace std;
#include <algorithm>
#include <functional>
#if 0
int main()
{
	int array[] = { 4, 1, 8, 5, 3, 7, 0, 9, 2, 6 };
	// Ĭ�ϰ���С�ڱȽϣ��ų������������
	std::sort(array, array + sizeof(array) / sizeof(array[0]));
	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
	return 0;
}
#endif

#if 0
struct Goods
{
	string _name;
	double _price;
};
struct Compare
{
	bool operator()(const Goods& gl, const Goods& gr)
	{
		return gl._price <= gr._price;
	}
};
int main()
{
	Goods gds[] = { { "ƻ��", 2.1 }, { "�ཻ", 3 }, { "����", 2.2 }, { "����", 1.5 } };
	//sort(gds, gds + sizeof(gds) / sizeof(gds[0]), Compare());
	sort(gds, gds + sizeof(gds) / sizeof(gds[0]), [](const Goods&left, const Goods& right)
													{
															return left._price < right._price; 
													});
	return 0;
}
#endif

#if 0
int g_a = 10;
int main()
{
	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
	[]{};
	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
	int a = 3, b = 4;
	[=,&g_a]{return a + 3; };	//��Ҫ��a�Ļ�����+3���ء�
	//�������lambda���ʽû����
	//��Ϊû��ȡ����

	// ʡ���˷���ֵ���ͣ��޷���ֵ����
	//��֪��lambda���ʽ�����;���auto
	//[&]�����õķ�ʽ����ǰ�������ı���  a=3;b=13;
	//[=]��ֵ�÷�ʽ���в���			a=3;b=4;
	auto fun1 = [=](int c)mutable{b = a + c; };
	fun1(10);
	cout << a << " " << b << endl;


	// �����ֶ������Ƶ�lambda����
	// [=] ��ֵ�ķ�ʽ�������еı���
	// [&] �����õķ�ʽ�������еı���
	// [=,&b] ����b���������õ÷�ʽ���񣬶�������������ֵ�ķ�ʽ
	auto fun2 = [=, &b](int c)->int{return b += a + c; };
	cout << fun2(10) << endl;

	// ���Ʋ�׽x
	// ��ֵ�÷�ʽ����x���������޸Ĳ���Ӱ���ⲿ
	int x = 10;
	auto add_x = [x](int a) mutable { x *= 2; return a + x; };
	cout << add_x(10) << endl;
	return 0;
}
#endif

#if 0
void(*PF)();//û�з���ֵҲû�в����ú���ָ��
int main()
{
	auto f1 = []{cout << "hello world" << endl; };
	auto f2 = []{cout << "hello world" << endl; };
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()
	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f2);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
	PF = f2;
	PF();
	return 0;
}
#endif

#if 0
class Rate
{
public:
	Rate(double rate) 
		: _rate(rate)
	{}
	double operator()(double money, int year)
	{
		return money * _rate * year;
	}
private:
	double _rate;
};
int main()
{
	// ��������
	double rate = 0.49;
	Rate r1(rate); //����һ���������ʴ���ȥ
	r1(10000, 2);	//�����������ķ��������������ñȽ����� ����()
	// �º���
	//=����rate
	auto r2 = [=](double monty, int year)->double{return monty*rate*year; };
	r2(10000, 2);

	int array[] = { 1, 2, 3, 4, 5 };
	for_each(array, array + 5, [](int&c){c *= 2; });
	for_each(array, array + 5, [](int c){cout << c<<" "; });
	system("pause");
	return 0;
}
#endif

#if 0
#include<thread>
void ThreadFunc(int a)
{
	cout << "Thread1" << a << endl;
}
class TF
{
public:
	void operator()()
	{
		cout << "Thread3" << endl;
	}
};

int main()
{
	TF tf;
	//�̺߳���β����ָ��
	thread t1(ThreadFunc, 10);
	//�̺߳���Ϊlambda���ʽ
	thread t2([]{cout << "Thread2" << endl; });
	//�̺߳���Ϊ��������
	thread t3(tf);

	t1.join();
	t2.join();
	t3.join();
	cout << "Main thread!" << endl;

	system("pause");
	return 0;
}
#endif
#if 0
#include<thread>
void ThreadFunc1(int& x)
{
	cout << &x << " " << x << endl;
	x += 10;
}

void ThreadFunc2(int*x)
{
	*x += 10;
}

int main()
{
	int a = 10;

	//���̺߳����ж�a�޸ģ�����Ӱ���ⲿʵ�Σ���Ϊ:�̺߳�����Ȼ�����÷�ʽ������ʵ�����õ����߳�ջ�еĿ���
	thread t1(ThreadFunc1, a);
	t1.join();
	cout << &a <<" "<< a << endl;

	//��ַ�Ŀ���
	thread t3(ThreadFunc2, &a);
	t3.join();
	cout << a << endl;

	system("pause");
	return 0;
}
#endif


#include <iostream>
using namespace std;
#include <thread>
#include<atomic>

//unsigned long sum = 0L;
atomic_long sum{0}; //����ԭ�����ͱ���

void fun(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	{
		sum++;
	}
}
int main()
{
	size_t begin = clock();
	cout << "Before joining,sum = " << sum << std::endl;
	thread t1(fun, 10000000);
	thread t2(fun, 10000000);
	//�����߳�ÿ��ÿ�ض�ѭ��10000000�Σ�ÿ�μ�1
	//���û����Ӧ����20000000
	t1.join();
	t2.join();
	cout << "After joining,sum = " << sum << std::endl;
	size_t end = clock();
	cout << end - begin << endl; //����ʱ��
	system("pause");
	return 0;
}
