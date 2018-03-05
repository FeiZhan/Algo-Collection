class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """

        self.stack = []
        self.min_stack = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """

        self.stack.append(x)
        if 0 == len(self.min_stack) or self.min_stack[-1] >= x:
            self.min_stack.append(x)

    def pop(self):
        """
        :rtype: nothing
        """

        temp = self.stack.pop()
        if self.min_stack[-1] == temp:
            self.min_stack.pop()

    def top(self):
        """
        :rtype: int
        """

        return self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """

        return self.min_stack[-1]
