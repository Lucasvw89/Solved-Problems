class Solution:

    def encode(self, strs: list[str]) -> str:
        s = ""
        for i in strs:
            s += f"{len(i)}-{i}"
        return s

    def decode(self, s: str) -> list[str]:
        strs = []
        curr = 0
        i = 0
        while i < len(s):
            if s[i] == '-':
                size = int(s[curr:i])
                i += 1
                strs.append(s[i: i + size])
                curr = i + size
                i = i + size
            else:
                i += 1
        return strs
