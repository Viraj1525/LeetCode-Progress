class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        n = len(s)
        stack = []
        ans = 0

        for ch in s:
            if ch == "(":
                stack.append(ch)
            else:
                if stack and stack[-1] == "(":
                    stack.pop()
                else:
                    ans += 1

        return len(stack) + ans

        