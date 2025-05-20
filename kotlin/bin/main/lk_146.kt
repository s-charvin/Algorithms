package solution._146

class LRUCache(val capacity: Int) {

    private data class Node(val key: Int, var value: Int, var prev: Node? = null, var next: Node? = null)

    private val map = HashMap<Int, Node>()
    private val head = Node(0, 0) // 伪头节点
    private val tail = Node(0, 0) // 伪尾节点

    init {
        head.next = tail
        tail.prev = head
    }

    fun get(key: Int): Int {
        val node = map[key] ?: return -1
        moveToHead(node)
        return node.value
    }

    fun put(key: Int, value: Int) {
        if (map.containsKey(key)) {
            val node = map[key]!!
            node.value = value
            moveToHead(node)
        } else {
            if (map.size >= capacity) {
                removeTail()
            }
            val newNode = Node(key, value)
            map[key] = newNode
            addToHead(newNode)
        }
    }

    private fun moveToHead(node: Node) {
        removeNode(node)
        addToHead(node)
    }

    private fun addToHead(node: Node) {
        node.next = head.next
        node.prev = head
        head.next!!.prev = node
        head.next = node
    }

    private fun removeNode(node: Node) {
        node.prev!!.next = node.next
        node.next!!.prev = node.prev
    }

    private fun removeTail() {
        val node = tail.prev!!
        removeNode(node)
        map.remove(node.key)
    }
}

/**
 * 使用示例：
 * val cache = LRUCache(2)
 * cache.put(1, 1)
 * cache.put(2, 2)
 * println(cache.get(1)) // 1
 * cache.put(3, 3)  // 淘汰 2
 * println(cache.get(2)) // -1 (被淘汰)
 */

