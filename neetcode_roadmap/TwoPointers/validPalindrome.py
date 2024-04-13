class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower().translate({ord(i): None for i in '!@#$%^&*()_+-={}[]:";\',.<>/?\\|`~ '})

        for i in range(len(s)):
            if s[i] != s[len(s) - 1 - i]:
                return False
        
        return True
