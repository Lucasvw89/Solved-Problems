class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        stack: list[int] = []
        for i in tokens:
            if i not in '+-*/':
                stack.append(int(i))
            else:
                b = stack.pop()
                a = stack.pop()
                if i == '+':
                    stack.append(a+b)
                if i == '-':
                    stack.append(a-b)
                if i == '*':
                    stack.append(a*b)
                if i == '/':
                    stack.append(int(a/b))
        return stack[-1]
