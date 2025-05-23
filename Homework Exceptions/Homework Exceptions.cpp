#include <iostream>
#include "List.h"
using namespace std;
/*
Исключения
Задание 1
Добавьте в класс двусвязного списка механизм обработки исключений. На ваш выбор генерируйте исключения в случае ошибок. Например, нехватка памяти, попытка удаления из пустого списка и т.д.

Задание 2
Создайте иерархию пользовательских классов-исключений. В ней должны быть классы для разных ситуаций. В качестве предметной области используйте ваши практические и домашние задания. Например, должны присутствовать классы для обработки всевозможных математических ошибок, нехватки памяти, проблемам по работе с файлами и т.д.
*/

int main()
{
    List<int> list;
    try {
        list.DeleteFromHead();
    }
    catch (const std::exception& ex) {
        cout << "Exception caught (DeleteFromHead): " << ex.what() << endl;
    }

    try {
        list.AddToHead(10);
        list.AddToTail(20);
        list.AddToTail(30);
        cout << "List after adding elements (PrintHead): ";
        list.PrintHead();

        list.RemoveAt(1); 
        cout << "List after RemoveAt(1): ";
        list.PrintHead();

        list.DeleteFromTail();
        cout << "List after DeleteFromTail: ";
        list.PrintHead();

        list.DeleteFromHead();
        cout << "List after DeleteFromHead: ";
        list.PrintHead();

        list.DeleteFromTail();
    }
    catch (const std::exception& ex) {
        cout << "Exception caught: " << ex.what() << endl;
    }

    try {
        list.AddToHead(100);
        cout << "Element at index 5: " << list.NodeAt(5)->m_data << endl;
    }
    catch (const std::exception& ex) {
        cout << "Exception caught (NodeAt): " << ex.what() << endl;
    }

    try {
        list.DeleteAll();
        list.Reverse();
    }
    catch (const std::exception& ex) {
        cout << "Exception caught (Reverse): " << ex.what() << endl;
    }

	system("pause");
	system("cls");
    return 0;
}