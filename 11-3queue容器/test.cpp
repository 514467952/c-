
#include<iostream>

using namespace std;
#include<queue>

void test01()
{
	queue<int>q;
	q.push(10);	//往队尾添加元素
	q.push(20);
	q.push(30);
	q.push(40);
	while (!q.empty())
	{
		cout << "队头:" << q.front() << endl;
		cout << "队尾:" << q.back() << endl;
		//弹出队头元素
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