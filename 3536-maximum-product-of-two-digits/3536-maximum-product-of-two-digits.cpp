class Solution {
public:
    int maxProduct(int n) {
        int firstmax=n%10;
        n=n/10;
        int secondmax=n%10;
        n=n/10;
        if(secondmax>firstmax){
            swap(firstmax,secondmax);
        }
        while(n>0){
            if(n%10>secondmax){
                secondmax=n%10;
                if(secondmax>firstmax){
                    swap(firstmax,secondmax);
                }
            }
            n=n/10;
        }
        return firstmax*secondmax;

    }
};