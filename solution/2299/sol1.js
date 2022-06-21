var strongPasswordCheckerII = function(password) {
    if (password.length < 8) {
        return false;
    }
    if (password.split('').filter(res => res >= 'a' && res <= 'z').length === 0) {
        return false;
    }
    if (password.split('').filter(res => res >= 'A' && res <= 'Z').length === 0) {
        return false;
    }
    if (password.split('').filter(res => res >= '0' && res <= '9').length === 0) {
        return false;
    }
    if (password.split('').filter(res => "!@#$%^&*()-+".includes(res)).length === 0) {
        return false;
    }
    const arr = password.split('');
    for (let i = 1; i < arr.length; ++i) {
        if (arr[i] === arr[i - 1]) {
            return false;
        }
    }
    return true;    
};

