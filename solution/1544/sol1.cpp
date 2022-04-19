class Solution {
public:
    string makeGood(string s) {
        for (;;){
            string t="";
            int cnt=0;
            for (int i=0;i<s.length();++i){
                if (i+1<s.length() && ((s[i]>='a' && s[i]<='z' && s[i+1]>='A' && s[i+1]<='Z' && s[i]-'a'==s[i+1]-'A')
                   || (s[i]>='A' && s[i]<='Z' && s[i+1]>='a' && s[i+1]<='z' && s[i]-'A'==s[i+1]-'a'))) i++,cnt++;
                else t=t+s[i];
            }
            s=t;
            if (!cnt) break;
        }
        return s;
    }
};

