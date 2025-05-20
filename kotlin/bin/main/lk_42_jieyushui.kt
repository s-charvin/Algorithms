package solution._42

class Solution {
    fun trap(height: IntArray): Int {
        // ===== 第一步：判断题型特征 =====
        // 观察问题特征:
        //   1. 每个位置 i 的储水量由左右两侧的最高柱子中较矮的那个决定, 即木桶效应
        //   2. 关键性质: 当计算位置 i 的右侧最大高度时, 可以利用位置 i+1 的右侧最大高度(存在递推关系, 左侧同理)
        // 判断适用动态规划的依据:
        //   重叠子问题 - 当计算不同位置的左右最大值时, 存在**重复计算**.
        //     例如位置 i 的左侧最大值=max(位置i-1的左侧最大值, height[i])，该计算过程会被后位置多次依赖
        //   最优子结构 - 全局最大储水量可以分解为每个位置的贡献量之和, 而每个位置的贡献量仅依赖于该位置的左右最大值,
        //   局部最优解(正确计算每个位置的储水量)能组合成全局最优解
        // 问题拆分: **将总雨水分解为每个柱子的垂直方向贡献量**

        // ===== 第二步：定义状态 =====
        // 单序列双状态
        // leftMax[i]: 位置 i 左侧（含i） 的最大高度
        // rightMax[i]: 位置 i 右侧（含i） 的最大高度

        // ===== 第三步: 构建状态转移方程 =====
        // 左最大高度递推: leftMax[i] = max(leftMax[i-1], height[i])  // 从左向右计算
        // 意思是当前下标 i 的左边（包括自己）的最高高度等于前面下标的最大值与当前柱子高度之间的较大者
        // 右最大高度递推: rightMax[i] = max(rightMax[i+1], height[i])  // 从右向左计算
        // 意思是当前下标 i 的右边（包括自己）的最高高度等于后面下标的最大值与当前柱子高度之间的较大者
        // 雨水计算: water += min(leftMax[i], rightMax[i]) - height[i]
        // 下标 i 两边最高柱子的最小值表示水能达到的最大高度, 减去当前位置的高度即为可存水量，若为负则表示无法存水。

        // ===== 第四步: 初始化边界条件 =====
        // 最左端左侧最大即自身
        // 最右端右侧最大即自身

        // ===== 第五步: 确定遍历顺序 =====
        // 正序遍历: 计算 leftMax 从左到右
        // 逆序遍历: 计算 rightMax 从右到左

        val n = height.size
        if (n == 0) return 0

        val leftMax = IntArray(n)
        val rightMax = IntArray(n)

        leftMax[0] = height[0]
        rightMax[n - 1] = height[n - 1]

        for (i in 1 until n) {
            leftMax[i] = maxOf(leftMax[i - 1], height[i])
        }

        for (i in n - 2 downTo 0) {
            rightMax[i] = maxOf(rightMax[i + 1], height[i])
        }

        var result = 0
        for (i in 0 until n) {
            result += maxOf(minOf(leftMax[i], rightMax[i]) - height[i], 0)
        }

        return result
    }
}
