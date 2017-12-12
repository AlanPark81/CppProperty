#include <iostream>
#include<list>

using namespace std;

#include "Property.h"

class ExampleClass
{
public:
    property(string, ExampleClass, m_strA)
    (
            get(string)
                    {
                        return value;
                    }
            ,set(string)
                    {
                        return value;
                    }
    );
    property(list<int>, ExampleClass, m_listA)
    (
            default_get(list<int>)
            ,default_set(list<int>)
	);
    property(int, ExampleClass, m_nA)
	(
            default_get(int)
	);

	void test()
	{
		m_strA("abcd");
		m_nA(13);
		m_listA(list<int>());
	}
};

int main()
{
    //function func{main};
    //func();
	ExampleClass a;
	a.test();
	a.m_strA() = "abcd";
    a.m_strA().append("abnc");
	cout << a.m_strA()<< "\t"<<a.m_strA().length() << endl;
	for(int i=5;i<10;i++)
		a.m_listA().push_back(i);
	a.m_listA() = list<int>();
	//a.test();

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
	//getchar();
	return 0;
}