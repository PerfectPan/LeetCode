#include <bits/stdc++.h>
using namespace std;
int pos[1000000];
class Solution {
public:
    int firstMissingPositive(vector<int>& num) {
        int len=num.size();
        for (int i=0;i<len;){
            if (num[i]==i+1) i+=1;
            else{
                if (num[i]>=1 && num[i]<=len && num[i]!=num[num[i]-1]) swap(num[i],num[num[i]-1]);
                else i+=1;
            }
        }
        for (int i=0;i<len;++i)if(num[i]!=i+1) return i+1;
        return len+1;
    }
};
