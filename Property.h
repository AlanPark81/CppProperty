#pragma once

template <typename T>
class Property
{
protected:
	T m_data;
public:
	Property() {}
	Property(T input) : m_data(input) {}
protected:
	inline virtual T& set(const T& input)
	{
		this->m_data = input;
		return this->m_data;
	}

	inline virtual T& operator=(const T& input)
	{
		return set(input);
	}

	inline virtual T& get()
	{
		return this->m_data;
	}

	inline virtual T& operator() ()
	{
		return get();
	}

	/*inline virtual T& operator() (const T& input)
	{
		return set(input);
	}*/

	inline virtual operator T&()
	{
		return get();
	}	
};

#define property_block(type) class : public Property<type>

#define property_get_set(type) public:\
	using Property<type>::operator=;\
	using Property<type>::operator type&;\
	using Property<type>::operator();\

#define property_set(type) public:\
using Property<type>::operator=; \

#define property_get(type) public:\
	using Property<type>::operator type&;\
	using Property<type>::operator();\

#define write_in_class(type1,type) friend type; protected: 	using Property<type1>::operator=;

#define set_override(type) public:\
	using Property<type>::operator=;\
	type& set(const type& input)

#define get_override(type) public:\
	using Property<type>::operator type&;\
	using Property<type>::operator();\
	type& get()

#define property(type, type1) class : public Property<type>\
{\
public:\
	using Property<type>::operator=;\
	using Property<type>::operator type&;\
	using Property<type>::operator();\
}

#define readonly_property(type, type1) class : public Property<type>\
{\
protected:\
	using Property<type>::operator=;\
public:\
	friend type1;\
	using Property<type>::operator type&;\
	using Property<type>::operator();\
}
