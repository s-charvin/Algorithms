package solution._92

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun reverseBetween(head: ListNode?, left: Int, right: Int): ListNode? {
        // 边界
        if (head == null || left == right) return head

        val resultHead = ListNode(0)
        resultHead.next = head
        var headPreNode: ListNode? = resultHead

        // 1. 找到反转区间前一个节点
        for (i in 0 until left - 1) {
            headPreNode = headPreNode?.next
        }

        // 2. 找到反转区间的尾节点
        var tailNode = headPreNode?.next
        for (i in 0 until right - left) {
            tailNode = tailNode?.next
        }

        val tailNextNode = tailNode?.next

        // 3. 反转区间和合并结果
        val (newHead, newTail) = reverse(headPreNode?.next!!, tailNode!!)
        headPreNode?.next = newHead
        newTail.next = tailNextNode

        // 4. 返回新的头节点
        return resultHead.next
    }

    fun reverse(left: ListNode, right: ListNode): Pair<ListNode, ListNode> {
        var preNode: ListNode? = null
        var curNode: ListNode? = left

        while (curNode != right) {
            val tempNode = curNode?.next
            curNode?.next = preNode
            preNode = curNode
            curNode = tempNode
        }
        curNode?.next = preNode

        return Pair<ListNode, ListNode>(right, left)
    }
}
