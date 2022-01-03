/**
 * @param {string} s
 * @param {string} part
 * @return {string}
 */
var removeOccurrences = function(s, part){
  let len=part.length;  
  while (true) {
    let f=false;
    let t=s;
    for (let i=0;i+len-1<s.length;++i){
      if (s.substr(i,len)===part){
        f=true;
        t=s.substr(0,i)+s.substr(i+len);
        break;
      }
    }
    s=t;
             
    if (!f){
      break;
    }
  }
  return s;
};

