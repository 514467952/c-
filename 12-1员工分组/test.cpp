
#include<iostream>

using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>
/*
公司招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
的人员信息：姓名 年龄 电话 工资等组成
通过Multimap进行信息的插入 保存 显示
分部门显示员工信息，显示全部的员工信息
*/
enum{RENLI,YANFA,MEISHU};

class Worker
{
public:

	string m_Name;
	int m_Money;
};

void createWorker(vector<Worker>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "员工";
		name += nameSeed[i];

		int money = rand() % 10000 + 10000;//10000~19999

		Worker w;
		w.m_Money = money;
		w.m_Name = name;

		v.push_back(w);
	}
}
void setGroup(vector<Worker>&v,multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		//随机产生部门编号
		int departmentId = rand() % 3;//0 1 2\
		//将员工分到multimap
		m.insert(make_pair(departmentId, *it));
	}
}

void showGroup(multimap<int, Worker>&m)
{
	//人力部门显示
	cout << "人力部门员工如下：" << endl;

	multimap<int,Worker>::iterator pos= m.find(RENLI);
	int index = 0;
	int number = m.count(RENLI);
	for (; pos != m.end(),index<number; pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Money << endl;
	}
	//0 A B 1 C 2 D E
	cout << "-----------------------------" << endl;

	cout << "研发部门员工如下：" << endl;
	 pos = m.find(YANFA);
	 index = 0;
     number = m.count(YANFA);
	for (; pos != m.end(), index<number; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Money << endl;
	}
	cout << "-----------------------------" << endl;

	cout << "美术部门员工如下：" << endl;
	pos = m.find(MEISHU);
	index = 0;
	number = m.count(MEISHU);
	for (; pos != m.end(), index<number; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "工资：" << pos->second.m_Money << endl;
	}

}

int main()
{
	srand((unsigned int)time(NULL));

	//声明存放一个员工的容器
	vector<Worker>v;
	//创建5名员工
	createWorker(v);

	//设置分组
	//分组的multimap容器
	multimap<int, Worker>m;
	setGroup(v, m);

	//分部门显示员工
	showGroup(m);

	//员工创建测试
	/*for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << "工资：" << it->m_Money << endl;
	}*/

	system("pause");
	return 0;
}