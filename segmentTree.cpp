int a[200000], tree[100];

//use buildSegmentTree(0, n-1, 0)
void buildSegmentTree(int start, int end, int node) {
	if(start==end) {
		tree[node]=a[start];
		return;
	}

	int mid=(start+end)/2;

	buildSegmentTree(start, mid, 2*node+1);
	buildSegmentTree(mid+1, end, 2*node+2);

	tree[node]=min(tree[2*node+1], tree[2*node+2]);
}

void updateSegmentTree(int start, int end, int node, int idx, int upd) {

	if(start==end) {
		a[idx]+=upd;
		tree[node]+=upd;
		return;
	}

	int mid=(start+end)/2;

	if(start<=idx && idx<=mid)
		updateSegmentTree(start, mid, 2*node+1, idx, upd);
	else
		updateSegmentTree(mid+1, end, 2*node+2, idx, upd);

	tree[node]=tree[2*node+1]+tree[2*node+2];
}

int query(int start, int end, int node, int l, int r) {

	if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(start, mid, 2*node+1, l, r);
    int p2 = query(mid+1, end, 2*node+2, l, r);
    return (p1 + p2);
}
