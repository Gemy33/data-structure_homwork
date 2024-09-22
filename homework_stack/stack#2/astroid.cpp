#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
	int size{};
	int top{};
	int *array{};

public:
	Stack(int size) : size(size), top(-1)
	{
		array = new int[size];
	}

	~Stack()
	{
		delete[] array;
	}

	void push(int x)
	{
		assert(!isFull());
		array[++top] = x;
	}
	void insert_at_bottom(int x)
	{
		// assert(!isFull());
		if (isEmpty())
		{
			push(x);
		}
		else
		{
			int cur = pop();
			insert_at_bottom(x);
			push(cur);
		}

		// for (int i = top; i >=0; --i)
		// {
		// 	array[i+1]=array[i];
		// }
		// top++;
		// array[0]=x;

		// need to arrive the end of the stack
		// add the value at the end
	}
	void reverse()
	{
		if (isEmpty())
		{
			return;
		}
		else
		{
			int cur = pop();
			reverse();
			insert_at_bottom(cur);
		}
	}

	int pop()
	{
		assert(!isEmpty());
		return array[top--];
	}

	int peek()
	{
		assert(!isEmpty());
		return array[top];
	}

	int isFull()
	{
		return top == size - 1;
	}

	int isEmpty()
	{
		return top == -1;
	}
void display_reversed() {
		for (int i = 0; i <= top; i++)
			cout << array[i] << " ";
		cout << "\n";
	}
	
	void display()
	{
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};
void asteroidCollision(int arr[], int len)
{
	Stack s(len);
	for (int i = 0; i < len; i++)
	{
		bool explode = false;
		while (!s.isEmpty() && arr[i] < 0 && s.peek() >= 0)
		{
			if (s.peek() < -arr[i])
			{
				s.pop();
				continue;
			}
			else if (s.peek() == -arr[i])
			{
				s.pop();
			}
			explode = true;
			break;
		}

		if (!explode)
		{
			s.push(arr[i]);
		}
	}
	s.display_reversed();
}
int main()
{
int arr[] ={1, 0, -1,1};
	asteroidCollision(arr, 4);
	


	return 0;
}
