/**
 * @file spo-q30-包含min函数的栈.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-01-08
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：
 * * 定义栈 (stack) 的数据结构，
 * * 并在该类型中实现一个能够得到栈的最小元素的 min 函数,
 * * 且在该栈中, 调用 min()、push(item) 及 pop() 函数的时间复杂度
 * * 都是 O(1)。
 * 链接:
 * * https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/?envType=study-plan&id=lcof&plan=lcof&plan_progress=cuzoj2j
 * 考察:
 * * 栈(先进后出)
 * 基本注意点
 * * 栈支持的操作: pop(), push(item), top()
 * * 函数时间复杂度 O(1) 应该如何实现
 * 高阶注意点
 * *
 */

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

// 官方题解
/**
 * 题解思路:
 * 通过一个额外的栈来保存每个数据入栈后, 当前时刻元素栈中对应的最小值.
 *
 * 具体实现:
 * 使用两个栈, 其中元素栈用来存储实际的入栈元素,
 * 辅助栈用于存储每个元素入栈后, 当前时刻元素栈中对应的最小值,
 * 并且这两个栈的插入与删除操作是同步的.
 *
 * 也就是说, 当一个元素要入栈时, 我们取(辅助栈栈顶存储的最小值,
 * 与当前要入栈元素)比较得出最小值, 并将这个最小值插入辅助栈中.
 * 而当一个元素要出栈时, 我们把辅助栈的栈顶元素也一并弹出.
 */
class MinStack
{
private:
    stack<int> x_stack;
    stack<int> min_stack;

public:
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int x)
    { // 辅助栈与元素栈同步入栈,
        // 其中辅助栈入栈元素为当前时刻所有输入元素的最小值
        x_stack.push(x);
        min_stack.push(::min(min_stack.top(), x));
    }

    void pop()
    { // 辅助栈与元素栈同步出栈
        x_stack.pop();
        min_stack.pop();
    }

    int top()
    { // 获取元素栈的栈顶元素
        return x_stack.top();
    }

    int min()
    { // 获取辅助栈的栈顶元素, 也就是当前时刻所有输入元素的最小值
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */