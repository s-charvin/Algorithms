package solution._103

import java.util.*

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    fun zigzagLevelOrder(root: TreeNode?): List<List<Int>> {
        val result = mutableListOf<List<Int>>()
        if(root == null){
            return result
        }

        val queue = java.util.ArrayDeque<TreeNode>()
        queue.offer(root)
        var is

        while(queue.isNotEmpty()){
            val levelNum = queue.size
            val levelList = mutableListOf<Int>()
            for(i in 1..levelNum){
                val node = queue.poll()
                levelList.add(node.`val`)
                node.left?.let{
                    queue.offer(it)
                }
                node.right?.let{
                    queue.offer(it)
                }
            }

            result.add(levelList.toList())
        }

        return result
    }
}
