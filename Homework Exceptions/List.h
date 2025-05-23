#pragma once

#include "Node.h"
#include <iostream>
#include <stdexcept>
using namespace std;
/*
Задание 1
Добавьте в класс двусвязного списка механизм обработки исключений. На ваш выбор генерируйте исключения в случае ошибок. Например, нехватка памяти, попытка удаления из пустого списка и т.д.

*/
template <typename T>
class List
{
    // Голова.
    Node<T>* m_head;
    // Хвост.
    Node<T>* m_tail;

    // Количество элементов.
    unsigned int m_size;

public:
    // Конструкторы и деструктор.
    List();
    List(const List& list);
    ~List();

    // Оператор присваивания.
    List& operator=(const List& right);

    // Методы добавления.
    void AddToHead(const T& data);
    void AddToTail(const T& data);

    // Копирование списка.
    void Assign(const List& list);

    // Вставка элемента.
    void Insert(const T& data, unsigned int index);

    // Получение элемента по индексу.
    Node<T>* NodeAt(unsigned int index) const;

    // Печать списка.
    void PrintHead() const;
    void PrintTail() const;

    // Удаление элементов.
    void DeleteAll();
    void RemoveAt(unsigned int index);
    void DeleteFromHead();
    void DeleteFromTail();

    // Получение размера списка.
    unsigned int GetSize() const;

    int Find(const T data) const;
    void Reverse();

};

// Реализация методов.

template <typename T>
List<T>::List() : m_head(nullptr), m_tail(nullptr), m_size(0U) {}

template <typename T>
List<T>::List(const List& list) : m_head(nullptr), m_tail(nullptr), m_size(0U)
{
    Assign(list);
}

template <typename T>
List<T>::~List()
{
    DeleteAll();
}

template <typename T>
List<T>& List<T>::operator=(const List& right)
{
    if (this != &right)
    {
        Assign(right);
    }
    return *this;
}

template <typename T>
void List<T>::AddToHead(const T& data)
{    
    try {
    Node<T>* node = new Node<T>(data);

    if (m_size > 0)
    {
        m_head->m_previous = node;
        node->m_next = m_head;
        m_head = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }

    ++m_size;
    }
    catch (const bad_alloc& e) {
		throw runtime_error("Memory allocation failed: " + string(e.what()));
    }
    catch (...) {
        cout << "An unknown error occurred." << endl;
	}
}

template <typename T>
void List<T>::AddToTail(const T& data)
{
    try {

    Node<T>* node = new Node<T>(data);

    if (m_size > 0U)
    {
        m_tail->m_next = node;
        node->m_previous = m_tail;
        m_tail = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }

    ++m_size;
    }
	catch (const bad_alloc& e) {
        throw runtime_error("Memory allocation failed: " + string(e.what()));
    }
    catch (...) {
        cout << "An unknown error occurred." << endl;
    }
}

template <typename T>
void List<T>::Assign(const List& list)
{
    DeleteAll();

    Node<T>* node = list.m_head;

    while (node != nullptr)
    {
        AddToTail(node->m_data);
        node = node->m_next;
    }
}

template <typename T>
void List<T>::Insert(const T& data, unsigned int index)
{
    if (index > m_size)
    {
        throw out_of_range("Index out of range.");
	}

    if (index == 0U)
    {
        AddToHead(data);
    }
    else if (index == m_size - 1U)
    {
        AddToTail(data);
    }
    else
    {
        Node<T>* current = NodeAt(index);

        Node<T>* node = new Node<T>(data);

        node->m_previous = current->m_previous;
        node->m_next = current;

        current->m_previous->m_next = node;
        current->m_previous = node;

        ++m_size;
    }
    
}

