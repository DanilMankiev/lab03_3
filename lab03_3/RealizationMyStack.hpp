//#pragma once
//#include"MyStack.h"
//#include"Exception_Handling.h"
//template <class T, int size> MyStack<T, size>::MyStack() {
//	number = 0;
//}
//template <class T, int size> void MyStack<T, size>::Push(const T& value) {
//	if (number >= size-1) {
//		throw StackOverflow(number,size);
//	}
//	array[number] = value;
//	number++;
//}
//template <class T, int size> T MyStack<T, size>::Pop() {
//	if ((number - 1) < 0) {
//		throw StackUnderflow(number);
//	}
//	T* tmp = &array[number];
//	array[number] = 0;
//	number--;
//	return *tmp;
//}
//template<class T, int size> int MyStack<T, size>::GetSize() {
//	return number;
//}
//template<class T, int size>  int MyStack<T, size>::Capacity() {
//	return size;
//}
//template< class T, int size> T MyStack<T, size>::operator[](int num) {
//	if (num < 0 || num >= size) {
//		throw StackOutOfRange();
//	}
//	return array[num];
//}