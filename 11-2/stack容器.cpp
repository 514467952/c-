
#include<iostream>
using namespace std;
#include<stack>
/*
## stackû�е�����
Stack����Ԫ�صĽ�����������ϡ��Ƚ��������������ֻ��stack���˵�Ԫ�أ����л��ᱻ���ȡ�ã�stack���ṩ�������ܣ�Ҳ���ṩ������

## stack �����Ĭ�Ϲ���

1. stack ����ģ����ʵ�֣� stack �����Ĭ�Ϲ�����ʽ�� stack<T>stkT;
2.  stack<int>stkInt; //һ����� int �� stack ������ stack<float>stkFloat; //һ����� float �� stack ������
3. stack<string>stkString; //һ����� string �� stack ������
4.  ...
5.  //�������ڻ���������ָ�����ͻ��Զ������͡�

## stack �� push()�� pop()����

1. stack.push(elem);  //��ջͷ���Ԫ��
2. stack.pop(); //��ջͷ�Ƴ���һ��Ԫ��

## stack ����Ŀ��������븳ֵ

1. stack(conststack&stk); //�������캯��
2. stack&operator=(conststack&stk); //���صȺŲ�����

## stack �����ݴ�ȡ

1.  stack.top(); //�������һ��ѹ��ջԪ��

## stack �Ĵ�С

1. stack.empty(); //�ж϶�ջ�Ƿ�Ϊ��
2. stack.size(); //���ض�ջ�Ĵ�С
*/

void test01()
{
	stack<int>s;
	//�������� push
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (s.size()!=0)
	{
		cout << "ջ��Ϊ��" << s.top() << endl;//40�ȳ� 30 20 10
		//����ջ��Ԫ��
		s.pop();
	}
	cout << "size= " << s.size() << endl;

}


int main()
{
	test01();
	system("pause");
	return 0;
}