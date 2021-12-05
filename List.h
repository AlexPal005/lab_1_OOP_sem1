#pragma once
#include "Date.h"

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class List
{
private:
	Node<T>* Head;
	Node<T>* tail;
	int lenght;
	void quickSort(Node<T>* head, Node<T>* l);
	void SwapValue(Node<T>* a, Node<T>* b);
	Node<T>* Partition(Node<T>* start, Node<T>* end);
public:
	List() : Head(nullptr), tail(nullptr), lenght(0) {};
	~List();
	List(const List<T>& other);
	List <T>& operator=(const List <T>& other);
	bool empty() const;
	int size() const;
	void search(T d);
	void push(T d);
	void del_f();
	void clear();
	void quicksort();
	void bublesort();
	void insort();
	Node<T>* Insort(Node<T>* Head);
	void getList() const;
};

template <typename T>
inline void List<T>::getList() const
{
	if (Head)
	{
		Node<T>* tmp = Head;
		while (tmp != nullptr)
		{
			std::cout << tmp->data << " ";
			tmp = tmp->next;
		}
	}
}

template <typename T>
inline void List<T>::SwapValue(Node<T>* a, Node<T>* b)
{
	T temp = a->data;
	a->data = b->data;
	b->data = temp;
}

template <typename T>
inline Node<T>* List<T>::Partition(Node<T>* start, Node<T>* end)
{
	T pivotValue = start->data;
	Node<T>* p = start;
	Node<T>* q = start->next;
	while (q != end) 
	{
		if (q->data < pivotValue)
		{
			p = p->next;
			SwapValue(p, q);
		}
		q = q->next;
	}
	SwapValue(p, start);
	return p;
}

template <typename T>
inline void List<T>::quickSort(Node<T>* start, Node<T>* end)
{
	if (start != end) 
	{
		Node<T>* mid = Partition(start, end);
		quickSort(start, mid);
		quickSort(mid->next, end);
	}

}


template <typename T>
inline void List<T>::quicksort()
{
	quickSort(Head, nullptr);
}

template <typename T>
inline void List<T>::bublesort()
{
	if (Head)
	{
		Node<T>* tmp = Head;
		bool prapor = false;
		do
		{
			prapor = false;
			for (tmp; !(tmp->next == nullptr); tmp = tmp->next)
			{
				if (tmp->data > tmp->next->data)
				{
					T tmp_el = tmp->data;
					tmp->data = tmp->next->data;
					tmp->next->data = tmp_el;
					prapor = true;
				}
			}
			tmp = Head;
		} while (prapor);
	}
}

template <typename T>
inline void List<T>::insort()
{
	Head = Insort(Head);
}

template <typename T>
inline Node<T>* List<T>::Insort(Node<T>* root)
{
	Node<T>* p, * key;
	Node<T>* result = root;
	root = root->next;
	result->next = nullptr;

	while (root->next != nullptr) 
	{
		key = root;
		root = root->next;
		if (key->data < result->data) 
		{ 
			key->next = result;
			result = key;
		}
		else 
		{
			p = result;
			while (p->next != nullptr) 
			{    
				if (p->next->data > key->data)
					break;
				p = p->next;
			}
			key->next = p->next;
			p->next = key;
		}
	}
	return result;
}

template <typename T>
inline void List<T>::del_f()
{
	if (Head != nullptr)
	{
		if (Head->next == nullptr)
		{
			delete Head;
			Head = tail = nullptr;
		}
		else
		{
			Node<T>* tmp = Head;
			Head = Head->next;
			delete tmp;
		}
	}
}

template <typename T>
inline void List<T>::search(T d)
{
	Node<T>* cur = Head;
	bool touch = 0;
	while (cur->next != nullptr)
	{
		if (cur->data == d)
		{
			std::cout << "This " << d << " element in the list\n";
			touch = true;
			break;
		}
		cur = cur->next;
	}
	if (touch == false)
	{
		if (cur->data == d)
		{
			std::cout << "This " << d << " element in the list\n";
			touch = true;
		}
		if (touch == false)
			std::cout << "NO " << d << " element in the list\n";
	}
}

template <typename T>
inline void List<T>::push(T d)
{
	Node<T>* New = new Node<T>;
	New->data = d;
	if (Head == nullptr)
	{
		Head = New;
		tail = New;
		Head->next = nullptr;
	}
	else
	{
		New->next = Head;
		Head = New;
	}
	lenght++;
}

template<typename T>
inline List<T>::~List()
{
	clear();
}

template <typename T>
inline void List<T>::clear()
{
	if (Head == nullptr)
		return;
	else
	{
		Node<T>* cur = Head;
		Node<T>* cur1 = Head;
		while (cur->next != nullptr)
		{
			cur1 = cur;
			cur = cur->next;
			delete cur1;
		}
		delete cur;
		Head = nullptr;
	}
	lenght = 0;
}

template <typename T>
inline List<T>& List<T>:: operator=(const List <T>& other)
{
	Node <T>* cur = other.Head;
	for (cur; cur != nullptr; cur = cur->next)
		push(cur->data);
	lenght = other.lenght;
	return *this;
}

template<typename T>
inline List<T>::List(const List<T>& other)
{
	*this = other;
}

template<typename T>
inline bool List<T>::empty() const
{
	return lenght == 0;
}

template <typename T>
inline int List<T>::size() const
{
	return lenght;
}
