//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include"MyStack.h"
#include"Exception_Handling.h"
//============= Шаблон функции для вывода с помощью итератора
template <class T> void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";

	// Итератор любого контейнера
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
	// Шаблоны функций
	//===========================================================
	// Создайте шаблон функции перестановки двух параметров - Swap().
	// Проверьте работоспособность созданного шаблона с помощью
	// приведенного ниже фрагмента.
	{
		int i = 1, j = -1;
		Swap(i, j);

		double a = 0.5, b = -5.5;
		Swap(a, b);

		Vector u(1, 2), w(-3, -4);
		Swap(u, w);

		// Если вы достаточно развили класс MyString в предыдущей работе,
		// то следующий фрагмент тоже должен работать корректно.

		MyString s1("Your fault"), s2("My forgiveness");
		Swap(s1, s2);
	}
	//===========================================================
	// Шаблоны классов
	//===========================================================
	// Создайте шаблон класса MyStack для хранения элементов любого типа T.
	// В качестве основы для стека может быть выбран массив.
	// Для задания максимального размера стека может быть использован
	// параметр-константа шаблона
	// Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
	// Необязательной - может быть выбор по индексу (operator[]).
	// Для того, чтобы гарантировать корректное выполнение этих операций 
	// следует генерировать исключительные ситуации.

	// С помощью шаблона MyStack создайте стек переменных типа int, затем
	// стек переменных типа double и, наконец, стек из переменных типа Vector 
	// Если вы подготовите три класса для обработки исключений,
	// то следующий фрагмент должен работать
	try
	{
		cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

		//stack.Push(4);	// Здесь должно быть "выброшено" исключение

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();

		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
		//stack.Pop();		// Здесь должно быть "выброшено" исключение
		stack.Push(2);

		int i = stack[3];	// Здесь должно быть "выброшено" исключение

		MyStack<Vector, 5> ptStack;

		cout << "\nVector Stack capacity: " << ptStack.Capacity();

		ptStack.Push(Vector(1, 1));
		ptStack.Push(Vector(2, 2));

		cout << "\nVector Stack pops: ";
		// Используйте метод класса Vector для вывода элемента
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
	// Контейнеры стандартной библиотеки. Последовательности типа vector
	//=======================================================================

	// Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
	// С помощью метода push_back() заполните вектор какими-либо значениями.
	// Получите новый размер вектора и выведите значения его элементов.
	// В процессе работы с вектором вы можете кроме количества реально заполненных
	// элементов (size()) узнать максимально возможное количество элементов (max_size()),
	// а также зарезервированную память (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	n = v.capacity();
	unsigned int z = v.max_size();

	// Так как мы часто будем выводить последовательности, то целесообразно
	// создать шаблон функции для вывода любого контейнера.
	// Проанализируйте коды такого шабдлона (pr), который приведен выше
	// Используйте его для вывода вашего вектора

	pr(v, "Vector of ints");

	// Используем другой конструктор для создания вектора вещественных
	// с начальным размером в 2 элемента и заполнением (222.).
	// Проверим параметры вектора. Затем изменим размер вектора и его заполнение
	// (метод - resize()) и вновь проверим параметры.

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

	// Используя метод at(), а также операцию выбора [], измените значения
	// некоторых элементов вектора и проверьте результат.
	vd[3] = -123;
	pr(vd, "After at");

	// Создайте вектор вещественных, который является копией существующего.
	vector<double> wd(vd);
	pr(wd, "Copy");

	// Создайте вектор, который копирует часть существующей последовательности
	vector<double> ud(vd.begin(), vd.begin() + 5);
	pr(ud, "Copy part");

	// Создайте вектор вещественных, который является копией части обычного массива.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar, (ar + 5));
	pr(va, "Copy part of array");

	// Создайте вектор символов, который является копией части обычной строки
	char s[] = "Array is a succession of chars";

	vector<char> vc((s + 11), (s + 21));
	pr(vc, "Copy part of c-style string");

	// Создайте вектор элементов типа Vector и инициализируйте
	// его вектором с координатами (1,1).
	vector<Vector> vv(10, Vector(1, 1));

	cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++)
		vv[i].Out();

	// Создайте вектор указателей на Vector и инициализируйте его адресами
	// объектов класса Vector
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
	// Научитесь пользоваться методом assign и операцией
	// присваивания = для контейнеров типа vector.
	Vector** mas1 = new Vector * [5];
	for (int i = 0; i < 5; i++) {
		mas1[i] = new Vector(2, 3);
	};
	vp.assign(mas1, (mas1 + 5));

	cout << "\n\nAfter assign\n";
	for (int i = 0; i < vp.size(); i++)
		vp[i]->Out();

	// Декларируйте новый вектор указателей на Vector и инициализируйте его 
	// с помощью второй версии assign
	vector<Vector*> vpNew;
	vpNew = vp;

	cout << "\n\nNew vector after assign\n";
	for (int i = 0; i < vpNew.size(); i++)
		vpNew[i]->Out();
	for (int i = 0; i < 5; i++) {
		delete mas1[i];
	}
	delete[] mas1;

	// На базе шаблона vector создание двухмерный массив и
	// заполните его значениями разными способами.
	// Первый вариант - прямоугольная матрица
	// Второй вариант - ступенчатая матрица

	//========= Прямоугольная матрица
	vector<vector<double>> vdc(10);
	for (int i = 0; i < vdc.size(); i++) {
		vdc[i] = vector<double>(vdc.size(), i);
		cout << endl;
		for (int j = 0; j < vdc.size(); j++) {
			cout << vdc[i][j] << "  ";
		}
	}

	//========= Ступенчатая матрица
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
	// Простейшие действия с контейнерами
	//===================================
	//3б. Получение значения первого и последнего элементов последовательности.
	//Получение размера последовательности. Присваивание значений
	//элементов одной последовательности элементам другой - assign().

	//Создайте и проинициализируйте вектор из элементов char. Размер -
	//по желанию.
	vector<char> ch(10, 'A');
	char cMas[6] = { 'H','e','l','l','o' };

	//Получите значение первого элемента вектора ( front() )
	char tmp = ch.front();

	//Получите значение последнего элемента вектора ( back() )
	tmp = ch.back();

	//Получите размер вектора
	int r = ch.size();

	//Присвойте вектору любой диапазон из значений массива cMas.
	ch.assign(cMas, cMas + 4);

	//Проверьте размер вектора, первый и последний элементы.
	r = ch.size();
	tmp = ch.front();
	tmp = *ch.begin();
	tmp = ch.back();

	//3в. Доступ к произвольным элементам вектора с проверкой - at()
	//и без проверки - []
	//Создайте неинициализированный вектор из 8 элементов char - vChar2.
	//С помощью at() присвойте четным элементам вектора значения
	//элементов vChar1 из предыдущего задания,
	//а с помощью [] присвойте нечетным элементам вектора vChar2 значения
	//массива {'K','U','K','U'}.
	char cMas2[5] = {'K','U','K','U'};

	vector<char>vChar2(8);
	for (int i = 0; i < vChar2.size(); i++){
		if (!(i % 2)) vChar2[i] = cMas[i/2];
		else vChar2[i] = cMas2[i/2];
	}
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. Обратите внимание: что происходит при
	//попытке обращения к несуществующему элементу в обоих случаях
	// vChar2.at(8);   unhandled exception
	// vChar2[12];  run-time library exception
	

	//3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
	//расширения кругозора можете ее сразу же и выкинуть (pop_back())
	vChar2.push_back('Z');
	vChar2.pop_back();

	stop;

	//3д. Вставка-удаление элемента последовательности insert() - erase()
	//Очистка последовательности - clear()

	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	auto it = vChar2.begin();
	while (it != vChar2.end()-1) {
		it = vChar2.insert(it, 'W');
		it+=2;
	}

	//Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'
	vChar2.insert(vChar2.begin() + 5, 3,'X');
	//Вставьте перед 2-ым элементом вектора vChar2 с третьего по
	//шестой элементы массива "aaabbbccc"
	const char* maschar = "aaabbbccc";
	vChar2.insert(vChar2.begin() + 1, maschar + 2, maschar + 6);


	//Сотрите c первого по десятый элементы vChar2
	vChar2.erase(vChar2.begin(), vChar2.begin() + 10);

	stop;

	//Уничтожьте все элементы последовательности - clear()
	vChar2.clear();
	stop;

	//Создание двухмерного массива
	vector<vector<double>> massive2(10);
	for (int i = 0; i < 10; i++) {
		massive2[i] = vector<double>(10, 10);
	}
	stop;

	///////////////////////////////////////////////////////////////////
	
		//Задание 4. Списки. Операции, характерные для списков.
		//Создайте два пустых списка из элементов Vector - ptList1 и
		//ptList2
	list<Vector> ptList1;
	list<Vector> ptList2;

	//	//Наполните оба списка значениями с помощью методов push_back(),
	//	//push_front, insret()
	ptList1.insert(ptList1.begin(), 2, Vector(1, 1));
	ptList1.push_front(Vector(10, 12));
	ptList1.push_back(Vector(23, 21));
	ptList2.insert(ptList2.begin(), 2, Vector(2, 2));
	ptList2.push_front(Vector(15, 17));
	ptList2.push_back(Vector(23, 21));




		//Отсортируйте списки - sort().
		//Подсказка: для того, чтобы работала сортировка, в классе Vector
		//должен быть переопределен оператор "<"
	ptList1.sort();
	ptList2.sort();

		stop;

		//Объедините отсортированные списки - merge(). Посмотрите: что
		//при этом происходит со вторым списком.
		ptList1.merge(ptList2);

		stop;

		//Исключение элемента из списка - remove()
		//Исключите из списка элемент с определенным значением.
		//Подсказка: для этого необходимо также переопределить
		//в классе Vector оператор "=="
		ptList1.remove(Vector(23, 21));

		stop;
	
	///////////////////////////////////////////////////////////////////
	
		//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
		// <algorithm>
		//5а. Выведите на экран элементы ptList1 из предыдущего
		//задания с помощью алгоритма for_each()
		
		for_each(ptList1.begin(), ptList1.end(),[](Vector& i) {
			i.Out();
			});

		stop;

		//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
		//определенным значением. С помощью алгоритма find_if() найдите
		//итератор на элемент, удовлетворяющий определенному условию,
		//например, обе координаты точки должны быть больше 2.
		//Подсказка: напишите функцию-предикат, которая проверяет условие
		//и возвращает boolean-значение (предикат может быть как глобальной
		//функцией, так и методом класса)
		
		auto it12s = find(ptList1.begin(), ptList1.end(), Vector(15, 17));
		list<Vector>::iterator sdmfp = find_if(ptList1.begin(), ptList1.end(), Predicat);


		  stop;

		//Создайте список из указателей на элеметы Vector. С помощью
		//алгоритма find_if() и предиката (можно использовать предикат -
		//метод класса Vector, определенный в предыдущем задании) найдите в
		//последовательности элемент, удовлетворяющий условию



		  stop;

		//5в. Создайте список элементов Vector. Наполните список
		//значениями. С помощью алгоритма replace() замените элемент
		//с определенным значением новым значением. С помощью алгоритма
		//replace_if() замените элемент, удовлетворяющий какому-либо
		//условию на определенное значение. Подсказка: условие
		//задается предикатом.
		  list<Vector> list3(10, Vector(1, 3));
		  list3.push_back(Vector(10, 21));
		  list3.push_back(Vector(50, 59));
	  //Сформировали значения элементов списка
		  replace(list3.begin(), list3.end(), Vector(10, 21),Vector(34,32));
		  replace_if(list3.begin(), list3.end(), [](auto& it) {return !(it) > 50 ? true : false; }, Vector(13, 17));
		

		stop;


		//5г. Создайте вектор строк (string). С помощью алгоритма count()
		//сосчитайте количество одинаковых строк. С помощью алгоритма
		//count_if() сосчитайте количество строк, начинающихся с заданной
		//буквы
		vector<string> vvs(10,"string");
		vvs.push_back("hello");
		vvs.push_back("hamster");
		vvs.push_back("world");;
		int count1 = count(vvs.begin(), vvs.end(), "string");
		char ch1 = 'h';
		count1 = count_if(vvs.begin(), vvs.end(), [&](string& it) {return it[0] == ch1 ? true : false; });

		//5д. С помощью алгоритма count_if() сосчитайте количество строк,
		//которые совпадают с заданной строкой. Подсказка: смотри тему
		//объекты-функции
		string ss = "world";
		count1 = count_if(vvs.begin(), vvs.end(), [&](string& s) {return s == ss ? true : false; });
		stop;
	

	cout << "\n\n";
};