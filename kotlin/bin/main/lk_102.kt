package solution._102

import java.util.*

class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun levelOrder(root: TreeNode?): List<List<Int>> {
        val result = mutableListOf<List<Int>>()

        if(root == null){
            return result
        }

        val deque: Queue<TreeNode> = java.util.ArrayDeque<TreeNode>()
        deque.offer(root)

        while(deque.isNotEmpty()){
            val levelNum = deque.size
            val levelList = mutableListOf<Int>()
            for(i in 1..levelNum){
                val node = deque.poll()
                levelList.add(node.`val`)
                node?.left?.let{
                    deque.offer(it)
                }
                node?.right?.let{
                    deque.offer(it)
                }
            }
            result.add(levelList.toList())
        }

        return result
    }
}


