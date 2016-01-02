class SetOfStacks
{
public:
	SetOfStacks() : capacity(0)
	{}
	void push(int v)
	{
		if (0 == stacks.size() || MAX_CAPACITY <= stacks[stacks.size() - 1].size())
		{
			stacks.push_back(std::stack<int>());
		}
		stacks[stacks.size() - 1].push(v);
	}
	int pop()
	{
		if (stacks.size() == 0)
		{
			// throw exception
			return 0;
		}
		int v = stacks[stacks.size() - 1].top();
		stacks[stacks.size() - 1].pop();
		if (stacks[stacks.size() - 1].empty())
		{
			stacks.pop_back();
		}
		return v;
	}
	int popAt(size_t index)
	{
		return leftShift(index, true);
	}
	int capacity;
private:
	int leftShift(size_t index, bool remove_top)
	{
		if (index >= stacks.size())
		{
			// throw exception
			return 0;
		}
		std::stack<int> &stack = stacks[index];
		int item = remove_top ? stack.pop() : stack.removeBottom();
		if (stack.empty())
		{
			stacks.erase(index, 1);
		} else if (stacks.size() > index + 1)
		{
			stack.push(leftShift(index + 1, false));
		}
		return item;
	}
	static const MAX_CAPACITY;
	std::vector<std::stack<int> > stacks;
};
SetOfStacks::MAX_CAPACITY = 10;
