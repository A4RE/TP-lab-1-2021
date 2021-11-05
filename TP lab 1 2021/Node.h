#pragma once
template <typename T>
class Node
{
public:

	T field;
	Node* next;
	Node* prev;
	Node();


};
template <typename T>
Node<T>::Node()
{
	this->field = 0;
	this->next = 0;
	this->prev = 0;
}

