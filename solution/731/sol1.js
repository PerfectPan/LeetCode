var MyCalendarTwo = function() {
    this.booked = [];
    this.overlaps = [];
};

MyCalendarTwo.prototype.book = function(start, end) {
    for (const arr of this.overlaps) {
        const l = arr[0], r = arr[1];
        if (l < end && start < r) {
            return false;
        }
    }
    for (const arr of this.booked) {
        const l = arr[0], r = arr[1];
        if (l < end && start < r) {
            this.overlaps.push([Math.max(l, start), Math.min(r, end)]);
        }
    }
    this.booked.push([start, end]);
    return true;
};

/** 
 * Your MyCalendarTwo object will be instantiated and called as such:
 * var obj = new MyCalendarTwo()
 * var param_1 = obj.book(startTime,endTime)
 */
