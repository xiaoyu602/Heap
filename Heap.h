#pragma once
#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

//�����
template <class T>
class Heap
{
public:
	Heap()   //�޲ι��캯��
	{}

	Heap(T* a,size_t size)
	{
		for(size_t i=0;i<size;++i)
		{
			_a.push_back(a[i]);
		}
		//����
		for(int i=(_a.size()-2)/2;i>=0;--i)
		{
			_ApDown(i);
		}
	}

	void Push(const T& x)//����Ԫ��
	{
		_a.push_back(x);//�ڶ�β����Ԫ��
		_ApHeapUp(_a.size()-1);	//���ϵ���	
	}

	void Pop()//ɾ��(ɾ�����ȼ���)
	{
		swap(_a[0],_a[_a.size()-1]);//�����ѵĵ�һ��Ԫ�غ����һ��Ԫ��
		_a.pop_back();//ɾ�����һ��Ԫ��
		_ApDown(0);//���µ���
	}

	size_t Size()//�ѵĴ�С
	{
		return _a.size();
	}

	bool Empty()//���Ƿ�Ϊ��
	{
		return _a.empty();
	}

public:
	void _ApDown(size_t parent) 
	{
		size_t child = parent*2+1;
		
		while(child < _a.size())
		{
			//�ҵ����Һ����нϴ��      //(1)
			if((child+1) < _a.size() && _a[child+1] > _a[child])
			{
				++child;
			}
			//�ȽϽϴ����븸��
			if(_a[child] > _a[parent]) //(2)
			{
				swap(_a[child],_a[parent]);
				parent = child;
				child = parent*2+1;
			}
			else
			{
				break;
			}
		}
	}

	void _ApHeapUp(size_t child)
	{
		size_t parent = (child-1)/2;
		while(child > 0)
		{ 
			//(3)
			if(_a[child] > _a[parent])//�ȽϺ����븸��
			{
				swap(_a[child],_a[parent]);
				child = parent;
				parent = (child-1)/2;
			}
			else
			{
				break;
			}
		}
	}
	
protected:
	vector<T> _a;
};


//��Ҫʵ����С�ѣ��ɽ�����������(1)(2)(3)���Ĵ��ڸ�ΪС�ڼ��ɡ�
//��������ʹ�ô������࣬������ά����
//��ô�����һ����ʵ�ּ��ɽ�����Ҳ�ɽ���С���أ�����֮ǰ���ķº��������ϳ�ඣ�
//�ع�һ��ʲô�Ƿº�����
//�º����Ļ��ƾ���ͨ���ԣ����������ء�

template <class T>
struct Less  //С��
{
	bool operator()(const T& l,const T& r)
	{
		return l < r;
	}
};

template <class T>
struct Greater  //����
{
	bool operator()(const T& l,const T& r)
	{
		return l > r;
	}
};

template <class T,class Comper = Greater<T> >//Ĭ�Ͻ����
class Heap
{
public:
	Heap()   //�޲ι��캯��
	{}

	Heap(T* a,size_t size)
	{
		for(size_t i=0;i<size;++i)
		{
			_a.push_back(a[i]);
		}
		//����
		for(int i=(_a.size()-2)/2;i>=0;--i)
		{
			_ApDown(i);
		}
	}

	void Push(const T& x)//����Ԫ��
	{
		_a.push_back(x);//�ڶ�β����Ԫ��
		_ApHeapUp(_a.size()-1);	//���ϵ���	
	}

	void Pop()//ɾ��(ɾ�����ȼ���)
	{
		swap(_a[0],_a[_a.size()-1]);//�����ѵĵ�һ��Ԫ�غ����һ��Ԫ��
		_a.pop_back();//ɾ�����һ��Ԫ��
		_ApDown(0);//���µ���
	}

	size_t Size()//�ѵĴ�С
	{
		return _a.size();
	}

	bool Empty()//���Ƿ�Ϊ��
	{
		return _a.empty();
	}

public:
	void _ApDown(size_t parent) 
	{
		size_t child = parent*2+1;
		
		while(child < _a.size())
		{
			Comper com;
			//�ҵ����Һ����нϴ��
			if((child+1) < _a.size() && com(_a[child+1],_a[child]))
			{
				++child;
			}
			//�ȽϽϴ����븸��
			if(com(_a[child],_a[parent]))
			{
				swap(_a[child],_a[parent]);
				parent = child;
				child = parent*2+1;
			}
			else
			{
				break;
			}
		}
	}

	void _ApHeapUp(size_t child)
	{
		size_t parent = (child-1)/2;
		Comper com;
		while(child > 0)
		{
			if(com(_a[child],_a[parent]))//�ȽϺ����븸��
			{
				swap(_a[child],_a[parent]);
				child = parent;
				parent = (child-1)/2;
			}
			else
			{
				break;
			}
		}
	}
	
protected:
	vector<T> _a;
};

