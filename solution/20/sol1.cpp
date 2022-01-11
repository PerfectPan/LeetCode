class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (int i=0;i<s.length();++i){
            if (s[i]=='(' || s[i]=='{' || s[i]=='[') S.push(s[i]);
            else{
                if (S.empty()) return false;
                char c = S.top();S.pop();
                if ((s[i]==')' && c=='(')||(s[i]=='}'&&c=='{')||(s[i]==']'&&c=='['));
                else return false;
            }
        }
        return S.empty();
    }
};

