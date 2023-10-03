#include"Exception_Handling.h"
#include"stdafx.h"
StackOverflow::StackOverflow(int index, int high):exception("StackOverflow") {
	m_index = index;
	m_high = high;
}

void StackOverflow::what_v2(){
	cout<<"\n" << this->what();
	cout << "\nindex = " <<m_index<< " high = "<< m_high<<endl;
}

StackUnderflow::StackUnderflow(int i): exception("StackUnderflow") {
	m_index = i;
}

void StackUnderflow::what_v2() {
	cout<<"\n" << this->what();
	cout << "\nindex = " << m_index<<endl;
}

//const char* StackUnderflow::what() const noexcept
//{
//	return "StackUnderflow";
//}

StackOutOfRange::StackOutOfRange(): exception("StackOutOfRange")
{
}
