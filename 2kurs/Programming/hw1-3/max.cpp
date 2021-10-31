
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Element
{
private:
	Element* next;
	Element* prev;

	T field;
public:
	virtual Element* getNext() { return next; }
	virtual void setNext(Element* value) { next = value; }

	virtual Element* getPrevious() { return prev; }
	virtual void setPrevious(Element* value) { prev = value; }

	virtual T getValue() { return field; }
	virtual void setValue(T value) { field = value; }

	Element()
	{
		next = prev = NULL;
	}
	Element(T value)
	{
		next = prev = NULL;
		field = value;
	}

	template<class T> friend ostream& operator<< (ostream& ustream, Element<T>& obj);
	template<typename T> friend bool operator< (Element<T> obj1, Element<T> obj2);
	template<typename T> friend bool operator> (Element<T> obj1, Element<T> obj2);
	template<typename T> friend bool operator<= (Element<T> obj1, Element<T> obj2);
	template<typename T> friend bool operator>= (Element<T> obj1, Element<T> obj2);
};

template<typename T>
bool operator<(Element<T> obj1, Element<T> obj2)
{
	return obj1.getValue() < obj2.getValue();
}

template<typename T>
bool operator>(Element<T> obj1, Element<T> obj2)
{
	return obj1.getValue() > obj2.getValue();
}

template<typename T>
bool operator<=(Element<T> obj1, Element<T> obj2)
{
	return obj1.getValue() <= obj2.getValue();
}

template<typename T>
bool operator>=(Element<T> obj1, Element<T> obj2)
{
	return obj1.getValue() >= obj2.getValue();
}

template<class T>
ostream& operator << (ostream& ustream, Element<T>& obj)
{
	ustream << obj.field;
	return ustream;
}

template <class T>
class LinkedListParent
{
protected:
	Element<T>* head;
	Element<T>* tail;
	int num;
public:
	virtual int Number() { return num; }

	virtual Element<T>* getBegin() { return head; }

	virtual Element<T>* getEnd() { return tail; }

	LinkedListParent()
	{
		cout << "\nParent constructor";
		head = NULL;
		tail = NULL;
		num = 0;
	}

	virtual Element<T>* push(T value) = 0;

	virtual Element<T>* pop() = 0;

	virtual ~LinkedListParent()
	{
		cout << "\nParent destructor";
	}

	virtual Element<T>* operator[](int i)
	{
		if (i<0 || i>num) return NULL;
		int k = 0;

		Element<T>* cur = head;
		for (k = 0; k < i; k++)
		{
			cur = cur->getNext();
		}
		return cur;
	}

	template<class T> friend ostream& operator<< (ostream& ustream, LinkedListParent<T>& obj);
	template<class T> friend istream& operator>> (istream& ustream, LinkedListParent<T>& obj);

};

template<class T>
ostream& operator << (ostream& ustream, LinkedListParent<T>& obj)
{
	if (typeid(ustream).name() == typeid(ofstream).name())
	{
		ustream << obj.num << "\n";
		for (Element<T>* current = obj.getBegin(); current != NULL; current = current->getNext())
			ustream << current->getValue() << " ";
		return ustream;
	}

	ustream << "\nLength: " << obj.num << "\n";
	int i = 0;
	for (Element<T>* current = obj.getBegin(); current != NULL; current = current->getNext(), i++)
		ustream << "arr[" << i << "] = " << current->getValue() << "\n";

	return ustream;
}

template<class T>
istream& operator >> (istream& ustream, LinkedListParent<T>& obj)
{
	int len;
	ustream >> len;
	double v = 0;
	for (int i = 0; i < len; i++)
	{
		ustream >> v;
		obj.push(v);
	}
	return ustream;
}

template<typename ValueType>
class ListIterator : public std::iterator<std::input_iterator_tag, ValueType>
{
private:

public:
	ListIterator() { ptr = NULL; }
	ListIterator(Element<ValueType>* p) { ptr = p; }
	ListIterator(const ListIterator& it) { ptr = it.ptr; }

	
	ListIterator& operator=(const ListIterator& it) { ptr = it.ptr; return *this; }
	ListIterator& operator=(Element<ValueType>* p) { ptr = p; return *this; }

	bool operator!=(ListIterator const& other) const { return ptr != other.ptr; }
	bool operator==(ListIterator const& other) const { return ptr == other.ptr; }
	Element<ValueType>& operator*()
	{
		return *ptr;
	}
	ListIterator& operator++() {
		if (ptr != NULL && ptr->getNext() != NULL)
			ptr = ptr->getNext();
		return *this;
	}
	ListIterator& operator++(int v) {
		if (ptr != NULL && ptr->getNext() != NULL)
			ptr = ptr->getNext();
		return *this;
	}
private:
	Element<ValueType>* ptr;
};

template <class T>
class IteratedLinkedList : public LinkedListParent<T>
{
public:
	IteratedLinkedList() : LinkedListParent<T>() { cout << "\nIteratedLinkedList constructor"; }
	virtual ~IteratedLinkedList() { cout << "\nIteratedLinkedList destructor"; }

