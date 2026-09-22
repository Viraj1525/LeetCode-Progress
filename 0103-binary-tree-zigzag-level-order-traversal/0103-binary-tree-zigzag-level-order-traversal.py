# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode | None) -> list[list[int]]:
        if not root: return []
        q = deque()
        q.append(root)
        ans = []
        level = [root.val]
        ans.append(level)

        while q:
            l = len(q)
            level = []

            for i in range(l):
                front = q.popleft()
                if front.left : 
                    q.append(front.left)
                    level.append(front.left.val)

                if front.right : 
                    q.append(front.right)
                    level.append(front.right.val)

            if len(level) > 0:
                ans.append(level)

        if len(ans) == 1 : return ans

        for i in range(1,len(ans),2):
            ans[i] = list(reversed(ans[i]))

        return ans







            


        