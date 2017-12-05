#pragma once

#ifndef PROPERTY_OWNER
#error "PROPERTY_OWNER not defined"
#endif

class PROPERTY_OWNER;

template <class T>
class Writable {
public:
	inline virtual T& operator=(const T& input) = 0;
};

template< typename T, bool lr = !std::is_fundamental<T>::value>
class ReadOnlyProperty;


template<class T>
class ReadOnlyProperty<T, true> : public T
{
protected:
	inline virtual T& operator=(const T& input)
	{
		return (((T&)(*this)) = input);
	}
public:
	inline virtual operator T() const
	{
		return *(T*)this;
	}
	friend PROPERTY_OWNER;
};

template<typename T>
class ReadOnlyProperty<T, false>
{
protected:
	T data;
	inline virtual T& operator=(const T& input)
	{
		return (this->data = input);
	}
public:
	inline virtual operator T() const
	{
		return data;
	}
	friend PROPERTY_OWNER;
};

template< typename T, bool lr = !std::is_fundamental<T>::value >
class Property;


template<class T>
class Property<T, true> : public ReadOnlyProperty<T, true>, public  Writable<T>
{
public:
	inline virtual T& operator=(const T& input)
	{
		return (((T&)(*this)) = input);
	}

	inline virtual operator T&() const
	{
		return *((T*)this);
	}
};

template<class T>
class Property<T, false> : public ReadOnlyProperty<T, false>, public  Writable<T>
{
public:
	inline virtual T& operator=(const T& input)
	{
		return (this->data = input);
	}
};