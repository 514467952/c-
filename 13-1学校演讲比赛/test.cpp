
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

	string m_Name;//����
	int m_Score[3];//�÷�����

};

//����ѡ�ֺ���
void createSpeaker(vector<int>&v, map<int,Speaker>&m)
{
	string nameSeed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//����ѡ��
	for (int i = 0; i < 24; ++i)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;

		//�÷ֳ�ʼ��
		for (int j = 0; j < 3; j++)
		{
			sp.m_Score[j] = 0;
		}
		//��ѡ�ַŵ�������
		v.push_back(i + 100);//���100~123
		m.insert(make_pair(i + 100, sp));
	}

}


//��ǩ����
void speechDraw(vector<int >v)
{
	//ϴ��
	random_shuffle(v.begin(), v.end());
}

//��������
// 1 �ڼ��ֵ÷�  2 v1����ѡ�ֱ�ţ�3 m��ѡ�ֱ�ź;���ѡ��   4 v2����ѡ�ֱ������
void speechContest(int index,vector<int>&v1, map<int, Speaker>&m, vector<int>&v2)
{
	//��ʱ����
	multimap<int, int, greater<int>>groupMap;//���� ���
	int num = 0;

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		num++;
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			//���������
			int score = rand() % 41 + 60;//60~100
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ�������ͷ�
		d.pop_back();
		d.pop_front();
		//�ۼƷ���
		int sum = accumulate(d.begin(),d.end(),0);
		int avg = sum / d.size();

		//��ƽ���� ���뵽m������
		//�ڼ��ֵĵ÷�
		m[*it].m_Score[index - 1] = avg;

		//ÿ6����ȡǰ���� ���� ����v2����
		//��ʱ��������6���ˣ����������գ��ٽ���6����
		//��ʱ��������������
		groupMap.insert(make_pair(avg, *it));
		if (num % 6 == 0)  //��6���˽���
		{
			/*cout << "С������ɼ����£�" << endl;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(); mit++)
			{
				cout << "��ţ�" << mit->second << "������" << m[mit->second].m_Name << "�÷֣�" << m[mit->second].m_Score[index - 1] << endl;
			}
*/
			//ȡǰ����
			int count = 0;
			for (multimap<int, int, greater<int>>::iterator mit = groupMap.begin(); mit != groupMap.end(), count < 3; mit++, count++)
			{
				//��������  ��ȡ����
				v2.push_back(mit->second);
			}

			groupMap.clear();//�������
		}
	}
}

void showScore(int index, vector<int>&v, map<int, Speaker>&m)
{
	cout << "��" << index << "�֣������ɼ����£�" << endl;

	for (map<int, Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first << "������" << it->second.m_Name << "������" << it->second.m_Score[index - 1]<<endl;
	}

	cout << "����ѡ�ֱ��:" << endl;

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
}

int main()
{

	vector<int>v1;//��ѡ�ֱ��
	map<int, Speaker> m ;//���ѡ�ֱ�ţ��Ͷ�ҽ����ľ���ѡ��
	//����ѡ��
	createSpeaker(v1, m);

	//��ǩ
	speechDraw(v1);

	//����
	vector<int>v2;//������һ�ֱ�������Ա���
	speechContest(1,v1, m, v2);

	//��ʾ�������
	showScore(1,v2,m);//������������ţ��������Ա��Ϣ

	//�ڶ��ֱ���
	speechDraw(v2);
	vector<int>v3;//�����ֵ�����
	speechContest(2, v2, m, v3);
	showScore(2, v3, m);

	//�����ֱ���
	speechDraw(v3);
	vector<int>v4;//�����ֵ�����
	speechContest(3, v3, m, v4);
	showScore(3, v4, m);

	/*for (map<int,Speaker>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "��ţ�" << it->first << "������" << it->second.m_Name << endl;
	}*/

	system("pause");
	return 0;
}

