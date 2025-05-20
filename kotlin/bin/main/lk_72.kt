package solution._72

class Solution {
    fun minDistance(word1: String, word2: String): Int {
        // ===== 第一步：判断题型特征 =====
        // 观察问题特征:
        // 重点目标: 单词转换到目标的最少操作数 = 单词长度变为一致, 单词种类变为一致.
        // 目标的难度是与单词的长度正相关的, 单词越少, 就越容易计算距离. 是否可以考虑将问题从单词长度层面进行拆分?

        // 判断适用动态规划的依据:
        // 问题拆分:
        //   原文题 A->B
        //   先拆分为 A[N]->B[M-1], 最少操作数 a, 则 A->B 需要 a+1 (表示 A[N] 中只需要新增一个字符就可以了)
        //   也可拆分为 A[N-1]->B, 最少操作数 b, 则 A->B 需要 b+1 (表示 A[N-1] 只需要删除一个字符)
        //   也可拆分为 A[N-1]->B[N-1], 最少操作数 c, 则 A->B 需要不超过 c+1(表示 A[N] 只需要替换一个字符就可以了, 如果字符相等, 就不用替换)
        //   也就是说 A->B 的最少操作数 = min((a+1), (b+1), (c+1))
        //   重叠子问题 - 长字符串的编辑距离依赖于短字符串的编辑距离
        //   最优子结构 - 全局最优解包含子问题的最优解

        // ===== 第二步：定义状态 =====
        // 单序列型, 双状态: dp[i]表示前i个元素的状态
        // 双序列型: dp[i][j] 表示两个序列前 i、j 元素的状态
        //
        // dp[i][j]：表示将 word1 的前 i 个字符转换为 word2 的前 j 个字符所需的编辑距离

        // ===== 第三步: 构建状态转移方程 =====
        // 当 A[i] = B[j] 时, dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1])
        // 当 A[i] != B[j] 时, dp[i][j] = min(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1] + 1)

        // ===== 第四步: 初始化边界条件 =====
        // 起点, 边界, 异常值
        // A[0] -> B[j] 时, dp[0][j] = j
        // A[i] -> B[0] 时, dp[i][0] = i

        // ===== 第五步: 确定遍历顺序 =====
        // 正序, 逆序, 多维
        //
        // 长度从小到大遍历, 因此正序遍历即可.

        val n = word1.length
        val m = word2.length

        if(n*m == 0) {
            return n + m
        }

        val dp = Array(n+1){IntArray(m+1)}

        for(i in dp.indices) {
            dp[i][0] = i
        }

        for(j in dp[0].indices){
            dp[0][j] = j
        }

        for(i in 1..n) {
            for(j in 1..m){
                val aChar = word1[i-1]
                val bChar = word2[j-1]
                if(aChar==bChar){
                    dp[i][j] = minOf(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1])
                }else{
                    dp[i][j] = minOf(dp[i][j-1] + 1, dp[i-1][j] + 1, dp[i-1][j-1]+1)
                }
            }
        }
        return dp[n][m]
    }
}
