

#include"Myarray.h"

void test01()
{
	//������������
	MyArray *array = new MyArray(30);

	MyArray *array2=new MyArray(*array);//new��ʽָ����������

	MyArray array3 = *array2;  //���캯�����صı���

	//MyArray *array4 = array; //������һ��ָ���arrayִ�еĵ�ַ��ͬ�����Բ�����ÿ�������


	delete array;

	//β�巨�Ĳ���
	for (int i = 0; i < 10; i++)
	{
		array2->Push_Back(i);
	}
	//��ȡ���ݵĲ���
	for (int i = 0; i < 10; i++)
	{
		cout << array2->getData(i) << endl;
	}
	//����ֵ�Ĳ���
	array2->setData(0, 1000);
	cout << array2->getData(0) << endl;

	//��ȡ�����С
	cout << "array2�������С" << array2->getSize() << endl;

	//��ȡ��������
	cout << "array2����������" << array2->getCapacity() << endl;
	
}


int main()
{
	test01();
	system("pause");
	return 0;
}