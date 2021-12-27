/**
 * @param {string} s
 * @return {string}
 */
var makeFancyString = function(s) {
    let t = "";
    for (let i = 0; i < s.length; ++i) {
        if (t.length + 1<= 2) {
            t += s[i];
        } else {
            const len=t.length;
            if (t[len-1]==t[len-2] && t[len-1]==s[i]) {
                continue;
            }  else{
                t+=s[i];
            }
        }
    }
    return t;
};

