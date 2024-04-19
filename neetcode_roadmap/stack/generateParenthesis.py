class Solution:
    def generateParenthesis(self, n: int) -> list[str]:
        res=[]
        def gen(n: int, i='(', j=1):

            if len(i) == 2*n:
                if j == 0: res.append(i)
                return

            gen(n, i+'(', j+1)
            if j > 0:
                gen(n, i+')', j-1)

        gen(n)
        return res
