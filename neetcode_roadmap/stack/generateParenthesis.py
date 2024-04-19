# recursion
res=[]
def gen(n: int, i='(', j=1):

    if len(i) == 2*n:
        if j == 0: res.append(i)
        return

    gen(n, i+'(', j+1)
    if j > 0:
        gen(n, i+')', j-1)



# iteration
def genParenthesis(n: int) -> list[str]:
    stack: list[str] = list()
    i: int = 0
    j: int = 0

    while True:
        stack.append('(')
        if j > 0: stack.append(')')



gen(3)
print(res)
