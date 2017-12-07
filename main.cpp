#include <iostream>
#include<list>
#include<string>

using namespace std;

#include "Property.h"

class ExampleClass
{
public:
	property_block(string) {
		property_set(string)
		get_override(string)
		{
			cout << "string access test" << endl;
			return this->m_data;
		}
//		write_in_class(string, ExampleClass)
	} m_strA;
	
	property(list<int>, ExampleClass) m_listA;

	property_block(int) {
		//property_set(int)
		property_get(int)
		write_in_class(int, ExampleClass)
	} m_nA;
	
	void test()
	{
		m_strA="abcd";
		m_nA=13;
		m_listA = list<int>();
	}
};

int main()
{
	ExampleClass a;
	a.test();
	a.m_strA = "abcd";
	
	a.m_strA().append("abnc");
	cout << a.m_strA()<< "\t"<<a.m_strA().length() << endl;
	for(int i=5;i<10;i++)
		a.m_listA().push_back(i);
	a.m_listA = list<int>();
	a.test();
	
	for (int i = 5; i<10; i++)
		a.m_listA().push_back(i);
	
	while(true)
	{
		if (a.m_listA().empty())
			break;
		cout << a.m_listA().back() << endl;
		a.m_listA().pop_back();
	}
	cout << "Empty: "<<a.m_listA().empty() << endl;
	cout << a.m_strA() << endl;
	cout << a.m_nA << endl;	
	getchar();
	return 0;
}