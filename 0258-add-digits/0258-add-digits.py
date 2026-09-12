class Solution:
    def addDigits(self, num: int) -> int:
        while num>=10:
            num_as_arr=list(str(num))
            add=0
            for i in range(len(num_as_arr)):
                num_as_arr[i]=int(num_as_arr[i])
                add+=num_as_arr[i]
            num=add
        return num
        