#pragma once
#ifndef QUEUE
#define QUEUE

#include<iostream>
#include<stdexcept>
using namespace std;

template <typename TN>
struct Node {
	TN data;
	Node<TN>* next;
};

template <typename T>
class Queue {
	template<typename T>
	friend ostream& operator << (ostream& os, const Queue<T>& item);
public:
	Queue<T>();
	void enqueue(T da);
	T dequeue();
	void Clear();
	int length() { return count; }
	~Queue<T>();

private:
	Node<T>* rear;
	int count;
};
template <typename T>
Queue<T>::Queue() {
	rear = new Node<T>;
	rear->next = rear;
	count = 0;
}
template <typename T>
void Queue<T>::enqueue(T da) {
	Node<T>* n = new Node<T>;
	n->data = da;
	n->next = rear->next;
	rear->next = n;
	rear = rear->next;
	count++;
}
template <typename T>
T Queue<T>::dequeue() {
	if (count == 0)
		throw logic_error("you can not dequeue an empty queue !");
	Node<T>* temp = rear->next;
	T da = temp->data;
	rear->next = temp->next;
	delete temp;
	count--;
	return da;
}
template <typename T>
void Queue<T>::Clear() {
	Node<T>* head = rear->next;
	Node<T>* temp = head->next;
	while (temp != head) {
		Node<T>* te = temp;
		temp = temp->next;
		delete te;
	}
	rear = head;
	rear->next = rear;
	count = 0;
}
template <typename T>
Queue<T>::~Queue<T>() {
	Node<T>* temp = rear->next;
	while (temp != rear) {
		Node<T>* te = temp;
		temp = temp->next;
		delete te;
	}
	delete temp;
}

template <typename T>
ostream& operator << (ostream& os, const Queue<T>& item) {
	if (item.count == 0)
	{
		os << "the queue is empty!";
		return os;
	}
	Node<T>* temp =( item.rear)->next->next;
	while (temp != item.rear) {
		os << temp->data << " ";
		temp = temp->next;
	}
	os << temp->data;
	return os;
}
#endif // !QUEUE
