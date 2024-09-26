class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int A = 0, B = 0;
        for (int num: nums) {
            A += num;
        }      
        for (int num: nums) {
            int x = num;
            while (x > 0) {
                B += x % 10;
                x /= 10;
            }
        }    
        return abs(A - B);  
    }
};
