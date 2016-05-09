#include "Heap.h"

//void Test()    //建大堆
//{
//	int a[] = {10,16,18,12,11,13,15,17,14,19};
//	Heap<int> hp(a,sizeof(a)/sizeof(a[0]));
//	//hp.Push(20);  //插入元素20
//	hp.Push(2);    //插入元素2
//	hp.Pop();     //删除（删除优先级高）
//}

void Test1()
{
	int a[] = {10,16,18,12,11,13,15,17,14,19};
	//Heap<int> hp(a,sizeof(a)/sizeof(a[0])); //默认建大堆
	Heap<int,Less<int> > hp1(a,sizeof(a)/sizeof(a[0])); //建小堆
}


int main()
{
	//Test();
	Test1();
	return 0;
}