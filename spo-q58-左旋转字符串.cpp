/**
 * @file spo-q58-左旋转字符串.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-02-13
 *
 * @copyright Copyright (c) 2023
 *
 */

/**
 * 题目：左旋转字符串
 * - 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 * 链接: https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof
 * 考察: 字符串
 * 基本注意点
 * - 如何一个个的将头部字符放到字符串尾部
 * 高阶注意点
 * -
 */

#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**字符串切片法
 * 获取字符串  s[n:] 切片和 s[:n] 切片，使用 "+" 运算符拼接并返回即可。
 */
string reverseLeftWords(string s, int n)
{
    return s.substr(n, s.length()) + s.substr(0, n);
}

/**字符串暴力拼接法
 * 将原字符串拷贝一份, 然后通过 "+" 运算拼接, 再截取对应的位置即可
 * (s+s)[n:size(s)]
 */

string reverseLeftWords(string s, int n)
{
    return (s + s).substr(n, s.size());
}

/**字符串遍历拼接法
 * 将原字符串拷贝一份, 然后通过 "+" 运算拼接, 再截取对应的位置即可
 * (s+s)[n:size(s)]
 */

string reverseLeftWords(string s, int n)
{
    string res;
    for (int i = n; i < s.length(); i++)
        res.push_back(s[i]);
    for (int i = 0; i < n; i++)
        res.push_back(s[i]);
    return res;
}

string reverseLeftWords(string s, int n)
{
    string res = "";
    for (int i = n; i < n + s.length(); i++)
        res += s[i % s.length()];
    return res;
}

/**字符串三次反转
 */

int reverse_string(string &s, int start, int end)
{
    for (int i = start; i <= (start + end) / 2; i++)
    {
        char temp = s[i];
        s[i] = s[start + end - i];
        s[start + end - i] = temp;
    }
    return 0;
}

string reverseLeftWords(string s, int n)
{
    int length = s.length();

    reverse_string(s, 0, length - 1);
    reverse_string(s, 0, length - n - 1);
    reverse_string(s, length - n, length - 1);

    return s;
}

string reverseLeftWords(string s, int n)
{
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    reverse(s.begin(), s.end());
    return s;
}

/**字符串单次翻转
 */
string reverseLeftWords(string s, int n)
{
    auto it = s.begin();
    for (int i = 0; i < n; i++)
    {
        it++;
    }
    rotate(s.begin(), it, s.end());
    return s;
}