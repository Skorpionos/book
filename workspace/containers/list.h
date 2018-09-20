#pragma once

#include <vector>

#include <iostream>

namespace user
{

template <class T>
class ListIterator;

template <class T>
class list
{
public:
//    struct Node;
    list();
    void push_front(T data);
    void push_back(T data);
    void pop_front();
    void pop_back();
    void clear();
    T& first();
    T& last();
    T& operator[](const size_t index);
    void insert(const size_t insertIndex, const T& data);
    void remove(const size_t removeIndex);
    void remove(ListIterator<T> it);
    void remove_first(const T& data);
    void remove_all(const T& data);
    inline bool empty();
    inline size_t size();
    size_t count(const T& data);

    ListIterator<T> begin();
    ListIterator<T> end();
    ListIterator<T> get_at(const size_t index);
    ListIterator<T> find(const T& data);
    std::vector<ListIterator<T>> find_all(const T& data);

    void Print();

//private:
    struct Node
    {
        Node* next = nullptr;
        T data;

        Node(T data_, Node* next_ = nullptr)
                : data(data_)
                , next(next_) {}
    };

    size_t m_size = 0;
    Node* m_head = nullptr;
    Node* m_back = nullptr;

private:
    Node* get_node_at(const size_t index);
};

template <class T>
list<T>::list()
{
    m_size = 0;
}

template <class T>
void list<T>::push_front(T data)
{
    m_head = new Node(data, m_head);

    ++m_size;

    if (m_size == 1)
        m_back = m_head;
}

template <class T>
void list<T>::push_back(T data)
{
    auto node = new Node(data);

    if (m_size == 0)
        m_head = node;
    else
        m_back->next = node;

    m_back = node;
    ++m_size;
}

template <class T>
bool list<T>::empty()
{
    return m_size == 0;
}

template <class T>
size_t list<T>::size()
{
    return m_size;
}

template <class T>
void list<T>::Print()
{
    auto current = m_head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template <class T>
typename list<T>::Node* list<T>::get_node_at(const size_t index)
{
    if (index >= m_size)
        return nullptr;

    size_t currentIndex = 0;

    auto currentNode = m_head;

    while (currentIndex < index)
    {
        ++currentIndex;
        currentNode = currentNode->next;
    }

    return currentNode;
 }

template <class T>
T& list<T>::operator[](const size_t index)
{
    return get_node_at(index)->data;
}

template <class T>
ListIterator<T> list<T>::begin()
{
    return ListIterator<T>(m_head, 0);
}

template <class T>
ListIterator<T> list<T>::end()
{
    return ListIterator<T>(nullptr);
}

template <class T>
ListIterator<T> list<T>::get_at(const size_t index)
{
    return ListIterator<T>(get_node_at(index), index);
}

template <class T>
T& list<T>::first()
{
    return m_head->data;
}

template <class T>
T& list<T>::last()
{
    return m_back->data;
}

template <class T>
void list<T>::pop_front()
{
    if (m_head == nullptr)
        return;

    const auto nextNode = m_head->next;

    delete m_head;

    m_head = nextNode;

    --m_size;

    if (empty())
        m_back = nullptr;
}

template <class T>
void list<T>::pop_back()
{
    remove(m_size - 1);
//    if (empty())
//        return;
//
//    if (size() == 1)
//    {
//        delete m_head;
//        m_head = nullptr;
//        m_back = nullptr;
//        --m_size;
//        return;
//    }
//
//    auto currentNode = m_head;
//    while (currentNode->next->next != nullptr)
//        currentNode = currentNode->next;
//
//    delete currentNode->next;
//
//    currentNode->next = nullptr;
//    m_back = currentNode;
//
//    --m_size;
}

template <class T>
void list<T>::clear()
{
    while (size())
        pop_front();
}

template <class T>
void list<T>::insert(const size_t insertIndex, const T& data)
{
    if (insertIndex > size())
        return;

    if (insertIndex == 0)
        return push_front(data);

    auto previousNode = get_node_at(insertIndex - 1);

    previousNode->next = new Node(data, previousNode->next);

    ++m_size;
}

template <class T>
void list<T>::remove(const size_t removeIndex)
{
    if (removeIndex >= m_size)
        return;

    if (removeIndex == 0)
        return pop_front();

    auto previousNode = get_node_at(removeIndex - 1);

    const auto nodeToDelete = previousNode->next;

    previousNode->next = nodeToDelete->next;

    delete nodeToDelete;

    if (removeIndex == m_size - 1)
        m_back = previousNode;

    --m_size;
}

template <class T>
void list<T>::remove(ListIterator<T> it)
{
    this->remove(it.index);
}

template <class T>
void list<T>::remove_first(const T& data)
{
    const auto it = find(data);
    remove(it.index);
}

template <class T>
void list<T>::remove_all(const T& data)
{
    auto it = find(data);
    while (it != end())
    {
        remove(it);
        it = find(data);
    }
}

template <class T>
size_t list<T>::count(const T& data)
{
    size_t result = 0;
    for (const auto element : *this)
    {
        if (element == data)
            ++result;
    }
    return result;
}

template <class T>
using NodePtr = typename list<T>::Node*;

template <class T>
ListIterator<T> list<T>::find(const T& data)
{
    for (auto it = begin(); it != end(); ++it)
    {
        if (*it == data)
            return it;
    }
//    return nullptr;
    return ListIterator<T>();
}

template <class T>
std::vector<ListIterator<T>> list<T>::find_all(const T& data)
{
    std::vector<ListIterator<T>> results;

    for (auto it = begin(); it != end(); ++it)
    {
        if (*it == data)
            results.push_back(it);
    }

    return results;
}

template <class T>
class ListIterator
{
public:
    explicit ListIterator(NodePtr<T> node_ = nullptr, size_t index_ = 0)
            : node(node_)
            , index(index_) {}

    void operator++();
    ListIterator<T> operator+(const size_t delta) const;
    size_t operator-(const ListIterator& rhs);
    bool operator==(const ListIterator& rhs);
    bool operator!=(const ListIterator& rhs);
    T& operator*();

    NodePtr<T> node;
    size_t index;
};

template <class T>
void ListIterator<T>::operator++()
{
    if (node != nullptr)
    {
        node = node->next;
        ++index;
    }
}

template <class T>
ListIterator<T> ListIterator<T>::operator+(const size_t delta) const
{
    auto it = *this;
    for (size_t index = 0; index < delta; ++index)
        ++it;
    return it;
}

template <class T>
size_t ListIterator<T>::operator-(const ListIterator& rhs)
{
    return this->index - rhs.index;
}

template <class T>
bool ListIterator<T>::operator==(const ListIterator& rhs)
{
    return node == rhs.node;
}

template <class T>
bool ListIterator<T>::operator!=(const ListIterator& rhs)
{
    return node != rhs.node;
}

template <class T>
T& ListIterator<T>::operator*()
{
    return node->data;
}


} // namespace user
