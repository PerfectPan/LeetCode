class FrontMiddleBackQueue {
private:
    deque<int> left;
    deque<int> right;

    // 调整长度，保证 0 <= right.size() - left.size() <= 1
    // 从而保证可以在正中间插入删除元素
    void balance() {
        if (left.size() > right.size()) {
            right.push_front(left.back());
            left.pop_back();
        } else if (right.size() > left.size() + 1) {
            left.push_back(right.front());
            right.pop_front();
        }
    }

public:
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        if (left.size() < right.size()) {
            left.push_back(val);
        } else {
            right.push_front(val);
        }
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        if (right.empty()) { // 整个队列为空
            return -1;
        }
        int val;
        if (left.empty()) {
            val = right.front();
            right.pop_front();
        } else {
            val = left.front();
            left.pop_front();
        }
        balance();
        return val;
    }

    int popMiddle() {
        if (right.empty()) { // 整个队列为空
            return -1;
        }
        int val;
        if (left.size() == right.size()) {
            val = left.back();
            left.pop_back();
        } else {
            val = right.front();
            right.pop_front();
        }
        return val;
    }

    int popBack() {
        if (right.empty()) { // 整个队列为空
            return -1;
        }
        int val = right.back();
        right.pop_back();
        balance();
        return val;
    }
};
