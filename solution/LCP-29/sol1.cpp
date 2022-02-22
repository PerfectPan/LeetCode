class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
      xPos += 1, yPos += 1;
      int a = yPos - 1;
      int b = num - yPos;
      int c = xPos - 1;
      int d = num - xPos;

      int dis = min(min(a, b), min(c, d));

      int outMax = (1LL * num * num % 9 - 1LL * (num - 2 * dis) * (num - 2 * dis) % 9) % 9;
      
      int inIdx = num - 2 * dis; 
      int inX = xPos - dis;
      int inY = yPos - dis;
      int res = 0;
      if (xPos - 1 == dis || num - yPos == dis) {
        res = (outMax + inX + inY - 1) % 9;
      } else {
        res = (outMax + 4LL * inIdx % 9 - inX - inY - 1) % 9;
      }

      if (res < 0) {
        res %= 9;
        res += 9;
        res %= 9;
      }

      return res == 0 ? 9 : res;
    }
};

