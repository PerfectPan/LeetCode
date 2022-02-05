class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
        int len=(int)cont.size();
        int n=1,m=cont[len-1];
        for (int i=len-2;i>=0;--i){
            int x=cont[i];
            n=x*m+n;
            n/=__gcd(n,m);
            m/=__gcd(n,m);
            swap(n,m);
        }
        vector<int>vec;
        vec.push_back(m);
        vec.push_back(n);
        return vec;
    }
};

