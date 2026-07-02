class Solution {
public:
    int arrangeCoins(int n) {
        if(n==0 || n==1){
            return 1;
        }
        int ans=0;
        long long low=1;
        long long high=n;

        while(low<=high){
            long long mid=low+(high-low)/2;
            long long coins=mid*(mid+1)/2;

            if(coins<=n){
                ans = mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};