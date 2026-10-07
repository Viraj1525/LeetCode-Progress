class Solution:
    def removeInvalidParentheses(self, s: str):
        left_rem = right_rem = 0

        for ch in s:
            if ch == '(':
                left_rem += 1

            elif ch == ')':
                if left_rem > 0:
                    left_rem -= 1
                else:
                    right_rem += 1

        ans = set()

        def dfs(i, left, right, balance, path):

            if balance < 0:
                return

            if i == len(s):
                if left == 0 and right == 0 and balance == 0:
                    ans.add("".join(path))
                return

            ch = s[i]

            if ch == '(':

                if left > 0:
                    dfs(i + 1, left - 1, right,
                        balance, path)

                path.append(ch)
                dfs(i + 1, left, right,
                    balance + 1, path)
                path.pop()

            elif ch == ')':

                if right > 0:
                    dfs(i + 1, left, right - 1,
                        balance, path)

                path.append(ch)
                dfs(i + 1, left, right,
                    balance - 1, path)
                path.pop()

            else:
                path.append(ch)
                dfs(i + 1, left, right,
                    balance, path)
                path.pop()

        dfs(0, left_rem, right_rem, 0, [])

        return list(ans)
        