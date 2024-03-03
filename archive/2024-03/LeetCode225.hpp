#pragma once
#include <deque>
using namespace std;
class MyStack {
private:
    deque<int> m_data;
public:
    MyStack() {

    }
    
    void push(int x) {
        m_data.push_back(x);
    }
    
    int pop() {
        int temp = top();
        m_data.pop_back();
        return temp;
    }
    
    int top() {
        return m_data.back();
    }
    
    bool empty() {
        return m_data.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//绪论
//这道题目是为初级读者准备的，题目涉及到栈和队列两种数据结构。
//栈是一种后进先出的数据结构，元素从顶端入栈，然后从顶端出栈。
//队列是一种先进先出的数据结构，元素从后端入队，然后从前端出队。
//
//方法一：两个队列
//为了满足栈的特性，即最后入栈的元素最先出栈，在使用队列实现栈时，应满足队列前端的元素是最后入栈的元素。可以使用两个队列实现栈的操作，其中 queue1 用于存储栈内的元素，queue2 作为入栈操作的辅助队列。
//入栈操作时，首先将元素入队到 queue2 ，然后将 queue1 的全部元素依次出队并入队到 queue2 ，此时 queue2 的前端的元素即为新入栈的元素，再将 queue1 和 queue2 互换，则 queue1 的元素即为栈内的元素，queue1 的前端和后端分别对应栈顶和栈底。
//由于每次入栈操作都确保 queue1 的前端元素为栈顶元素，因此出栈操作和获得栈顶元素操作都可以简单实现。出栈操作只需要移除 queue1 的前端元素并返回即可，获得栈顶元素操作只需要获得 queue1 的前端元素并返回即可（不移除元素）。
//由于 queue1 用于存储栈内的元素，判断栈是否为空时，只需要判断 queue1 是否为空即可。
//class MyStack {
//public:
//    queue<int> queue1;
//    queue<int> queue2;
//
//    /** Initialize your data structure here. */
//    MyStack() {
//
//    }
//
//    /** Push element x onto stack. */
//    void push(int x) {
//        queue2.push(x);
//        while (!queue1.empty()) {
//            queue2.push(queue1.front());
//            queue1.pop();
//        }
//        swap(queue1, queue2);
//    }
//    
//    /** Removes the element on top of the stack and returns that element. */
//    int pop() {
//        int r = queue1.front();
//        queue1.pop();
//        return r;
//    }
//    
//    /** Get the top element. */
//    int top() {
//        int r = queue1.front();
//        return r;
//    }
//    
//    /** Returns whether the stack is empty. */
//    bool empty() {
//        return queue1.empty();
//    }
//};
//复杂度分析
//时间复杂度：入栈操作 O(n)，其余操作都是 O(1)，其中 n 是栈内的元素个数。
//入栈操作需要将 queue1 中的 n 个元素出队，并入队 n+1 个元素到 queue2 ，共有 2n+1 次操作，每次出队和入队操作的时间复杂度都是 O(1)，因此入栈操作的时间复杂度是 O(n)。
//出栈操作对应将 queue1 的前端元素出队，时间复杂度是 O(1)。
//获得栈顶元素操作对应获得 queue1 的前端元素，时间复杂度是 O(1)。
//判断栈是否为空操作只需要判断 queue1 是否为空，时间复杂度是 O(1)。
//空间复杂度：O(n)，其中 n 是栈内的元素个数。需要使用两个队列存储栈内的元素。
//
//方法二：一个队列
//方法一使用了两个队列实现栈的操作，也可以使用一个队列实现栈的操作。
//使用一个队列时，为了满足栈的特性，即最后入栈的元素最先出栈，同样需要满足队列前端的元素是最后入栈的元素。
//入栈操作时，首先获得入栈前的元素个数 n，然后将元素入队到队列，再将队列中的前 n 个元素（即除了新入栈的元素之外的全部元素）依次出队并入队到队列，此时队列的前端的元素即为新入栈的元素，且队列的前端和后端分别对应栈顶和栈底。
//由于每次入栈操作都确保队列的前端元素为栈顶元素，因此出栈操作和获得栈顶元素操作都可以简单实现。出栈操作只需要移除队列的前端元素并返回即可，获得栈顶元素操作只需要获得队列的前端元素并返回即可（不移除元素）。
//由于队列用于存储栈内的元素，判断栈是否为空时，只需要判断队列是否为空即可。
//class MyStack {
//public:
//    queue<int> q;
//
//    /** Initialize your data structure here. */
//    MyStack() {
//
//    }
//
//    /** Push element x onto stack. */
//    void push(int x) {
//        int n = q.size();
//        q.push(x);
//        for (int i = 0; i < n; i++) {
//            q.push(q.front());
//            q.pop();
//        }
//    }
//    
//    /** Removes the element on top of the stack and returns that element. */
//    int pop() {
//        int r = q.front();
//        q.pop();
//        return r;
//    }
//    
//    /** Get the top element. */
//    int top() {
//        int r = q.front();
//        return r;
//    }
//    
//    /** Returns whether the stack is empty. */
//    bool empty() {
//        return q.empty();
//    }
//};
//复杂度分析
//时间复杂度：入栈操作 O(n)，其余操作都是 O(1)，其中 n 是栈内的元素个数。
//入栈操作需要将队列中的 n 个元素出队，并入队 n+1 个元素到队列，共有 2n+1 次操作，每次出队和入队操作的时间复杂度都是 O(1)，因此入栈操作的时间复杂度是 O(n)。
//出栈操作对应将队列的前端元素出队，时间复杂度是 O(1)。
//获得栈顶元素操作对应获得队列的前端元素，时间复杂度是 O(1)。
//判断栈是否为空操作只需要判断队列是否为空，时间复杂度是 O(1)。
//空间复杂度：O(n)，其中 n 是栈内的元素个数。需要使用一个队列存储栈内的元素。
