class Solution {
public:
    void sortColors(vector<int>& nums) {
      for(int i=0;i<nums.size()-1;i++){
        int temp;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                temp=nums[i];
              
            }
            else if(nums[i]>nums[j]){
                temp=nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
            else{
                nums[i]=nums[j];
            }
        }
      }  
    }
};