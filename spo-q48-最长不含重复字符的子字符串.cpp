/**
 * 题目：最长不含重复字符的子字符串
 * - 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
 * 链接:
 * - https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
 * 考察:
 * - 动态规划
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

using namespace std;

/**
 * 假设字符串字符数为 n 时, 其最长无重复子串长度为 f(n)
 * 则如果去掉最后一个字符, 其最长无重复子串长度为 f(n-1)
 * 由 f(n-1) 去计算 f(n), 需要考虑包含最后一个字符的最长无重复子串与 f(n-1) 中的最长无重复子串哪个更长
 * f(n) = max(f(n-1), 最后一个字符的最长无重复子串长度)
 *
 * 注意到这里需要的包含最后一个字符的最长无重复子串, 可以同样通过动态规划获得,
 *
 * 假设包含第 n 个字符的最长无重复子串长度为 g(n)
 * 则包含第 n-1 个字符的最长无重复子串长度为 g(n-1)
 * 从 g(n-1) 到 g(n), 需要判断第 n-1 个字符的最长无重复子串是否可以继续与第 n 个字符构成无重复子串
 * - 如果能, 说明第 n 个字符 *不存在* 于第 n-1 个字符的最长无重复子串中, g(n) = g(n-1) + 1
 * - 如果不能, 说明存在于第 n-1 个字符的最长无重复子串中, g(n) = 第 n 个字符位置 - 第 n 个字符的上一次出现位置 + 1
 *
 * 这里需要通过一个哈希表去记录每个字符最后一次出现的位置
 *
 * 第 n-1 个字符的最长无重复子串最左侧位置: g_l(n-1) = n - 1 - g(n-1) + 1
 * 字典中获取第 n 个字符的出现位置 dict[dp[n]]
 */

/**
 * 转移方程:
 * - dict[dp[n]] < n - g(n-1), g(n) = g(n-1) + 1
 * - dict[dp[n]] >= n - g(n-1), g(n) = n - dict[dp[n]]
 * - f(n) = max(f(n-1), g(n))
 *
 * 初始状态: g(0)= 0, f(0) = 0,
 * 返回值: f[n]
 */

int lengthOfLongestSubstring(string s)
{
    /* 特殊值处理 */
    if (s == "")
        return 0;
    if (s.size() == 1)
        return 1;
    /* 用一个哈希表存储遇到的字符最后出现的位置 */
    unordered_map<char, int> position;
    /* 初始化方程初值和第一个字符 */
    int f = 0, g = 0, l;
    for (int i = 0; i < s.size(); i++)
    {
        if (position.find(s[i]) == position.end())
            l = -1;
        else
            l = position[s[i]];

        if (l < i - g) /* 第 n 个字符不存在于第 n-1 个字符的最长无重复子串中 */
        {
            g = g + 1;
        }
        else /* 第 n 个字符在第 n-1 个字符的最长无重复子串中 */
            g = i - l;

        position[s[i]] = i;
        f = max(f, g);
    }
    return f;
}