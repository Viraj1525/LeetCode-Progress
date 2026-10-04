class Solution:
    def helper(self, s:str, factor: int, idx : int, dp):
        if factor<0 : 
            return False

        if idx == len(s): 
            return factor == 0

        if (idx, factor) in dp:
            return dp[(idx, factor)]

        if s[idx] == "(":
            ans =  self.helper(s, factor+1, idx + 1, dp)

        elif s[idx] == ")":
            ans =  self.helper(s, factor-1, idx + 1, dp)

        else:
            ans =  (
                self.helper(s, factor+1, idx + 1, dp) or 
                self.helper(s, factor-1, idx + 1, dp) or 
                self.helper(s, factor, idx + 1, dp)
            )

        dp[(idx, factor)] = ans
        return ans
 

    def checkValidString(self, s: str) -> bool:
        return self.helper(s, 0, 0, {})
