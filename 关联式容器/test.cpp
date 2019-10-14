#include<iostream>

using namespace std;



#include<map>
#include<string>
void TestMap()
{
	map<string, string>m;
	m.insert(pair<string,string>("�ν�","��ʱ��"));
	m.insert(pair<string, string>("����", "������"));

	//pair<iterator,bool>
	//iterator:����map�е�һ��key-value�ļ�ֵ��
	//bool:insert�����Ƿ�ɹ�
	auto ret = m.insert(make_pair("�����","ĸҹ��"));
	if (ret.second){
		cout << (*ret.first).first << "--->" << ret.first->second << endl;
	}
	ret = m.insert(make_pair("����", "��ţ"));
	//key �Ѿ����ڲ������
	cout << (*ret.first).first << "--->" << ret.first->second << endl;

	cout << m.size() << endl;

	cout << m["����"] << endl; //��value������
	//�û��ṩkey---->[]����key����Ӧ��value
	m["����"] = "��ţ";  //�޸�value
	cout << m["����"] << endl;
	m["�ֳ�"] = "����ͷ";
	cout << m.size() << endl;
}


void TestMap2()
{
	int array[] = { 3, 1, 9, 4, 0, 7, 6, 2, 5 };
	map<int, int>m;
	for (auto e : array){
		m.insert(make_pair(e, e));
	}

	//���԰��յ�������ʽ���б������ܷ�õ�һ������key���������
	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "---->" << it->second << endl;
		++it;
	}
	cout << endl;

	m.erase(5);
	for (auto& e : m)
	{
		cout << e.first << "---->" << e.second << endl;
	}
	cout << endl;
}



//#include<set>


//int main()
//{
//	int array[] = { 3, 1, 3, 4, 5, 6, 7, 8, 9, 0, 9, 4, 0, 7, 6, 2, 5, 8 };
//	set<int>s;
//	for (auto e : array)
//		s.insert(e);
//	cout << s.size() << endl;
//
//	for (auto e : s)
//		cout << e << " ";
//	cout << endl;
//	system("pause");
//	return 0;
//}


#include<set>
int main()
{
	int array[] = { 3, 1, 3, 4, 5, 6, 7, 8, 9, 0, 9, 4, 0, 7, 6, 2, 5, 8 };
		multiset<int>s;
		for (auto e : array)
			s.insert(e);
		cout << s.size() << endl;
	
		for (auto e : s)
			cout << e << " ";
		cout << endl;
	system("pause");
	return 0;
}