template <typename T>
Node<T>* List<T>::NodeAt(unsigned int index) const
{
    if (index >= m_size)
    {
        throw out_of_range("Index out of range.");
    }
    Node<T>* node = nullptr;

    if (index <= m_size / 2U)
    {
        node = m_head;

        unsigned int i = 0U;

        while (i < index)
        {
            node = node->m_next;
            i++;
        }
    }
    else
    {
        node = m_tail;

        unsigned int i = m_size - 1U;

        while (i > index)
        {
            node = node->m_previous;
            i--;
        }
    }
    
    return node;    
}

template <typename T>
void List<T>::PrintHead() const
{
    Node<T>* current = m_head;

    while (current != nullptr)
    {
        cout << current->m_data<<" ";

        current = current->m_next;

    }

    cout << endl;
}

template <typename T>
void List<T>::PrintTail() const
{
    Node<T>* current = m_tail;
    int ind = m_size - 1;
    while (current != nullptr)
    {
        cout << current->m_data;

        current = current->m_previous;
        ind--;
}

cout << endl;
}

template <typename T>
void List<T>::DeleteAll()
{
    while (m_head != nullptr)
    {
        DeleteFromHead();
    }
}

template <typename T>
void List<T>::RemoveAt(unsigned int index)
{
    if (index >= m_size)
    {
        throw out_of_range("Index out of range.");
    }
    if (index == 0U)
    {
        DeleteFromHead();
    }
    else if (index == m_size - 1U)
    {
        DeleteFromTail();
    }
    else
    {
        Node<T>* removeElement = NodeAt(index);

        removeElement->m_previous->m_next = removeElement->m_next;
        removeElement->m_next->m_previous = removeElement->m_previous;

        delete removeElement;

        --m_size;
    }
   
}

template <typename T>
void List<T>::DeleteFromHead()
{
    if (m_head == nullptr){
        throw out_of_range("List is empty. Cannot delete from head.");
    }

    Node<T>* temp = m_head;

    m_head = m_head->m_next;

    if (m_head != nullptr)
    {
        m_head->m_previous = nullptr;
    }
    else
    {
        m_tail = nullptr;
    }

    delete temp;

    --m_size;

}

template <typename T>
void List<T>::DeleteFromTail()
{
    if (m_tail == nullptr){
        throw out_of_range("List is empty. Cannot delete from tail.");
	}

    Node<T>* node = m_tail;

    m_tail = m_tail->m_previous;

    if (m_tail != nullptr)
    {
        m_tail->m_next = nullptr;
    }
    else
    {
        m_head = nullptr;
    }

    delete node;

    --m_size;
    
}

template <typename T>
unsigned int List<T>::GetSize() const
{
    return m_size;
}

template<typename T>
inline int List<T>::Find(const T data) const
{
    Node<T>* forward = m_head;  // Указатель для движения от головы
    Node<T>* backward = m_tail; // Указатель для движения от хвоста
    int forwardPosition = 0;    // Позиция при движении от головы
    int backwardPosition = m_size - 1; // Позиция при движении от хвоста

    while (forward != nullptr && backward != nullptr && forwardPosition <= backwardPosition)
    {
        // Проверяем узел при движении от головы
        if (forward->m_data == data)
        {
            return forwardPosition;
        }   

        // Проверяем узел при движении от хвоста
        if (backward->m_data == data)
        {
            return backwardPosition;
        }

        // Двигаемся вперед и назад
        forward = forward->m_next;
        backward = backward->m_previous;
        ++forwardPosition;
        --backwardPosition;
    }

    // Если элемент не найден, возвращаем -1
    return -1;
}


template<typename T>
inline void List<T>::Reverse()
{
    if (m_head == nullptr) {
		throw logic_error("List is empty. Cannot reverse.");
    }

    Node<T>* current = m_head;
    Node<T>* temp = nullptr;


    while (current != nullptr)
    {
        temp = current->m_previous;
        current->m_previous = current->m_next;
        current->m_next = temp;
        current = current->m_previous;
    }


    temp = m_head;
    m_head = m_tail;
    m_tail = temp;
}
