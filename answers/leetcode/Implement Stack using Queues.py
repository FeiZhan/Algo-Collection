class Stack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """

        self.queue0 = []
        self.queue1 = []

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """

        self.queue0.append(x)

    def pop(self):
        """
        :rtype: nothing
        """

        self.top()
        self.queue0.pop(0)

    def top(self):
        """
        :rtype: int
        """

        if 0 == len(self.queue0):
            while len(self.queue1):
                self.queue0.append(self.queue1.pop(0))
        while len(self.queue0) > 1:
            self.queue1.append(self.queue0.pop(0))
        return self.queue0[0]

    def empty(self):
        """
        :rtype: bool
        """

        return 0 == len(self.queue0) + len(self.queue1)
