class Solution:
    def checkString(self, s: str) -> bool:
        if s.count('a') == 0 or s.count('b') == 0:
            return True
        return s.find('b') > s.rfind('a')

        