package solution._23

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

    fun mergeKLists(lists: Array<ListNode?>): ListNode? {
        return merge(lists.toList(), 0, lists.size - 1)
    }

    private fun merge(lists: List<ListNode?>, l: Int, r: Int): ListNode? {
        if (l == r) return lists[l]
        if (l > r) return null
        val mid = (l + r) / 2
        return mergeTwoList(merge(lists, l, mid), merge(lists, mid + 1, r))
    }

    // fun mergeKLists(lists: Array<ListNode?>): ListNode? {
    //     var ans: ListNode? = null
    //     lists.forEach {
    //         ans = mergeTwoList(ans, it)
    //     }
    //     return ans

    fun mergeTwoList(list1: ListNode?, list2: ListNode?): ListNode? {
        if (list1 == null) return list2
        if (list2 == null) return list1
        val headNode: ListNode = ListNode(0)
        var tailNode: ListNode? = headNode
        var list1CurNode = list1
        var list2CurNode = list2

        while (list1CurNode != null && list2CurNode != null) {
            if (list1CurNode.`val` < list2CurNode.`val`) {
                tailNode?.next = list1CurNode
                list1CurNode = list1CurNode.next
            } else {
                tailNode?.next = list2CurNode
                list2CurNode = list2CurNode.next
            }
            tailNode = tailNode?.next
        }

        tailNode?.let {
            it.next = if (list1CurNode != null) list1CurNode else list2CurNode
        }
        return headNode.next

    }
}