#include <iostream>
#include<list>
#include<string>
//#include<Integer>
using namespace std;

#define PROPERTY_OWNER ExampleClass
#include "Property.h"

class ExampleClass
{
public:
	ReadOnlyProperty<string> m_strA;
	ReadOnlyProperty<list<int>> m_listA;
	ReadOnlyProperty<int> m_nA;
	
	void test()
	{
		m_strA = "abcd";
		m_nA = 13;
		m_listA = list<int>();
	}
};

int main()
{
	ExampleClass a;
	
	a.m_strA.append("abnc");
	cout << a.m_strA<< "\t"<<a.m_strA.length() << endl;
	
	
	for(int i=5;i<10;i++)
		a.m_listA.push_back(i);
	
	a.test();
	for (int i = 5; i<10; i++)
		a.m_listA.push_back(i);
	
	while(true)
	{
		if (a.m_listA.empty())
			break;
		cout << a.m_listA.back() << endl;
		a.m_listA.pop_back();
	}
	cout << "Empty: "<<a.m_listA.empty() << endl;
	cout << a.m_strA << endl;
	cout << a.m_nA << endl;

	getchar();
	return 0;
}