
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""

        ans = []

        while num > 0:
            digit = min(9, sum)
            ans.append(str(digit))
            sum -= digit
            num -= 1

        return "".join(ans)
