#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#if 0
int main()
{
	printf("%d,%d", "hello", "world");
	int a = 0;
	scanf("%d",&a);
	return 0;
}
#endif

#if 0
#include<string>
int main()
{
	cerr << "error1";
	cerr << "error2" << endl;

	//�����־��Ϣ
	clog << "2019/10/27";
	clog << "2019/10/27" << endl;

	int a;
	double b;
	string s;
	cin >> a;
	cin >> b >> s;

	//IO���㷨
	//ѭ������
	//���н���
	while(getling(cin,s))
	system("pause");
	return 0;
}
#endif
# if 0
int main()
{
	char c;
	//cin >> c;
	c = getchar();
	return 0;
}
#endif

#include<fstream>
// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ��д
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
			// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
			// C ���Ե��ȶ��ַ�������atoi
			ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // �����ļ�
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// �ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}