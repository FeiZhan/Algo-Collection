template <typename T>
class MyQueue
{
public:
	MyQueue(void)
	{}
	int size(void)
	{
		return s1.size() + s2.size();
	}
	void enqueue(T value)
	{
		s1.push(value);
	}
	T peek(void)
	{
		if (! s2.empty())
		{
			return s2.top();
		}
		while (! s1.empty())
		{
			s2.push(s1.pop());
		}
		return s2.top();
	}
	T dequeue()
	{
		if (! s2.empty())
		{
			return s2.pop();
		}
		while (! s1.empty())
		{
			s2.push(s1.pop());
		}
		return s2.pop();
	}
private:
	std::stack<T> s1, s2;
};
