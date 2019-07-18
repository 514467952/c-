

#include"Myarray.h"

void test01()
{
	//堆区创建数组
	MyArray *array = new MyArray(30);

	MyArray *array2=new MyArray(*array);//new方式指定拷贝构造

	MyArray array3 = *array2;  //构造函数返回的本体

	//MyArray *array4 = array; //这声明一个指针和array执行的地址相同，所以不会调用拷贝构造


	delete array;

	//尾插法的测试
	for (int i = 0; i < 10; i++)
	{
		array2->Push_Back(i);
	}
	//获取数据的测试
	for (int i = 0; i < 10; i++)
	{
		cout << array2->getData(i) << endl;
	}
	//设置值的测试
	array2->setData(0, 1000);
	cout << array2->getData(0) << endl;

	//获取数组大小
	cout << "array2的数组大小" << array2->getSize() << endl;

	//获取数组容量
	cout << "array2的数组容量" << array2->getCapacity() << endl;
	
}


int main()
{
	test01();
	system("pause");
	return 0;
}