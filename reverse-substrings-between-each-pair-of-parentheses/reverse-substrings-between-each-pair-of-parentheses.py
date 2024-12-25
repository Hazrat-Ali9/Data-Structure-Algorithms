class Solution:
    def reverseParentheses(self, s: str) -> str:
        st = deque()
        ans = []
        for c in s:
            if c == '(':
                st.append(len(ans))
            elif c == ')':
                start = st.pop()
                ans[start:] = ans[start:][::-1]
            else: ans.append(c)
        return "".join(ans)