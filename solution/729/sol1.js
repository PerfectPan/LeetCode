var MyCalendar = function() {
    this.schedule = new Set();
};

/** 
 * @param {number} startTime 
 * @param {number} endTime
 * @return {boolean}
 */
MyCalendar.prototype.book = function(startTime, endTime) {
    for (const [s, e] of this.schedule) {
        if ((startTime >= s && startTime < e) || (endTime - 1 >= s && endTime - 1 < e) || (startTime <= s && e < endTime)) {
            return false;
        }
    }
    this.schedule.add([startTime, endTime]);
    return true;
};

/** 
 * Your MyCalendar object will be instantiated and called as such:
 * var obj = new MyCalendar()
 * var param_1 = obj.book(startTime,endTime)
 */
