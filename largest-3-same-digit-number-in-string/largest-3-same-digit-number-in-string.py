class Solution:
    def largestGoodInteger(self, num: str) -> str:
        mxDigit = ' '
        for i in range(len(num)-2):
            if num[i] == num[i+1] == num[i+2]:
                mxDigit = max(mxDigit, num[i])
        return '' if mxDigit==' ' else mxDigit*3