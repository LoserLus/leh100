/*
 * @lc app=leetcode.cn id=155 lang=cpp
 * @lcpr version=30202
 *
 * [155] 最小栈
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"
#include "../common/utils.cpp"

using namespace std;

// @lc code=start
class MinStack {
    stack<int> s;
    stack<int> min_s;
public:
   
    MinStack() {
    
    }
    
    void push(int val) {
        
        if(s.empty())
        {
            min_s.push(val);
        }
        else{
            int min_val = min(val,min_s.top());
            min_s.push(min_val);
        }
        s.push(val);
    }
    
    void pop() {
        s.pop();
        min_s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

// int main() {
//     Solution solution;
//     // your test code here
// }



/*
// @lcpr case=start
// ["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]\n
// @lcpr case=end

 */

