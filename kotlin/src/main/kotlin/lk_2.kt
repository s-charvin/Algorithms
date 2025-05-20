package solution._2

class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

class Solution {
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        if (l1 == null) return l2
        if (l2 == null) return l1

        var num1Ptr = l1
        var num2Ptr = l2

        var resultHead: ListNode? = null
        var resultTail: ListNode? = null
        var carry: Int = 0 // 上次计算的进位
        while (num1Ptr != null || num2Ptr != null) {
            val num1 = num1Ptr?.`val` ?: 0
            val num2 = num2Ptr?.`val` ?: 0

            val sum = (num1 + num2 + carry)
            val numTemp = sum % 10
            carry = sum / 10

            if (resultHead == null) {
                resultHead = ListNode(numTemp)
                resultTail = resultHead
            } else {
                resultTail?.next = ListNode(numTemp)
                resultTail = resultTail?.next
            }

            if (num1Ptr != null) {
                num1Ptr = num1Ptr?.next
            }

            if (num2Ptr != null) {
                num2Ptr = num2Ptr?.next
            }

        }

        if (carry > 0) {
            resultTail?.next = ListNode(carry)
        }

        return resultHead
    }
}
