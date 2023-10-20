class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = length >= 1e4 || width >= 1e4 || height >= 1e4 || 1LL * width * height * length >= 1e9;
        bool isHeavy = mass >= 100;

        if (isBulky and isHeavy) {
            return "Both";
        }
        if (!isBulky and !isHeavy) {
            return "Neither";
        }
        if (isBulky) {
            return "Bulky";
        }
        return "Heavy";
    }
};
