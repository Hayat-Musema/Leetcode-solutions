class Solution:
    def numberGame(self, nums: List[int]) -> List[int]:
        arr=[]
        nums.sort()
        for i in range (0,len(nums),2):
            nums[i],nums[i+1]=nums[i+1],nums[i]
            arr.append(nums[i])
            arr.append(nums[i+1])

        return arr
