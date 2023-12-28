#ifndef _PRIORNODE
#define _PRIORNODE

//First let's declare a single node in the list
template<typename T>
class PriorNode
{
private:
	T item;	// A data item (can be any complex sturcture)
	PriorNode<T>* next;	// Pointer to next node
	float priority; 

public:

	PriorNode() //default constructor
	{
		next = nullptr;
		priority = 0;
	}

	PriorNode(T newItem, float p = 0) //non-default constructor
	{
		item = newItem;
		next = nullptr;
		priority = p;
	}

	void setPriority(float p) {
		priority = p;
	}

	float getpriority() const {
		return priority;
	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(PriorNode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	PriorNode<T>* getNext() const
	{
		return next;
	}
}; // end Node

#endif	