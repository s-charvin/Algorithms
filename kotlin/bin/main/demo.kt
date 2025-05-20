// demo.kt

// 定义一个简单链表节点的数据类
data class ListNode(var value: Int, var next: ListNode? = null)

// 普通函数
fun add(x: Int, y: Int): Int {
    return x + y
}

// 表达式函数
fun multiply(x: Int, y: Int) = x * y

// 高阶函数，接受 lambda 表达式作为参数
fun operate(x: Int, y: Int, op: (Int, Int) -> Int): Int = op(x, y)

// 函数默认参数与命名参数示例
fun greet(name: String, greeting: String = "Hello") {
    println("$greeting, $name!")
}

// 扩展函数，为 String 添加返回最后一个字符的功能
fun String.lastChar(): Char = this[this.length - 1]

// 扩展属性，为 String 添加获取首字符的属性
val String.firstChar: Char
    get() = this[0]

// 在 "2. 常用数据结构" 部分添加：
// 2.10 带索引的集合遍历
fun indexedIterationDemo() {
    val colors = listOf("Red", "Green", "Blue")

    // 使用 forEachIndexed
    println("\nforEachIndexed 示例:")
    colors.forEachIndexed { index, color ->
        println("颜色 $index 是 $color")
    }
}

// 在 Map 操作部分补充：
fun mapOperationsDemo() {
    val wordCount = mutableMapOf("apple" to 1, "banana" to 2)

    // 使用 getOrDefault
    println("\ngetOrDefault 示例:")
    println("apple 出现次数: ${wordCount.getOrDefault("apple", 0)}")
    println("orange 出现次数: ${wordCount.getOrDefault("orange", 0)}")

    // 使用 !! 非空断言操作符（需谨慎使用）
    val unsafeValue = wordCount["apple"]!! + 1
    println("非空断言后的计算: $unsafeValue")
}

// 在集合操作部分补充：
fun collectionOperationsDemo() {
    val numbers = listOf(1, 2, 3, 4, 5)

    // 使用 all 检查所有元素
    println("\nall 检查示例:")
    println("所有元素都是偶数吗？${numbers.all { it % 2 == 0 }}")  // 输出 false
    println("所有元素都小于10吗？${numbers.all { it < 10 }}")    // 输出 true
}

// 在控制流部分补充标签返回示例：
fun labelReturnDemo() {
    println("\n标签返回示例:")
    listOf(1, 2, 3, 4, 5).forEach {
        if (it == 3) return@forEach // 返回到 lambda 的调用者 forEach
        print("$it ")
    }
    println("\n跳过了数字3")
}

// -------------------------------
// 补充的扩展函数（可添加到原扩展函数部分）
// -------------------------------
// 字符串字符统计扩展函数（类似算法中的字符统计逻辑）
fun String.charFrequency(): Map<Char, Int> {
    val frequency = mutableMapOf<Char, Int>()
    this.forEach { char ->
        frequency[char] = frequency.getOrDefault(char, 0) + 1
    }
    return frequency
}


