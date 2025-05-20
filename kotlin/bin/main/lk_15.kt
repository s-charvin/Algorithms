
class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        // 暴力解法 N3
        // 问题 1: 相同位置, 不同顺序导致重复, 如 [a, b, c] 和 [b, a, c] 等情况.
        // 解决办法: 先排序, 然后保证 a =< b =< c
        // 问题 2: 不同位置, 但是相同值导致重复
        // 解决办法: 相邻两次不能相等.
        // 问题 3: 因为求和公式固定特性, 固定 a, 则 b 增加, c 一定减少.
        // 解决办法: b 右移动, c 左移动.
        val n = nums.size
        nums.sort()
        val ans = mutableListOf<List<Int>>()

        // 枚举 a
        for (first in 0 until n) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) continue

            // c 对应的指针初始指向数组的最右端
            var third = n - 1
            val target = -nums[first]

            // 枚举 b
            for (second in first + 1 until n) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) continue

                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    third--
                }

                // 如果指针重合，则随着 b 后续的增加，就不会有满足 a+b+c=0 并且 b < c 的 c 了，可以退出循环
                if (second == third) break

                if (nums[second] + nums[third] == target) {
                    ans.add(listOf(nums[first], nums[second], nums[third]))
                }
            }
        }
        return ans
    }
}
