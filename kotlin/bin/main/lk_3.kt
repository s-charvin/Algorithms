package solution._3

class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        // ===== 第一步：判断题型特征 =====
        // 题目要求找出字符串中不含重复字符的最长子串的长度
        // 最简单: 枚举所有子串并判断其是否包含重复字符, 时间复杂度 n2
        // 观察问题特征:
        //    题目要求子串是连续的, 因此可以考虑用一个窗口表示连续子串部分, 窗口内需要保证不含重复字符.
        //    从左向右看, 遇到不重复字符, 则可以继续扩展窗口;
        //    遇到重复字符时, 则需要从左侧开始缩减窗口, 直至遇到的重复字符不再是重复字符即可.
        //
        // 判断适用于双指针的依据:
        //     使用一个指针表示窗口的左边界, 另一个指针表示右边界.

        val occ = mutableSetOf<Char>() // 记录当前窗口内存在的字符(不能重复)
        var rk = -1 // 右指针，初始值为 -1，表示还未开始滑动
        var ans = 0

        for (i in s.indices) {
            if (i != 0) {
                // 左指针向右移动一格, 随之移除字符, 缩小窗口大小
                occ.remove(s[i - 1])
            }
            while (rk + 1 < s.length && s[rk + 1] !in occ) {
                // 右指针不断向右移动，直到遇到重复字符, 确定窗口终点
                // 窗口遇到终点, 则随之左指针移动, 开始缩减窗口大小, 直至
                occ.add(s[rk + 1])
                rk++
            }
            // 计算当前窗口的最大长度
            ans = maxOf(ans, rk - i + 1)
        }
        return ans
    }
}



// class Solution {
//     fun lengthOfLongestSubstring(s: String): Int {
//         val occ = mutableSetOf<Char>() // 记录当前遍历位置的窗口内字符
//         var result = 0
//         for(i in 0 until s.length){
//             // 遍历右指针
//             var rk = i
//             while(rk<s.length && !occ.contains(s[rk])) {
//                 occ.add(s[rk])
//                 rk++
//             }
//             result = max(rk-i, result)
//             occ.clear()
//         }

//         return result
//     }
// }
