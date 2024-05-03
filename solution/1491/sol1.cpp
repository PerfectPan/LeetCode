class Solution {
public:
    double average(vector<int>& salary) {
        return (1.0 * accumulate(salary.begin(), salary.end(), 0) - *max_element(salary.begin(), salary.end()) - *min_element(salary.begin(), salary.end())) / ((int)salary.size() - 2);
    }
};
