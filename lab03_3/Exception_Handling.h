#pragma once
#include<exception>
class StackOverflow:public std::exception {
	int m_index;
	int m_high;
public:
	StackOverflow(int index,int high);
	void what_v2();

};
class StackUnderflow : public std::exception {
	int m_index;
public:
	StackUnderflow(int i);
	void what_v2();
	//virtual const char * what() const  noexcept override;
};
class StackOutOfRange : public std::exception{
public:
	StackOutOfRange();
};