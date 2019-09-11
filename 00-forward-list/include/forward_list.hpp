#include <iostream>
#include <unordered_set>

namespace lib
{
template <typename T>
class node
{
public:
	T element;
	node *next;
	node(T elemval, node *nextval = nullptr) : element(elemval), next(nextval) {}
	node(node *nextval = nullptr) : next(nextval) {}

	T &operator()()
	{
		return element;
	}
};

template <typename T>
class forward_list
{
private:
	node<T> *head;
	node<T> *tail;

	void init()
	{
		head = fence = tail = new node<T>(nullptr);
	}

public:
	node<T> *getHead() { return head; }
	node<T> *getTail() { return tail; }
	void setHead(node<T> *h) { head = h; }
	void setTail(node<T> *t) { tail = t; }
	node<T> *fence;
	int flag = 1;
	forward_list() { init(); }
	bool append(T it)
	{
		tail->next = new node<T>(it, nullptr);
		if (flag == 1)
		{
			head = tail->next;
			flag++;
			fence = head;
		}
		tail = tail->next;
		return true;
	}

	bool print()
	{
		if (head == nullptr)
			return 0;
		fence = head;
		while (fence != nullptr)
		{
			std::cout << fence->element << " ";
			fence = fence->next;
		}
		fence = head;
		// std::cout << std::endl;
		return true;
	}

	

	forward_list(const std::initializer_list<T> arr)
	{
		for (auto it = arr.begin(); it < arr.end(); it++)
		{
			if (flag == 1)
			{
				head = new node<T>(*it, nullptr);
				tail = head;
				fence = head;
				flag++;
			}
			else
			{
				append(*it);
			}
		}
	}

	node<T> *begin()
	{
		fence = head;
		return fence;
	}

	bool alternate()
	{
		if (head == nullptr)
			return false;
		node<T> *fence = head;
		node<T> *n = head->next;

		while (fence != nullptr && n != nullptr)
		{
			fence->next = n->next;

			free(n);

			fence = fence->next;
			if (fence != NULL)
				n = fence->next;
		}
	}

	bool nthNode(int n)
	{
		if (head == nullptr)
			return false;

		int i = 0;
		fence = head;

		while (fence->next != nullptr)
		{
			i += 1;
			if (i == n)
			{
				std::cout << fence->element;
				return true;
			}
			fence = fence->next;
		}
		return false;
	}

	bool removeDuplicates()
	{
		if (head == nullptr)
			return false;
		std::unordered_set<int> seen;
		fence = head;
		node<T> *prev = nullptr;
		while (fence != nullptr)
		{
			if (seen.find(fence->element) != seen.end())
			{
				prev->next = fence->next;
				delete (fence);
			}
			else
			{
				seen.insert(fence->element);
				prev = fence;
			}
			fence = fence->next;
		}
	}

	bool reverse()
	{

		node<T> *fence = head;
		node<T> *prev = nullptr, *n = nullptr;

		while (fence != nullptr)
		{
			n = fence->next;

			fence->next = prev;

			prev = fence;
			fence = n;
		}
		head = prev;
	}

	void swapnode(int x, int y)
	{
		node<T> **head_ref = &head;
		if (x == y)
			return;

		node<T> *prevX = nullptr, *currX = *head_ref;
		while (currX && currX->element != x)
		{
			prevX = currX;
			currX = currX->next;
		}

		node<T> *prevY = nullptr, *currY = *head_ref;
		while (currY && currY->element != y)
		{
			prevY = currY;
			currY = currY->next;
		}

		if (currX == nullptr || currY == nullptr)
			return;

		if (prevX != nullptr)
			prevX->next = currY;
		else
			*head_ref = currY;

		if (prevY != nullptr)
			prevY->next = currX;
		else
			*head_ref = currX;

		node<T> *temp = currY->next;
		currY->next = currX->next;
		currX->next = temp;
	}

	bool operator==(const forward_list<T> &l1);


};
template <typename T>
inline bool forward_list<T>::operator==(const forward_list<T> &l1)
{
	node<T> *f1 = l1.head;
	node<T> *f2 = this->head;

	while (f1 != nullptr && f2 != nullptr)
	{
		if (f1->element != f2->element)
			break;

		f1 = f1->next;
		f2 = f2->next;

	}

	return (f1 == nullptr && f2 == nullptr);
}
} // namespace lib
