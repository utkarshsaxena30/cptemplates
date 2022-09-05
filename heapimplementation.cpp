// NOTE: Implementations are for max heap

// purpose: place index i in the correct place in the heap
// time: O(logN)
void max_heapify(vector<int> &heap, int i) {
    int left_child = 2 * i, right_child = 2 * i + 1, largest_idx = i;
    if(left_child < heap.size() && heap[left_child] > heap[i]) largest_idx = left_child;
    if(right_child < heap.size() && heap[right_child] > heap[largest_idx]) largest_idx = right_child;

    if(largest_idx != i) {
        swap(v[i], v[largest]);
        max_heapify(v, largest);
    }
}

// purpose: building the heap
// time: O(N)
void build_maxheap(vector<int> v) {
    // since nodes greater than N / 2 are leaves which are already 1 element heaps
    for(int i = N / 2; i >= 1; i--) max_heapify(v, i);
}

// 1. get max element -> return heap[1] 
//    time: O(1)
// 2. pop (max element) -> swap last element with heap[1], pop last element, max_heapify index 1 
//    time: O(logN)
// 3. increase value -> increase value and wap with parent until parent's value is less than curr value
//    time: O(logN)
// 4. insert value -> insert at last, perform increase value
//    time: O(logN)