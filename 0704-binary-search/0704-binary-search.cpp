class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n=nums.size();
        int st=0;
        int end=n-1;

        while(st<=end){
            int mid=st+(end-st)/2;

            if(tar==nums[mid]){
                return mid;
            }
            else if(tar>nums[mid]){
                st=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        return -1;
    }
};