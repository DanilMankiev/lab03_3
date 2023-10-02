//=======================================================================
//	������������ �3. ������� �������. ������� �������. ����������� ������� �++.
//				��������� ����������.
//=======================================================================
//����������� ����������� ����� �� ������������ 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include"MyStack.h"
#include"Exception_Handling.h"
//============= ������ ������� ��� ������ � ������� ���������
template <class T> void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";

	// �������� ������ ����������
	typename T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); p++, i++)
		cout << endl << i + 1 << ". " << *p;
	cout << '\n';
}
template<typename T> void Swap(T& first, T& second) {
	T tmp = first;
	first = second;
	second = tmp;
}

bool Predicat(Vector& v) {
	Vector tmp(4, 4);
	if (v > tmp) return true; 
	else  return false; 
}
//bool Predicat1(string& ss) {
//	if (ss[0] == 'h') return true;
//	else return false;
//}


int main()
{
	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������� ������������ ���� ���������� - Swap().
	// ��������� ����������������� ���������� ������� � �������
	// ������������ ���� ���������.
	{
		int i = 1, j = -1;
		Swap(i, j);

		double a = 0.5, b = -5.5;
		Swap(a, b);

		Vector u(1, 2), w(-3, -4);
		Swap(u, w);

		// ���� �� ���������� ������� ����� MyString � ���������� ������,
		// �� ��������� �������� ���� ������ �������� ���������.

		MyString s1("Your fault"), s2("My forgiveness");
		Swap(s1, s2);
	}
	//===========================================================
	// ������� �������
	//===========================================================
	// �������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	// � �������� ������ ��� ����� ����� ���� ������ ������.
	// ��� ������� ������������� ������� ����� ����� ���� �����������
	// ��������-��������� �������
	// ������������� ���������� �� ������ �������� "Push" � "Pop","GetSize" � "Capacity"
	// �������������� - ����� ���� ����� �� ������� (operator[]).
	// ��� ����, ����� ������������� ���������� ���������� ���� �������� 
	// ������� ������������ �������������� ��������.

	// � ������� ������� MyStack �������� ���� ���������� ���� int, �����
	// ���� ���������� ���� double �, �������, ���� �� ���������� ���� Vector 
	// ���� �� ����������� ��� ������ ��� ��������� ����������,
	// �� ��������� �������� ������ ��������
	try
	{
		cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		//stack.Push(4);	// ����� ������ ���� "���������" ����������

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
		//stack.Pop();		// ����� ������ ���� "���������" ����������
		stack.Push(2);

		int i = stack[3];	// ����� ������ ���� "���������" ����������

		MyStack<Vector, 5> ptStack;

		cout << "\nVector Stack capacity: " << ptStack.Capacity();

		ptStack.Push(Vector(1, 1));
		ptStack.Push(Vector(2, 2));

		cout << "\nVector Stack pops: ";
		// ����������� ����� ������ Vector ��� ������ ��������
		//ptStack.Pop().Out();

		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow o)
	{
		o.what_v2();
	}
	catch (StackUnderflow o)
	{
		o.what_v2();
	}
	catch (StackOutOfRange o)
	{
		cout << "\n" << o.what() << endl;
	}

	//=======================================================================
	// ���������� ����������� ����������. ������������������ ���� vector
	//=======================================================================

	// �������� ������ ������ ����� �����. ������� ��� ������ � ������� ������ size(),
	// � ������� ������ push_back() ��������� ������ ������-���� ����������.
	// �������� ����� ������ ������� � �������� �������� ��� ���������.
	// � �������� ������ � �������� �� ������ ����� ���������� ������� �����������
	// ��������� (size()) ������ ����������� ��������� ���������� ��������� (max_size()),
	// � ����� ����������������� ������ (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	n = v.capacity();
	unsigned int z = v.max_size();

	// ��� ��� �� ����� ����� �������� ������������������, �� �������������
	// ������� ������ ������� ��� ������ ������ ����������.
	// ��������������� ���� ������ �������� (pr), ������� �������� ����
	// ����������� ��� ��� ������ ������ �������

	pr(v, "Vector of ints");

	// ���������� ������ ����������� ��� �������� ������� ������������
	// � ��������� �������� � 2 �������� � ����������� (222.).
	// �������� ��������� �������. ����� ������� ������ ������� � ��� ����������
	// (����� - resize()) � ����� �������� ���������.

	vector<double> vd(2, 222.);
	pr(vd, "Vector of doubles");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	vd.resize(10, 10);

	pr(vd, "After resize");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	// ��������� ����� at(), � ����� �������� ������ [], �������� ��������
	// ��������� ��������� ������� � ��������� ���������.
	vd[3] = -123;
	pr(vd, "After at");

	// �������� ������ ������������, ������� �������� ������ �������������.
	vector<double> wd(vd);
	pr(wd, "Copy");

	// �������� ������, ������� �������� ����� ������������ ������������������
	vector<double> ud(vd.begin(), vd.begin() + 5);
	pr(ud, "Copy part");

	// �������� ������ ������������, ������� �������� ������ ����� �������� �������.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar, (ar + 5));
	pr(va, "Copy part of array");

	// �������� ������ ��������, ������� �������� ������ ����� ������� ������
	char s[] = "Array is a succession of chars";

	vector<char> vc((s + 11), (s + 21));
	pr(vc, "Copy part of c-style string");

	// �������� ������ ��������� ���� Vector � ���������������
	// ��� �������� � ������������ (1,1).
	vector<Vector> vv(10, Vector(1, 1));

	cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++)
		vv[i].Out();

	// �������� ������ ���������� �� Vector � ��������������� ��� ��������
	// �������� ������ Vector
	Vector** mas = new Vector * [5];
	for (int i = 0; i < 5; i++) {
		mas[i] = new Vector(1, 2);
	}
	vector<Vector*> vp(mas, (mas + 4));

	cout << "\n\nvector of pointers to Vector\n"; for (int i = 0; i < 5; i++) {
		mas[i] = new Vector(1, 2);
	}

	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();
	for (int i = 0; i < 5; i++) {
		delete mas[i];
	}
	delete[] mas;
	// ��������� ������������ ������� assign � ���������
	// ������������ = ��� ����������� ���� vector.
	Vector** mas1 = new Vector * [5];
	for (int i = 0; i < 5; i++) {
		mas1[i] = new Vector(2, 3);
	};
	vp.assign(mas1, (mas1 + 5));

	cout << "\n\nAfter assign\n";
	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	// ������������ ����� ������ ���������� �� Vector � ��������������� ��� 
	// � ������� ������ ������ assign
	vector<Vector*> vpNew;
	vpNew = vp;

	cout << "\n\nNew vector after assign\n";
	for (int i = 0; i < vpNew.size(); i++)
		vpNew[i]->Out();
	for (int i = 0; i < 5; i++) {
		delete mas1[i];
	}
	delete[] mas1;

	// �� ���� ������� vector �������� ���������� ������ �
	// ��������� ��� ���������� ������� ���������.
	// ������ ������� - ������������� �������
	// ������ ������� - ����������� �������

	//========= ������������� �������
	vector<vector<double>> vdc(10);
	for (int i = 0; i < vdc.size(); i++) {
		vdc[i] = vector<double>(vdc.size(), i);
		cout << endl;
		for (int j = 0; j < vdc.size(); j++) {
			cout << vdc[i][j] << "  ";
		}
	}

	//========= ����������� �������
	vector<vector<double>> vdd(10);
	for (int i = 0; i < vdd.size(); i++)
		vdd[i] = vector<double>(i + 1, double(i));

	cout << "\n\n\tTest vector of vector<double>\n";
	for (int i = 0; i < vdd.size(); i++)
	{
		cout << endl;
		for (int j = 0; j < vdd[i].size(); j++)
			cout << vdd[i][j] << "  ";
	}

	//===================================
	// ���������� �������� � ������������
	//===================================
	//3�. ��������� �������� ������� � ���������� ��������� ������������������.
	//��������� ������� ������������������. ������������ ��������
	//��������� ����� ������������������ ��������� ������ - assign().

	//�������� � ������������������ ������ �� ��������� char. ������ -
	//�� �������.
	vector<char> ch(10, 'A');
	char cMas[6] = { 'H','e','l','l','o' };

	//�������� �������� ������� �������� ������� ( front() )
	char tmp = ch.front();

	//�������� �������� ���������� �������� ������� ( back() )
	tmp = ch.back();

	//�������� ������ �������
	int r = ch.size();

	//��������� ������� ����� �������� �� �������� ������� cMas.
	ch.assign(cMas, cMas + 4);

	//��������� ������ �������, ������ � ��������� ��������.
	r = ch.size();
	tmp = ch.front();
	tmp = *ch.begin();
	tmp = ch.back();

	//3�. ������ � ������������ ��������� ������� � ��������� - at()
	//� ��� �������� - []
	//�������� �������������������� ������ �� 8 ��������� char - vChar2.
	//� ������� at() ��������� ������ ��������� ������� ��������
	//��������� vChar1 �� ����������� �������,
	//� � ������� [] ��������� �������� ��������� ������� vChar2 ��������
	//������� {'K','U','K','U'}.
	char cMas2[5] = {'K','U','K','U'};

	vector<char>vChar2(8);
	for (int i = 0; i < vChar2.size(); i++){
		if (!(i % 2)) vChar2[i] = cMas[i/2];
		else vChar2[i] = cMas2[i/2];
	}
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. �������� ��������: ��� ���������� ���
	//������� ��������� � ��������������� �������� � ����� �������
	// vChar2.at(8);   unhandled exception
	// vChar2[12];  run-time library exception
	

	//3�.�������� � ����� ������� vChar2  - ����� Z (push_back()). ���
	//���������� ��������� ������ �� ����� �� � �������� (pop_back())
	vChar2.push_back('Z');
	vChar2.pop_back();

	stop;

	//3�. �������-�������� �������� ������������������ insert() - erase()
	//������� ������������������ - clear()

	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	auto it = vChar2.begin();
	while (it != vChar2.end()-1) {
		it = vChar2.insert(it, 'W');
		it+=2;
	}

	//�������� ����� 5-�� ��������� ������� vChar2 3 ����� 'X'
	vChar2.insert(vChar2.begin() + 5, 3,'X');
	//�������� ����� 2-�� ��������� ������� vChar2 � �������� ��
	//������ �������� ������� "aaabbbccc"
	const char* maschar = "aaabbbccc";
	vChar2.insert(vChar2.begin() + 1, maschar + 2, maschar + 6);


	//������� c ������� �� ������� �������� vChar2
	vChar2.erase(vChar2.begin(), vChar2.begin() + 10);

	stop;

	//���������� ��� �������� ������������������ - clear()
	vChar2.clear();
	stop;

	//�������� ����������� �������
	vector<vector<double>> massive2(10);
	for (int i = 0; i < 10; i++) {
		massive2[i] = vector<double>(10, 10);
	}
	stop;

	///////////////////////////////////////////////////////////////////
	
		//������� 4. ������. ��������, ����������� ��� �������.
		//�������� ��� ������ ������ �� ��������� Vector - ptList1 �
		//ptList2
	list<Vector> ptList1;
	list<Vector> ptList2;

	//	//��������� ��� ������ ���������� � ������� ������� push_back(),
	//	//push_front, insret()
	ptList1.insert(ptList1.begin(), 2, Vector(1, 1));
	ptList1.push_front(Vector(10, 12));
	ptList1.push_back(Vector(23, 21));
	ptList2.insert(ptList2.begin(), 2, Vector(2, 2));
	ptList2.push_front(Vector(15, 17));
	ptList2.push_back(Vector(23, 21));




		//������������ ������ - sort().
		//���������: ��� ����, ����� �������� ����������, � ������ Vector
		//������ ���� ������������� �������� "<"
	ptList1.sort();
	ptList2.sort();

		stop;

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� �� ������ �������.
		ptList1.merge(ptList2);

		stop;

		//���������� �������� �� ������ - remove()
		//��������� �� ������ ������� � ������������ ���������.
		//���������: ��� ����� ���������� ����� ��������������
		//� ������ Vector �������� "=="
		ptList1.remove(Vector(23, 21));

		stop;
	
	///////////////////////////////////////////////////////////////////
	
		//������� 5. ����������� ���������.���������� ������������ ����
		// <algorithm>
		//5�. �������� �� ����� �������� ptList1 �� �����������
		//������� � ������� ��������� for_each()
		
		for_each(ptList1.begin(), ptList1.end(),[](Vector& i) {
			i.Out();
			});

		stop;

		//5�.� ������� ��������� find() ������� �������� �� ������� Vector �
		//������������ ���������. � ������� ��������� find_if() �������
		//�������� �� �������, ��������������� ������������� �������,
		//��������, ��� ���������� ����� ������ ���� ������ 2.
		//���������: �������� �������-��������, ������� ��������� �������
		//� ���������� boolean-�������� (�������� ����� ���� ��� ����������
		//��������, ��� � ������� ������)
		
		auto it12s = find(ptList1.begin(), ptList1.end(), Vector(15, 17));
		list<Vector>::iterator sdmfp = find_if(ptList1.begin(), ptList1.end(), Predicat);


		  stop;

		//�������� ������ �� ���������� �� ������� Vector. � �������
		//��������� find_if() � ��������� (����� ������������ �������� -
		//����� ������ Vector, ������������ � ���������� �������) ������� �
		//������������������ �������, ��������������� �������



		  stop;

		//5�. �������� ������ ��������� Vector. ��������� ������
		//����������. � ������� ��������� replace() �������� �������
		//� ������������ ��������� ����� ���������. � ������� ���������
		//replace_if() �������� �������, ��������������� ������-����
		//������� �� ������������ ��������. ���������: �������
		//�������� ����������.
		  list<Vector> list3(10, Vector(1, 3));
		  list3.push_back(Vector(10, 21));
		  list3.push_back(Vector(50, 59));
	  //������������ �������� ��������� ������
		  replace(list3.begin(), list3.end(), Vector(10, 21),Vector(34,32));
		  replace_if(list3.begin(), list3.end(), [](auto& it) {return !(it) > 50 ? true : false; }, Vector(13, 17));
		

		stop;


		//5�. �������� ������ ����� (string). � ������� ��������� count()
		//���������� ���������� ���������� �����. � ������� ���������
		//count_if() ���������� ���������� �����, ������������ � ��������
		//�����
		vector<string> vvs(10,"string");
		vvs.push_back("hello");
		vvs.push_back("hamster");
		vvs.push_back("world");;
		int count1 = count(vvs.begin(), vvs.end(), "string");
		char ch1 = 'h';
		count1 = count_if(vvs.begin(), vvs.end(), [&](string& it) {return it[0] == ch1 ? true : false; });

		//5�. � ������� ��������� count_if() ���������� ���������� �����,
		//������� ��������� � �������� �������. ���������: ������ ����
		//�������-�������
		string ss = "world";
		count1 = count_if(vvs.begin(), vvs.end(), [&](string& s) {return s == ss ? true : false; });
		stop;
	

	cout << "\n\n";
};