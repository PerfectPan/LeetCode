class Solution {
public:
    int flag[26];
    string decodeMessage(string key, string message) {
      memset(flag, -1, sizeof(flag));
      int cnt = 0;
      for (int i = 0; i < key.length(); ++i) {
        if (isalpha(key[i]) && !(~flag[key[i] - 'a'])) {
          flag[key[i] - 'a'] = cnt++;
        }
      }

      for (int i = 0; i < message.length(); ++i) {
        if (isalpha(message[i])) {
            message[i] = 'a' + flag[message[i] - 'a'];
        }
      }
      return message;        
    }
};