	ListIterator<T> iterator;

	ListIterator<T> begin() { ListIterator<T> it = LinkedListParent<T>::head; return it; }
	ListIterator<T> end() { ListIterator<T> it = LinkedListParent<T>::tail; return it; }
};


template <class T>
class Stack : public IteratedLinkedList<T>
{
public:
	Stack() : IteratedLinkedList<T>() { cout << "\nStack constructor"; }
	virtual ~Stack() { cout << "\nStack destructor"; }

	virtual Element<T>* push(T value)
	{
		if (LinkedListParent<T>::head != NULL)
		{
			Element<T>* newElem = new Element<T>(value);
			LinkedListParent<T>::tail->setNext(newElem);
			newElem->setPrevious(LinkedListParent<T>::tail);
			LinkedListParent<T>::tail = newElem;
		}
		else
		{
			LinkedListParent<T>::tail = new Element<T>(value);
			LinkedListParent<T>::head = LinkedListParent<T>::tail;
		}
		LinkedListParent<T>::num++;
		return LinkedListParent<T>::tail;
	}
	virtual Element<T>* pop()
	{
		Element<T>* delElem = LinkedListParent<T>::tail;
		if (LinkedListParent<T>::num >= 2)
		{
			Element<T>* newTail = LinkedListParent<T>::tail->getPrevious();
			newTail->setNext(NULL);
			LinkedListParent<T>::tail = newTail;
			LinkedListParent<T>::num--;
		}
		else if (LinkedListParent<T>::num == 1)
		{
			LinkedListParent<T>::tail = NULL;
			LinkedListParent<T>::head = NULL;
			LinkedListParent<T>::num--;
		}
		else 
		{
			cout << "List is empty" << endl;
			return NULL;
		}
		return delElem;
	}

	Stack<T> filter(bool (*func_ptr)(T))
	{
		Stack<T> res;
		ListIterator<T> it = IteratedLinkedList<T>::begin();
		while (it != IteratedLinkedList<T>::end())
		{
			if (func_ptr((*it).getValue()))
				res.push((*it).getValue());
			it++;
		}
		if (IteratedLinkedList<T>::num != 0 && func_ptr((*it).getValue()))
			res.push((*it).getValue());
		return res;
	}
};


template<class T>
class StackHeir : public Stack<T>
{
public:
	StackHeir() : Stack<T>() { cout << "\nStackHeir constructor"; }
	virtual	~StackHeir() { cout << "\nStackHeir destructor"; }

	virtual Element<T>* push(T value) 
	{

		if (LinkedListParent<T>::head != NULL) 
		{
			Element<T>* newElem = new Element<T>(value);
			Element<T>* curr = LinkedListParent<T>::head;
			if (*newElem >= *curr)                
			{
				LinkedListParent<T>::head->setPrevious(newElem);
				newElem->setNext(LinkedListParent<T>::head);        
				LinkedListParent<T>::head = newElem;
				LinkedListParent<T>::num++;
				return LinkedListParent<T>::tail;
				
			}
			curr = curr->getNext();                
			while (curr != LinkedListParent<T>::tail)
			{
				if (*newElem >= *curr)
				{
					(curr->getPrevious())->setNext(newElem);
					newElem->setPrevious(curr->getPrevious());
					newElem->setNext(curr);
					curr->setPrevious(newElem);
					LinkedListParent<T>::num++;
					return LinkedListParent<T>::tail;
				}
				curr = curr->getNext();
			}
			if (*newElem >= *curr)                   
			{
				(curr->getPrevious())->setNext(newElem);
				newElem->setPrevious(curr->getPrevious());
				curr->setPrevious(newElem);
				newElem->setNext(curr);			
			}
			else
			{
				newElem->setPrevious(LinkedListParent<T>::tail);
				LinkedListParent<T>::tail->setNext(newElem);
				LinkedListParent<T>::tail = newElem;
			}
				
		}
		else 
		{
			LinkedListParent<T>::tail = new Element<T>(value);
			LinkedListParent<T>::head = LinkedListParent<T>::tail;
		}
		LinkedListParent<T>::num++;
		return LinkedListParent<T>::tail;
	}
};

bool condition(int value)
{
	return (value % 2 == 0);
}

int main()
{

	/*Stack<int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	cout << S;*/
	/*
	cout << "\n";
	Element<int>* e1 = S.pop();
	cout << "\nElement = " << e1->getValue();
	cout << S;

	cout << "\nIndex in the Stack class: " << S[1]->getValue();

	cout << S;
	cout << "\nIterators:\n";
	S.iterator = S.begin();
	while (S.iterator != S.end())
	{
		cout << *S.iterator << " ";
		S.iterator++;
	}
	cout << *S.iterator << " ";
	S.filter(*condition);*/
	StackHeir<int> S;
	/*S.push(3);
	S.push(5);
	S.push(4);
	S.push(10);
	S.push(1);
	S.push(9);
	cout << S;*/
	cout << '\n' << S.pop();

	char c; cin >> c;
	return 0;
}