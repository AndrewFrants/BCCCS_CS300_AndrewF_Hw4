#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include "ItemNotFoundException.h"
using namespace std;

// List node item
template <class T>
struct node {
	T data;
	node* next;

	// Define this to make referenced locations
	// a bit shorter
	node(T& d, node* n) :
		data(d), next(n)
	{
	}
};

// Linked List ADT
template <class T>
class LinkedList {
private:
	LinkedList(const LinkedList&) = delete; //copy constructor

protected:
	int count;
	node<T> *head, *last;
public:
	// C'tor
	LinkedList();

	// isEmpty
	bool isEmpty();

	// length of the list
	int length();

	// top of the list
	T front();

	// back of the list
	T back();

	// insert an item into the list
	virtual void insert(T&);

	// search for an item in the list
	virtual T& search(T&);

	// insert from top
	void insertFirst(T&);

	// insert from back
	void insertLast(T&);

	// delete a node
	virtual void deleteNode(T&);

	// delete the list
	void destroylist();

	// Comparison op for list
	LinkedList<T>& operator=(LinkedList<T>&);

	// Print lis top
	template <class U>
	friend ostream& operator<<(ostream& os, LinkedList<U>& list);

	// D'tor
	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList() {
	head = last = NULL;
	count = 0;
}

template <class T>
bool LinkedList<T>::isEmpty() {
	return head == NULL;
}
template <class T>
int LinkedList<T>::length() {
	return count;
}

template <class T>
T LinkedList<T>::front() {
	return head->data;
}

template <class T>
T LinkedList<T>::back() {
	return last->data;
}

template <class T>
void LinkedList<T>::insert(T& item) {
	// we can reuse the same method
	this->insertFirst(item);
}

template <class T>
T& LinkedList<T>::search(T& item) {

	node<T> *currNode = head;

	while (currNode != nullptr)
	{
		if (item == currNode->data)
		{
			return currNode->data;
		}

		currNode = currNode->next;
	}

	throw ItemNotFoundException("item wasnt found");
}

template <class T>
void LinkedList<T>::insertFirst(T& item) {
	node<T> *temp = new node<T>(item, head);
	head = temp;
	count++;
	if (last == NULL) last = temp;

}
template <class T>
void LinkedList<T>::insertLast(T& item) {
	node<T> *newnode = new node<T>(item, nullptr);
	if (head == NULL) {
		head = last = newnode;
	}
	else {
		last->next = newnode;
		last = newnode;
	}
	count++;
}
template <class T>
void LinkedList<T>::deleteNode(T& item) {
	if (head == NULL)
		cerr << "empty list";
	else {
		if (head->data == item) {
			node<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if (head == NULL) last = NULL;
		}
		else {
			node<T>* p = head;
			node<T>* q = p->next;
			while (q != NULL && !(q->data == item)) {
				p = q;
				q = q->next;
			}
			if (q != NULL) {
				p->next = q->next;
				count--;
				if (last == q) last = p;
				delete q;
			}
		}
	}
}

template <class T>
void LinkedList<T>::destroylist() {
	node<T> *p;
	while (head != NULL) {
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list) {
	if (this != &list) {
		copylist(list);
	}
	return *this;
}


template <class T>
LinkedList<T>::~LinkedList() {
	destroylist();
}


#endif /* LINKEDLIST_H_ */
