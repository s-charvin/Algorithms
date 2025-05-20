package solution._59

class Solution {
    fun generateMatrix(n: Int): Array<IntArray> {
        val matrix = Array(n){
            IntArray(n)
        }
        var num = 1

        var top = 0
        var bottom = n - 1
        var left = 0
        var right = n - 1

        while(top<=bottom && left <= right){
            // 从左到右
            for(i in left .. right){
                matrix[top][i] = num
                num++
            }
            top++
            // 从上到下
            for(i in top .. bottom) {
                matrix[i][right] = num
                num++
            }
            right--

            // 从右到左
            if(right>=left){
                for(i in right downTo left) {
                    matrix[bottom][i] = num
                    num ++
                }
                bottom--
            }

            // 从下到上
            if(bottom>=top){
                for(i in bottom downTo top) {
                    matrix[i][left] = num
                    num++
                }
                left++
            }
        }

        return matrix
    }
}