package solution._141

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
    fun hasCycle(head: ListNode?): Boolean {
        var slowNode: ListNode? = head
        var fastNode: ListNode? = head?.next?.next

        while (slowNode != null && fastNode != null) {
            if (slowNode == fastNode) {
                return true
            } else {
                slowNode = slowNode?.next
                fastNode = fastNode?.next?.next
            }
        }

        return false
    }
}
