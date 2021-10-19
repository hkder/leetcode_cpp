class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size();
        int k = -1;
        int flag = 1;
        for(k = s-1; k >= 1; --k){
            if(nums[k] > nums[k-1]){
                flag = 0;
                break;
            }
        }
        
        if(flag){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        k = k-1;
        // find number that is just larger than nums[k];
        for(int m = s-1; m > k; --m){
            if(nums[m] > nums[k]){
                swap(nums[m], nums[k]);
                break;
            }
        }
        
        reverse(nums.begin()+k+1, nums.end());
    }
};
