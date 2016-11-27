/**
*	@file : Node.cpp
*	@author :  Victor Berger da Silva
*	@date : 
* 
*/

#include "Node.h"

template <typename T>
Node<T>::Node()
{
    this->m_left = nullptr;
    this->m_right = nullptr;
    this->m_rank = 0;
}

template <typename T>
void Node<T>::setValue(int i)
{
    this->m_value = i;
}

template <typename T>
int Node<T>::getValue()
{
    return this->m_value;
}

template <typename T>
void Node<T>::setLeft(Node<T>* left)
{
    this->m_left = left;
}

template <typename T>
Node<T>* Node<T>::getLeft()
{
    return this->m_left;
}

template <typename T>
void Node<T>::setRight(Node<T>* right)
{
    this->m_right = right;
}

template <typename T>
Node<T>* Node<T>::getRight()
{
    return this->m_right;
}

template <typename T>
int Node<T>::getRank()
{
    return this->m_rank;
}

template <typename T>
void Node<T>::setRank(int r)
{
    this->m_rank = r;
}
