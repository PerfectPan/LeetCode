// 问题等价于找左边第一个比当前股票价值数大的位置，单调栈即可
class StockSpanner {
public:
    int day = 1;
    stack<pair<int, int>> stk;
    StockSpanner() {
        stk.push({1, 1000000000});
    }
    
    int next(int price) {
        day++;
        while (stk.top().second <= price) {
            stk.pop();
        }
    
        int res = day - stk.top().first;

        stk.push({ day, price });
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
 
