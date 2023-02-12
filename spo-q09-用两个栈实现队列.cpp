/**
 * @file spo-q09-用两个栈实现队列.cpp
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
 * * 用两个栈 (stack) 实现一个队列 (queue)。队列的声明如下，
 * * 请实现它的两个函数 `appendTail` 和 `deleteHead` ，
 * * 分别完成在队列尾部插入整数和在队列头部删除整数的功能。
 * * (若队列中没有元素，deleteHead 操作返回 -1 )
 *
 * 链接: https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 * 考察: 队列(先进先出), 栈(先进后出)
 * 基本注意点
 * * 只允许在队列的前端（front）进行删除操作
 * * 只允许在队列的后端（rear）进行插入操作
 * * 栈支持的操作: pop(), push(item), top()
 *
 * 高阶注意点
 * *
 *
 */

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

// 官方题解
/**
 * 题解思路:
 * 利用栈先进后出的特性, 使用两个栈间接实现输入数据的先进先出
 * 也就是队列结构
 *
 * 具体实现:
 * 将一个栈当作输入栈, 即队列后端，用于压入 `appendTail` 传入的数据；
 * 另一个栈当作输出栈, 即队列前端，用于 `deleteHead` 操作。
 * 每次前端输出栈进行 `deleteHead` 时，若前端输出栈为空则
 * 将后端输入栈的全部数据依次弹出并压入到前端输出栈，
 * 这样前端输出栈从栈顶往栈底的顺序就是队列从队首往队尾的顺序。
 *
 */
class CQueue
{
private:
    stack<int> inStack;  // 后端输入栈, 存放 int 类型值
    stack<int> outStack; // 前端输出栈, 存放 int 类型值

public:
    CQueue() {}

    void appendTail(int value)
    // 在输入栈 `inStack` 压入 (push) 传入的数据 `value`.
    {
        inStack.push(value);
    }

    int deleteHead()
    {
        if (outStack.empty())
        {
            if (inStack.empty()) // 如果队列为空
            {
                return -1;
            }
            // 如果前端输出栈为空, 但是后端输入栈有了新数据
            // 将后端输入栈的全部数据依次弹出并压入前端输出栈
            // 其实也相当于通过两个栈先进后出的特性, 变相的实现先进先出
            while (!inStack.empty())
            {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        // 如果前端输出栈有数据, 则可先把当前已经排序号的数据处理完
        // 之后再考虑新输入的数据
        int value = outStack.top();
        outStack.pop();
        return value;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */