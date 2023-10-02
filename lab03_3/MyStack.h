#pragma once
#include"Exception_Handling.h"
#include"stdafx.h"
template<class T, int size>  class MyStack {
	T array[size];
	int number;
public:
	MyStack();
	T Pop();
	void Push(const T& value);
	int GetSize();
	int Capacity();
	T operator[](int num);
};

template <class T, int size> MyStack<T, size>::MyStack() {
	number = 0;
}
template <class T, int size> void MyStack<T, size>::Push(const T& value) {
	if (number >= size) {
		throw StackOverflow(number, size);
	}
	array[number] = value;
	number++;
}
template <class T, int size> T MyStack<T, size>::Pop() {
	if ((number - 1) < 0) {
		throw StackUnderflow(number);
	}
	T &tmp = array[number];
	number--;
	return tmp;
}
template<class T, int size> int MyStack<T, size>::GetSize() {
	return number;
}
template<class T, int size>  int MyStack<T, size>::Capacity() {
	return size;
}
template< class T, int size> T MyStack<T, size>::operator[](int num) {
	if (num < 0 || num >= size) {
		throw StackOutOfRange();
	}
	return array[num];
}
