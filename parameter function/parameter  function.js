/**
 * @param {number} k
 * @param {number} w
 * @param {number[]} profits
 * @param {number[]} capital
 * @return {number}
 */
var findMaximizedCapital = function(k, w, profits, capital) {
    let n = profits.length;
    let projects = [];
    for (let i = 0; i < n; i++) {
        projects.push([capital[i], profits[i]]);
    }
    // Sort projects based on their capital requirements
    projects.sort((a, b) => a[0] - b[0]);
    // Max-heap to keep track of the max profit we can achieve
    let maxHeap = new MaxHeap();
    let ptr = 0;
    for (let i = 0; i < k; i++) {
        // Add all affordable projects to the max-heap
        while (ptr < n && projects[ptr][0] <= w) {
            maxHeap.push(projects[ptr][1]);
            ptr++;
        }
        // If we can't afford any more projects, break
        if (maxHeap.isEmpty()) {
            break;
        }
        // Select the project with the maximum profit
        w += maxHeap.pop();
    }
    return w;
};
// MaxHeap class implementation
class MaxHeap {
    constructor() {
        this.heap = [];
    }  
    push(val) {
        this.heap.push(val);
        this._heapifyUp();
    }
    pop() {
        if (this.isEmpty()) return null;
        const max = this.heap[0];
        const end = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = end;
            this._heapifyDown();
        }
        return max;
    }
    isEmpty() {
        return this.heap.length === 0;
    }
    _heapifyUp() {
        let idx = this.heap.length - 1;
        const element = this.heap[idx];
        while (idx > 0) {
            let parentIdx = Math.floor((idx - 1) / 2);
            let parent = this.heap[parentIdx];
            if (element <= parent) break;
            this.heap[idx] = parent;
            idx = parentIdx;
        }
        this.heap[idx] = element;
    }
    _heapifyDown() {
        let idx = 0;
        const length = this.heap.length;
        const element = this.heap[0];
        while (true) {
            let leftChildIdx = 2 * idx + 1;
            let rightChildIdx = 2 * idx + 2;
            let leftChild, rightChild;
            let swap = null;
            
            if (leftChildIdx < length) {
                leftChild = this.heap[leftChildIdx];
                if (leftChild > element) {
                    swap = leftChildIdx;
                }
            }
            
            if (rightChildIdx < length) {
                rightChild = this.heap[rightChildIdx];
                if (
                    (swap === null && rightChild > element) || 
                    (swap !== null && rightChild > leftChild)
                ) {
                    swap = rightChildIdx;
                }
            }
            
            if (swap === null) break;
            this.heap[idx] = this.heap[swap];
            idx = swap;
        }
        this.heap[idx] = element;
    }
};
