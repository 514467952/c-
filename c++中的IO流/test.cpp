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

	//输出日志信息
	clog << "2019/10/27";
	clog << "2019/10/27" << endl;

	int a;
	double b;
	string s;
	cin >> a;
	cin >> b >> s;

	//IO类算法
	//循环输入
	//整行接收
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
// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
			// 这里会发现IO流读整形比C语言那套就简单多了，
			// C 语言得先读字符串，再atoi
			ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // 配置文件
};

int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}