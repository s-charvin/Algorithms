package solution._160


class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */

class Solution {
    fun getIntersectionNode(headA: ListNode?, headB: ListNode?): ListNode? {
        if (headA == null || headB == null) {
            return null
        }

        var curNode1 = headA
        var curNode2 = headB

        while (curNode1 != curNode2) {

            if (curNode1 == null) {
                curNode1 = headB
            } else {
                curNode1 = curNode1?.next
            }

            if (curNode2 == null) {
                curNode2 = headA
            } else {
                curNode2 = curNode2?.next
            }
        }

        return curNode1
    }
}