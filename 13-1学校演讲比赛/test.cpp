
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#include<string>
#include<algorithm>
#include<deque>
#include<numeric>
#include<functional>
class Speaker
{
public:

	string m_Name;//姓名
	int m_Score[3];//得分数组

};

//创建选手函数
void createSpeaker(vector<int>&v, map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//创建选手
	for (int i = 0; i < 24; ++i)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;

		//得分初始化
		for (int j = 0; j < 3; j++)
		{
			sp.m_Score[j] = 0;
		}
		//将选手放到容器中
		v.push_back(i + 100);//编号100~123
		m.insert(make_pair(i + 100, sp));
	}

}


//抽签函数
void speechDraw(vector<int >v)
{
	//洗牌
	random_shuffle(v.begin(), v.end());
}

//比赛函数
// 1 第几轮得分  2 v1比赛选手编号，3 m是选手编号和具体选手   4 v2晋级选手编号容器
void speechContest(int index,vector<int>&v1, map<int, Speaker>&m, vector<int>&v2)
{
	//临时容器
	multimap<int, int, greater<int>>groupMap;//分数 编号
	int num = 0;

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		num++;
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//分数随机给
			int score = rand() % 41 + 60;//60~100
			d.push_back(score);
		}
		//排序
		sort(d.begin(), d.end());
		//去除最高最低分
		d.pop_back();
		d.pop_front();
		//累计分数
		int sum = accumulate(d.begin(),d.end(),0);
		int avg = sum / d.size();

		//将平均分 放入到m容器中
		//第几轮的得分
		m[*it].m_Score[index - 1] = avg;

		//每6个人取前三名 晋级 进入v2容器
		//临时容器保存6个人，晋级完后清空，再进入6个人
		//临时容器，存入数据
		groupMap.insert(make_pair(avg, *it));
		if (num % 6 == 0)  //够6个人进入
		{
			/*cout << "小组比赛成绩如下：" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
			{
				cout << "编号：" << mit->second << "姓名：" << m[mit->second].m_Name << "得分：" << m[mit->second].m_Score[index - 1] << endl;
			}
*/
			//取前三名
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(), count < 3; mit++, count++)
			{
				//晋级容器  获取数据
				v2.push_back(mit->second);
			}

			groupMap.clear();//清空容器
		}
	}
}

void showScore(int index, vector<int>&v, map<int, Speaker>&m)
{
	cout << "第" << index << "轮，比赛成绩如下：" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "选手编号：" << it->first << "姓名：" << it->second.m_Name << "分数：" << it->second.m_Score[index - 1]<<endl;
	}

	cout << "晋级选手编号:" << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{

	vector<int>v1;//放选手编号
	map<int, Speaker> m ;//存放选手编号，和队医你个的具体选手
	//创建选手
	createSpeaker(v1, m);

	//抽签
	speechDraw(v1);

	//比赛
	vector<int>v2;//进入下一轮比赛的人员编号
	speechContest(1,v1, m, v2);

	//显示比赛结果
	showScore(1,v2,m);//轮数，晋级编号，具体的人员信息

	//第二轮比赛
	speechDraw(v2);
	vector<int>v3;//第三轮的容器
	speechContest(2, v2, m, v3);
	showScore(2, v3, m);

	//第三轮比赛
	speechDraw(v3);
	vector<int>v4;//第三轮的容器
	speechContest(3, v3, m, v4);
	showScore(3, v4, m);

	/*for (map<int,Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "编号：" << it->first << "姓名：" << it->second.m_Name << endl;
	}*/

	system("pause");
	return 0;
}

