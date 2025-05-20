/**
 * 题目：翻转单词顺序
 * - 输入一个英文句子, 翻转句子中单词的顺序, 但单词内字符的顺序不变, 为简单起见, 标点符号和普通字母一样处理.
 * 例如输入字符串 "I am a student.", 则输出 "student. a am I".
 * 链接:
 * - https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * 考察:
 * - 双指针
 * 基本注意点
 * -
 * 高阶注意点
 * -
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

/**
 * 通过双指针从后往前记录每个单词的边界, 然后添加到新字符串中
 */
string reverseWords(string s)
{
    if (s.empty())
        return s;
    string res;
    int l = s.size() - 1, r = s.size() - 1;

    while (l > -1 && r > -1)
    {
        r = l;
        while (r > -1 && s[r] == ' ')
            r--; /* 跳过单词右侧空白 */

        if (r == -1)
            break; /* 判断是否遍历完所有单词 */

        l = r;
        while (l > -1 && s[l] != ' ')
            l--; /* 获取单词左边界 */

        // res = res + s.substr(l + 1, r - l) + ' '; /* 存储单词及其分隔符 */
        res = std::move(res) + std::move(s.substr(l + 1, r - l)) + std::move(' '); /* 使用移动语义, 减少 substr 的字符串拷贝次数 */
    }
    res.pop_back();
    return res;
}

/**
 * 通过指针从后往前记录判断字符是否为空, 然后添加到新字符串中
 */
string reverseWords(string s)
{
    istringstream ss(s);
    string res, str;
    while (ss >> str)
        res = str + ' ' + res;
    return res.substr(0, res.size() - 1);
}

/**
 * 利用istringstream对象以空格为分隔符把字符串分开的特性, 将分开得到的单词逐一流入字符串并进行拼接
 */
string reverseWords(string s)
{
    stack<string> stk;
    string res, str;
    istringstream ss(s);
    while (ss >> str)
        stk.push(str), stk.push(" ");
    if (!stk.empty())
        stk.pop();
    while (!stk.empty())
        res += stk.top(), stk.pop();
    return res;
}
