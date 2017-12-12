#pragma once
#include<functional>

using namespace std;

template<typename T>
using Getter=std::function<T&(T&)>;

template<typename T>
using Setter=std::function<T(const T&)>;


template <typename T, typename T1>
class Property
{
protected:
	T m_data;
	const Getter<T> get;
    const Setter<T> set;
    inline virtual T& operator() (const T& input)
    {
        if(set)
            return m_data=set(input);
        else
            return m_data=input;
    }

public:
    Property(Getter<T> getInput=Getter<T>(), Setter<T> setInput=Setter<T>()) : get(getInput), set(setInput){}
	inline virtual T& operator=(const T& input)
	{
		return m_data=set(input);
	}

	inline virtual T& operator() ()
	{
		return get(m_data);
	}

	inline virtual operator T&()
	{
		return get(m_data);
	}
    friend T1;
};

#define get(T) (Getter<T>)[](T& value)->T&
#define set(T) (Setter<T>)[](const T& value)->T

#define default_get(T) (Getter<T>)[](T& value)->T& {return value;}
#define default_set(T) (Setter<T>)[](const T& value)->T {return value;}

#define property(T1, T2, V) Property<T1, T2> V=Property<T1, T2>

