
#include<iostream>

using namespace std;
#include<queue>

void test01()
{
	queue<int>q;
	q.push(10);	//����β���Ԫ��
	q.push(20);
	q.push(30);
	q.push(40);
	while (!q.empty())
	{
		cout << "��ͷ:" << q.front() << endl;
		cout << "��β:" << q.back() << endl;
		//������ͷԪ��
		q.pop();
	}
	cout << "size:" << q.size() << endl;

}




int main()
{
	test01();
	system("pause");
	return 0;
}