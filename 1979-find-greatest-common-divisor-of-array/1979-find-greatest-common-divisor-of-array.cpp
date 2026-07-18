class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min=INT_MAX;
        int max=INT_MIN;

        for(int num:nums){
            if(num<=min){
                min=num;
            }
            if(num>=max){
                max=num;
            }
        }
         //gcd from 1 to min
        int ans = 1;
        for (int i = 1; i <= min; i++) {
            if(min % i==0 && max % i==0){
                ans=i;
            }
        }

        return ans;
    }
};