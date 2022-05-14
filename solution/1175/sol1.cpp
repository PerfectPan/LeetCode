class Solution {
public:
    const int P=1e9+7;
    bool isPrime(int x){
        for (int i=2;i*i<=x;++i)if(x%i==0) return 0;
        return 1;
    }
    int numPrimeArrangements(int n) {
        int cnt=0;
        for (int i=2;i<=n;++i){
            if (isPrime(i)) cnt++;
        }
        int ans=1;
        for (int i=1;i<=cnt;++i) ans=1LL*ans*i%P;
        for (int i=1;i<=n-cnt;++i) ans=1LL*ans*i%P;
        return ans;
    }
};

