class NumArray {
public:
    int n, sum[30010];
    vector<int> a;
    int lowbit(int x) { return x & (-x); }
    void add(int x, int v) {
        for (; x <= n; x += lowbit(x)) {
            sum[x] += v;
        }
    }
    int get(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) {
            ans += sum[x];
        }
        return ans;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        for (int i = 1; i <= n; ++i) {
            sum[i] = 0;
        }
        for (int i = 0; i < nums.size(); ++i) {
            add(i + 1, nums[i]);
        }
        a = move(nums);
    }
    
    void update(int index, int val) {
        add(index + 1, val - a[index]);
        a[index] = val;
    }
    
    int sumRange(int left, int right) {
        return get(right + 1) - get(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
