
#include<iostream>
#include<string>
using namespace std;

class Printer
{
private:
	//默认构造函数私有化
	Printer(){ m_Count = 0; };
	//拷贝构造函数私有化
	Printer(const Printer& p){};

public:
	//对外提供接口访问唯一一个实例
	static Printer *getInstance()
	{
		return singlePrinter;
	}
	//打印功能
	void printText(string text)
	{
		cout << text << endl;
		m_Count++;
		cout << "打印机使用了次数为：" << m_Count << endl;
	}


private:
	static Printer *singlePrinter;
	int m_Count;		//打印次数

};

Printer * Printer::singlePrinter = new Printer;

void test01()
{
	//拿到打印机
	Printer *ptr= Printer::getInstance();

	ptr->printText("离职报告");
	ptr->printText("入职报告");
	ptr->printText("加薪申请");
	ptr->printText("升级申请");
	ptr->printText("退休申请");
	
}


int main()
{
	test01();
	system("pause");
	return 0;
}