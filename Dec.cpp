// Dec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "deque.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "for int:" << endl;
	deque <int> a;
	a.PushLast(1);
	a.PushLast(5);
	a.PushLast(8);
	a.PushLast(0);
	deque <int> a2 = a;
	a2.Print(cout);
	a.dsort();
	a.Print(cout);
	a.PrintReverse(cout);
	cout << "for double:" << endl;
	deque <double> d;
	d.PushLast(0.25);
	d.PushLast(4);
	d.PushFirst(3.5);
	d.PushLast(2.0);
	deque <double> d2 = d;
	d2.Print(cout);
	d.dsort();
	d.Print(cout);
	d.PrintReverse(cout);
	cout << "for char:" << endl;
	deque<const char*> ch;
	ch.PushLast("I");
	ch.PushLast("love");
	ch.PushLast("Anime");
	ch.PushLast("!");
	deque <const char*> ch2 = ch;
	ch.Print(cout);
	ch.PrintReverse(cout);
	ch.dsort();
	ch.Print(cout);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
