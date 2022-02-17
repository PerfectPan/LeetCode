class Solution {
public:
    int calculate(string s) {
      int A=1,B=0;
      for (int i=0;i<s.size();++i){
        if (s[i]=='A'){
          A=A*2+B;
        } else {
          B=B*2+A;
        }
      }
      return A+B;
    }
};