// 程序起始函数
fun main() {
    // -------------------------------
    // 1. Kotlin 基础语法
    // -------------------------------

    // 1.1 变量声明
    val immutableVal = 10   // 不可变变量
    var mutableVar = 20       // 可变变量
    mutableVar = 30
    val integerByte: Byte = 100 // 字节变量, 取值范围: -2^7(-128) ~ 2^7-1(127)
    val integerShort: Short = 100 // 短整形变量, 取值范围: -2^15(-32768) ~ 2^15-1(32767)
    val integerInt: Int = 100 // 整形变量, 取值范围: -2^31(-2147483648) ~ 2^31-1(2147483647)
    val integerLong: Long = 100 // 长整形变量, 取值范围: -2^63(-9223372036854775808L) ~ 2^63-1(9223372036854775807L)
    val integerUByte: UByte = 100u // 无符号字节变量, 取值范围: 0 ~ 255
    val integerUShort: UShort = 100u // 无符号短整形变量, 取值范围: 0 ~ 65535
    val integerUInt: UInt = 100u // 无符号整形变量, 取值范围: 0 ~ 4294967295
    val integerULong: ULong = 100u // 无符号长整形变量, 取值范围: 0 ~ 18446744073709551615
    val numberFloat: Float = 10.5f // 单精度浮点数, 取值范围: 1.4E-45F ~ 3.4028235E38F
    val numberDouble: Double = 10.5 // 双精度浮点数, 取值范围: 4.9E-324 ~ 1.7976931348623157E308
    val booleanVal: Boolean = true // 布尔变量, 取值范围: true/false
    val charVal: Char = 'A' // 字符变量, 取值范围: '\u0000' ~ '\uffff'
    val stringVal: String = "Hello, Kotlin!" // 字符串变量
    println("immutableVal = $immutableVal, mutableVar = $mutableVar")

    // 1.2 函数与 Lambda 表达式
    println("add(5, 3) = ${add(5, 3)}")
    println("multiply(5, 3) = ${multiply(5, 3)}")

    val sumLambda = { x: Int, y: Int -> x + y }
    println("Lambda sum: ${sumLambda(4, 6)}")

    println("operate subtraction: ${operate(10, 4) { a, b -> a - b }}")

    // 1.3 控制流
    // if/else 表达式
    val max = if (immutableVal > mutableVar) immutableVal else mutableVar
    println("Max value = $max")

    // when 表达式
    val num = 2
    when (num) {
        1 -> println("num is 1")
        2 -> println("num is 2")
        else -> println("num is something else")
    }

    // 异常处理
    try {
        val result = 10 / 0
        println(result)
    } catch (e: Exception) {
        println("Caught exception: ${e.message}")
    }

    // -------------------------------
    // 2. 常用数据结构
    // -------------------------------

    // 2.1 数组
    val arr = arrayOf(1, 2, 3)
    println("Array: ${arr.joinToString()}")

    // 原生类型数组，避免装箱，提高性能
    val intArr = IntArray(5) { it * 2 }  // 初始化时通过 lambda 指定值
    println("IntArray: ${intArr.joinToString()}")

    // 2.2 列表
    val immutableList = listOf(1, 2, 3)
    println("Immutable list: $immutableList")

    val mutableList = mutableListOf(1, 2, 3)
    mutableList.add(4)
    println("Mutable list: $mutableList")

    // 2.3 集合（Set）
    val immutableSet = setOf(1, 2, 3)
    println("Immutable set: $immutableSet")

    val mutableSet = mutableSetOf(1, 2, 3)
    mutableSet.add(4)
    println("Mutable set: $mutableSet")

    // 2.4 映射（Map）
    val immutableMap = mapOf("a" to 1, "b" to 2)
    println("Immutable map: $immutableMap")

    val mutableMap = mutableMapOf("a" to 1, "b" to 2)
    val mutableMap2 = mutableMapOf<String, Int>()
    mutableMap["c"] = 3
    println("Mutable map: $mutableMap")

    // 2.5 队列和栈（使用 ArrayDeque）
    val queue = ArrayDeque<Int>()
    queue.add(1)
    queue.add(2)
    println("Queue removeFirst: ${queue.removeFirst()}")  // 输出 1

    val stack = ArrayDeque<Int>()
    stack.addLast(1)
    stack.addLast(2)
    println("Stack removeLast: ${stack.removeLast()}")    // 输出 2

    // 2.6 堆（优先队列），使用 Java 的 PriorityQueue
    val heap = java.util.PriorityQueue<Int>()
    heap.offer(3)
    heap.offer(1)
    heap.offer(2)
    println("PriorityQueue poll: ${heap.poll()}")  // 输出 1（最小堆）

    // 2.7 序列（Sequence）: 惰性计算链式操作
    val sequence = sequenceOf(1, 2, 3, 4, 5)
    val seqResult = sequence.map { it * 2 }
        .filter { it > 5 }
        .toList()
    println("Sequence result: $seqResult")

    // 2.8 Pair, Triple, 及数据类
    val pair = Pair("Kotlin", 1.8)
    println("Pair: ${pair.first}, ${pair.second}")

    val triple = Triple("A", 10, true)
    println("Triple: ${triple.first}, ${triple.second}, ${triple.third}")

    // 使用数据类构造简单链表
    val node1 = ListNode(1)
    val node2 = ListNode(2)
    node1.next = node2
    println("Linked list: ${node1.value} -> ${node1.next?.value}")

    // 2.9 解构声明
    val (language, version) = pair
    println("Destructured Pair: $language, $version")

    // -------------------------------
    // 3. Kotlin 语法糖
    // -------------------------------

    // 3.1 区间与范围操作
    println("Range 1..5:")
    for (i in 1..5) {
        print("$i ")
    }
    println()

    val tempResult = mutableListOf(1)
    val test = tempResult[0]

    println("半开区间 (1 until 5):")
    for (i in 1 until 5) {
        print("$i ")
    }
    println()

    println("倒序区间 (5 downTo 1):")
    for (i in 5 downTo 1) {
        print("$i ")
    }
    println()

    println("步长 (1..10 step 2):")
    for (i in 1..10 step 2) {
        print("$i ")
    }
    println()

    // 3.2 集合操作和 in 运算符
    val fruits = listOf("apple", "banana", "cherry")
    if ("banana" in fruits) {
        println("Found banana in fruits")
    }
    // 使用 forEach 遍历集合
    fruits.forEach { fruit ->
        println("Fruit: $fruit")
    }


    // 3.3 字符串模板
    val name = "Alice"
    println("Hello, $name!")
    val a = 5
    val b = 3
    println("Sum: ${a + b}")

    // 3.4 默认参数与命名参数
    greet("Bob")  // 使用默认 greeting
    greet(name = "Bob", greeting = "Hi")  // 命名参数

    // 3.5 扩展函数与扩展属性
    println("Last character of \"Kotlin\": ${"Kotlin".lastChar()}")
    println("First character of \"Kotlin\": ${"Kotlin".firstChar}")


    // 新增示例
    indexedIterationDemo()
    mapOperationsDemo()
    collectionOperationsDemo()
    labelReturnDemo()

    // 字符频率统计示例
    println("\n字符频率统计示例:")
    val testStr = "hello"
    println("'$testStr' 字符频率: ${testStr.charFrequency()}")

    // -------------------------------
    // 补充集合扩展函数演示
    // -------------------------------

    val numbers = listOf(1, 2, 3, 4, 5, 4, 3)
    val words = listOf("apple", "banana", "cherry", "date")
    val map = mapOf("a" to 1, "b" to 2, "c" to 3)

    // 1. 过滤操作
    println("\n=== 过滤操作 ===")
    println("取前3个元素: ${numbers.take(3)}") // [1, 2, 3]
    println("丢弃前2个元素: ${numbers.drop(2)}") // [3, 4, 5, 4, 3]
    println("保留偶数: ${numbers.filter { it % 2 == 0 }}") // [2, 4, 4]
    println("分割奇偶数: ${numbers.partition { it % 2 == 0 }}") // ([2,4,4], [1,3,5,3])

    // 2. 转换操作
    println("\n=== 转换操作 ===")
    println("平方数: ${numbers.map { it * it }}") // [1,4,9,16,25,16,9]
    println("扁平化处理: ${words.flatMap { it.toList() }}") // 展开所有字符
    println("按长度分组: ${words.groupBy { it.length }}") // {5=[apple], 6=[banana, cherry], 4=[date]}

    // 3. 聚合操作
    println("\n=== 聚合操作 ===")
    println("总和: ${numbers.sum()}") // 22
    println("平均值: %.2f".format(numbers.average())) // 3.14
    println("最大值: ${numbers.max()}") // 5
    println("累计乘积: ${numbers.fold(1) { acc, i -> acc * i }}") // 1440

    // 4. 查找判断
    println("\n=== 查找判断 ===")
    println("存在大于4的元素: ${numbers.any { it > 4 }}") // true
    println("首个偶数: ${numbers.find { it % 2 == 0 }}") // 2
    println("最后一个偶数: ${numbers.findLast { it % 2 == 0 }}") // 4

    // 5. Map 操作
    println("\n=== Map 操作 ===")
    println("转换值: ${map.mapValues { it.value * 10 }}") // {a=10, b=20, c=30}
    println("过滤键: ${map.filterKeys { it > "a" }}") // {b=2, c=3}
    println("反向映射: ${map.entries.associate { (k,v) -> v to k }}") // {1=a, 2=b, 3=c}

    // 6. 高级操作
    println("\n=== 高级操作 ===")
    println("去重: ${numbers.distinct()}") // [1,2,3,4,5]
    println("分块: ${numbers.chunked(3)}") // [[1,2,3], [4,5,4], [3]]
    println("带索引遍历:")
    numbers.withIndex().forEach { (i, v) ->
        println("索引 $i → 值 $v")
    }

    // 7. 链式操作
    println("\n=== 链式操作 ===")
    val result = words
        .filter { it.length > 4 }
        .map { it.uppercase() }
        .sortedDescending()
        .joinToString(" | ")

    println("处理结果: $result") // CHERRY | BANANA | APPLE
}
