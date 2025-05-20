package solution._20

class Solution {
    fun isValid(s: String): Boolean {
        val n = s.length
        if (n % 2 == 1) {
            return false
        }

        val pairs = mapOf(
            ')' to '(',
            ']' to '[',
            '}' to '{'
        )
        val stack = ArrayDeque<Char>()

        for (ch in s) {
            if (ch in pairs) {
                if (stack.isEmpty() || stack.last() != pairs[ch]) {
                    return false
                }
                stack.removeLast()
            } else {
                stack.addLast(ch)
            }
        }
        return stack.isEmpty()
    }
}

