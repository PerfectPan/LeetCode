int primes[100005], f[100005];

auto init = [] {
    for (int i = 2; i <= 100000; i += 1) {
		if (!f[i]) {
			primes[++primes[0]] = i;
            f[i] = f[i - 1] + 1;
		} else {
            f[i] = f[i - 1];
        }
        
		for (int j = 1; 1LL * i * primes[j] <= 100000 && j <= primes[0]; j += 1) {
            f[i * primes[j]] = 1;
            if (i % primes[j] == 0) {
                break;
            }
        }
	}
    return 0;
}();

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        return r - l + 1 - f[(int)sqrt(r + 0.5)] + f[(int)sqrt(l - 1 + 0.5)];
    }
};
