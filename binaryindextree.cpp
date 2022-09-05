/* 
 UNDERSTANDING FENWICK / BINARY INDEX TREE

 Note: Array is considered to be 1 indexed.
 1. If the rightmost bit of the index of a number is set(1) just copy it over as it is. This makes up for half the elements of the original array. It can be imagined as the bottom most layer of the tree.
 2. If the second rightmost bit of the index of a number is set(1), we sum two values, this number and the number before it. This makes up for half the remaining elements.
 3. If the third rightmost bit of the index of a number is set(1), we sum four values, this number and three numbers before it.
 ..And so on.

 The relation: if the nth rightmost bit of a number is set, the pre calculated new array contains the sum of 2^(n - 1) elements, from i - 2^(n - 1) - 1 to i.
*/

// to sum from index 1 to i
// T is the array formed after following the above relation
// Time: O(log2N)
int sum(int i) {
    int ans = 0;
    while(i > 0) {
        sum += T[i];
        i -= i & -i; // flip the last set bit
    }
    return ans;
}

// update at index i, the change k, i.e., A[i] becomes A[i] + k
void update(int i, int k) {
    while(i < T.size()) {
        T[i] += k;
        i += i & -i;
    }
}

// populate the fenwick tree
// initialise T to size N + 1 and all elements 0. Then call update for each element of A. Time: O(NlogN).