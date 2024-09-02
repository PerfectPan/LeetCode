class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0, l = 0, cnt[2]{};
        for (int r = 0; r < answerKey.length(); ++r) {
            cnt[answerKey[r] >> 1 & 1]++;
            while (cnt[0] > k and cnt[1] > k) {
                cnt[answerKey[l++] >> 1 & 1]--;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
