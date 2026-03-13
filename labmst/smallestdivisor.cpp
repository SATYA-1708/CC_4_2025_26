class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int left = 1;
        int right = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] > right){
                right = nums[i];
            }
        }

        while(left<right){

            int mid=(left+right)/2;
            int sum=0;

            for(int i=0;i<n;i++){
                sum+=(nums[i]+mid-1)/mid;
            }
            if(sum<=threshold){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};