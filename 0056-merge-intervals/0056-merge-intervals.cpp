class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){ 
            //Only new values will be inserted or the values which are not in range
            if(ans.empty() || ans.back()[1]<nums[i][0]){
                ans.push_back(nums[i]);
            }
            else{
                ans.back()[1]=max(ans.back().back(),nums[i][1]);
            }
        }
        return ans;
    }
};