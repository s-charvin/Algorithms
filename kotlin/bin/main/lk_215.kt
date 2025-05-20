package solution._215

class Solution {
    fun findKthLargest(nums: IntArray, k: Int): Int {
        // 二叉树性质
        // 高度 H
        // 节点数 N
        // 左侧起始节点索引: 2n - 1
        // 第 i 节点的子节点索引: 2i + 1, 2i + 2
        // 最后一个非叶子节点的索引: N/2 - 1
        // 叶子节点的起始索引：N / 2

        var maxHeapDepth = nums.size
        buildMaxHeap(nums, maxHeapDepth)

        // 通过减小 HeapDepth 到 1 和丢弃顶部最大值, 获取第 K 个最大值, 丢弃 k-1次
        for(i in nums.size - 1 downTo nums.size - k + 1){
            val tempV = nums[i]
            nums[i] = nums[0]
            nums[0] = tempV
            maxHeapDepth--
            // 递归处理后续受影响的节点
            heapify(nums, 0, maxHeapDepth)
        }

        return nums[0]
    }

    fun buildMaxHeap(nums: IntArray, maxHeapDepth: Int) {
        for(i in (nums.size)/2-1 downTo 0){
            heapify(nums, i, maxHeapDepth)
        }
    }

    // 最大堆, 递归处理指定节点之后的节点, 性质, 子节点均小于父结点
    // 我需要的是
    fun heapify(nums: IntArray, i: Int, maxHeapDepth: Int) {
        val leftNodeInd = 2*i+1
        val rightNodeInd = 2*i+2

        var maxInd = i

        // 找出最大值索引, maxHeapDepth 用于定义从 i 开始能到达的最大深度.
        if(leftNodeInd < maxHeapDepth && nums[leftNodeInd] > nums[maxInd]){
            maxInd = leftNodeInd
        }
        if(rightNodeInd < maxHeapDepth && nums[rightNodeInd] > nums[maxInd]){
            maxInd = rightNodeInd
        }

        if(maxInd != i){
            val tempV = nums[i]
            nums[i] = nums[maxInd]
            nums[maxInd] = tempV
            // 递归处理后续受影响的节点
            heapify(nums, maxInd, maxHeapDepth)
        }
    }
}
