package solution._206


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun reverseList(head: ListNode?): ListNode? {
        var preNode: ListNode? = null
        var curNode = head

        while (curNode != null) {
            val tempNode = curNode.next
            curNode.next = preNode
            preNode = curNode
            curNode = tempNode
        }

        return preNode
    }
}
