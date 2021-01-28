// returns the breadth first search of the graph
template<typename T>
vector<T> bfs(vector<T> adj[], int V){
  // V is the number of vertices in the graph
    vector<T> v, isVisited(V+1, 0);
    queue<T> q;
    q.push(1);
    isVisited[1]=1;
    while(!q.empty()) {
        T currentNode=q.front();
        v.push_back(currentNode);
        for(int i=0; i<adj[currentNode].size(); i++) {
           if(!isVisited[adj[currentNode][i]])
                q.push(adj[currentNode][i]), isVisited[adj[currentNode][i]]=1;
        }
        q.pop();
    }

    return v;
}

// stores the dfs in vector vdfs
vector<int> vdfs, isVisited(100000, 0);
void dfs(int node, vector<int> adj[]) {
  if(isVisited[node])
    return;

  vdfs.push_back(node);
  isVisited[node]=1;

  for(auto i: adj[node])
    dfs(i, adj);
}

// returns the level of each element of tree. A tree is just a undirected graph with N nodes and N-1 edges
// root is at level 1
template<typename T>
vector<T> level(vector<T> adj[], int V){
  // V is the number of vertices in the graph
    vector<T> v(V+1, 0), isVisited(V+1, 0);
    queue<T> q;
    q.push(1);
		v[1]=1;
		isVisited[1]=1;
    while(!q.empty()) {
        T currentNode=q.front();
        for(int i=0; i<adj[currentNode].size(); i++) {
           if(!isVisited[adj[currentNode][i]]){
                q.push(adj[currentNode][i]);
								isVisited[adj[currentNode][i]]=1;
								v[adj[currentNode][i]]=v[currentNode]+1;
        	 }
				}
        q.pop();
    }

    return v;
}

// taking input for graph
int nodes, edges;
cin>>nodes>>edges;
vector<int> adj[nodes+1];
for(int i=0; i<edges; i++) {
  int a, b;
  cin>>a>>b;
  adj[a].push_back(b);
  // for undirected graph
  // adj[b].push_back(a);
}
