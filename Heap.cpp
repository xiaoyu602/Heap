#include "Heap.h"

//void Test()    //�����
//{
//	int a[] = {10,16,18,12,11,13,15,17,14,19};
//	Heap<int> hp(a,sizeof(a)/sizeof(a[0]));
//	//hp.Push(20);  //����Ԫ��20
//	hp.Push(2);    //����Ԫ��2
//	hp.Pop();     //ɾ����ɾ�����ȼ��ߣ�
//}

void Test1()
{
	int a[] = {10,16,18,12,11,13,15,17,14,19};
	//Heap<int> hp(a,sizeof(a)/sizeof(a[0])); //Ĭ�Ͻ����
	Heap<int,Less<int> > hp1(a,sizeof(a)/sizeof(a[0])); //��С��
}


int main()
{
	//Test();
	Test1();
	return 0;
}