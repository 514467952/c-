#include<iostream>

using namespace std;
#include<string>

void TestString1()
{
	string s1;
	string s2("hello");
	string s3(10, '$');
	string s4(s3);

	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//������ط�ʽ
void TestString2()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	if (s.empty())
		cout << "NULL" << endl;
	else
		cout << "NOT NULL string" << endl;

	//ֻ���string������Ч�ַ�����������ı�ײ�ռ�Ĵ�С
	s.clear();		//�����������
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	if (s.empty())
		cout << "NULL" << endl;
	else
		cout << "NOT NULL string" << endl;
}


void TestString3()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//resize 10����Ч�ַ���ԭ����5�����������5����!�Ž������
	s.resize(10,'!');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(20, '8');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(6);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void TestString4()
{
	string s("hello");
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(20);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(40);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(24);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}


void TestString5()
{
	string s("hello");
	cout << s[0] << endl;
	s[0] = 'H';
	//[] ���Խ��----assert����
	


	cout << s.at(2) << endl;
	s.at(2) = 'L';
	//s.at()���Խ��---�׳�out_of_range���쳣

	//��ͬ��
	//cout << s[10] << endl;  //Խ�����

	cout << s.at(10) << endl;
}


void TestString6()
{
	string s1;
	s1.push_back('I');

	s1 += " Love ";

	string s2("you");
	s1 += s2;

	s1.append(1, ',');
	s1.append("���");
	s1.append(3, '!');

	cout << s1 << endl;
}


void TestPushBack() 
{ 
	string s;       //ά��һ�����飬����15����Ч�ַ�
	s.reserve(100);
	size_t sz = s.capacity();    
	cout << "making s grow:\n";    
	for (int i = 0; i < 100; ++i)    
	{ 
		s.push_back( 'c');        
		if (sz != s.capacity())        //sz��¼��һ��������С
		{ 
			sz = s.capacity();            
			cout << "capacity changed: " << sz << '\n'; 
		} 
	} 
}

void TestPushBack_P() {
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}

void TestString7()
{
	string s("123456");
	int ret = atoi(s.c_str());

}

//find rfind
void TestString8()
{
	string s("hello world");
	size_t pos = s.find( ' ');
	if (pos != string::npos)
	{
		cout << ' ' << "is in s"<<endl;
	}

	pos = s.find("world");
	if (pos != string::npos)
	{
		cout << "world" << "is in s" << endl;
	}

	//��ȡ�ļ���׺
	string ss("2019-10-26.cpp.cpp");
	pos = ss.rfind('.') + 1;  //��׺��λ�ô�.�ĺ��濪ʼ
	cout << pos << endl;

	string filepos = ss.substr(pos);
	cout << filepos << endl;

}

void TestString9()
{
	string s("hello");

	for (auto e : s)
	{
		cout << e;
	}
	cout << endl;

	for (int i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;

	//char *
	string::iterator it = s.begin();
	while (it!=s.end())
	{
		cout << *it ;
		++it;
	}
	cout << endl;
}

//��ת�ַ���
void reversestring(string &s)
{
	//char* begin = (char *)s.c_str();
	//char* end = begin + s.size() - 1;
	//while (begin < end)
	//{
	//	swap(*begin, *end);
	//	begin++;
	//	end--;
	//}

	reverse(s.begin(), s.end());
}

//�������

class Solution {
public:
	string addStrings(string num1, string num2) {

		int LSize = num1.size();
		int RSize = num2.size();
		//���ĸ��Ƚϳ�
		if (LSize < RSize)
		{
			num1.swap(num2);
			swap(LSize, RSize);
		}
		//������
		string strRet(LSize + 1, '0');

		char offset = 0; //��λ
		int LIdx;
		int RIdx;
		for (LIdx = num1.size() - 1, RIdx = num2.size() - 1; LIdx >= 0; LIdx--, RIdx--);
		{
			char cRet = num1[LIdx] - '0';

			if (RIdx >= 0)
			{
				cRet += num2[RIdx] - '0';
			}

			cRet += offset;
			offset = 0; //��λ����
			if (cRet >= 10)
			{
				offset = 1;
				cRet -= 10;
			}
			strRet[LIdx + 1] += cRet;
		}

		if (offset == 1)
			strRet[0] += 1;
		else
			strRet.erase(strRet.begin());
		return strRet;
	}
};
int main()
{

	string s;
	getline(cin , s);
	cout << s << endl;

	//TestString6();
	//TestPushBack();
	//TestString9();

	/*string s("hello");
	cout << s << endl;
	reversestring(s);
	cout << s << endl;*/
	system("pause");
	return 0;
}