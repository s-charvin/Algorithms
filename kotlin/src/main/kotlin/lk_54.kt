package solution._54

class Solution {
    fun spiralOrder(matrix: Array<IntArray>): List<Int> {
        val result = mutableListOf<Int>()
        if (matrix.isEmpty() || matrix[0].isEmpty()) return result

        // 限定矩形边界
        var top = 0
        var bottom = matrix.size - 1
        var left = 0
        var right = matrix[0].size - 1

        while (top <= bottom && left <= right) {
            // 从左向右
            for(i in left .. right) {
                result.add(matrix[top][i])
            }
            top++
            // 从上到下
            for (i in top..bottom) {
                result.add(matrix[i][right])
            }
            right--
            // 从右到左
            if (top <= bottom) {
                for (i in right downTo left) {
                    result.add(matrix[bottom][i])
                }
                bottom--
            }
            // 从下到上
            if (left <= right) {
                for (i in bottom downTo top) {
                    result.add(matrix[i][left])
                }
                left++
            }
        }
        return result
    }
}
