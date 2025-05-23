#pragma once

template <typename T>
class Node
{
public:
    // Данные.
    T m_data;

    // Адрес следующего элемента списка.
    Node* m_next;

    // Адрес предыдущего элемента списка.
    Node* m_previous;

    // Конструктор.
    explicit Node(const T& data) : m_data(data), m_next(nullptr), m_previous(nullptr) {}
};
