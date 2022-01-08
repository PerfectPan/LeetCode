class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long long ans=0,t=x;
        while (x){
            ans=ans*10+x%10;
            x/=10;
        }
        return ans==t;
    }
};

