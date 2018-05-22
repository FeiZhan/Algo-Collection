class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """

        num_stack = []
        for i in range(len(tokens)):
            if '+' == tokens[i] or '-' == tokens[i] or '*' == tokens[i] or '/' == tokens[i]:
                num0 = num_stack.pop()
                num1 = num_stack.pop()
                num_stack.append(self.calculate(num1, num0, tokens[i]))
            else:
                num_stack.append(int(tokens[i]))
        return num_stack[-1]

    def calculate(self, num0, num1, op):
        answer = 0
        if '+' == op:
            answer = num0 + num1
        elif '-' == op:
            answer = num0 - num1
        elif '*' == op:
            answer = num0 * num1
        elif '/' == op:
            answer = abs(num0) / abs(num1)
            if num0 * num1 < 0:
                answer *= -1
        return answer
