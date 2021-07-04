#ifndef _DATA_STRUCTURES_H_
#define _DATA_STRUCTURES_H_
//DISJOINT SET UNION
class DSU
{
private:
	int n;
	int *parent;
	int *size;

public:
	DSU(int n);
	int root(int x);
	void merge(int x, int y);
	bool areInSame(int x, int y);
	~DSU();
};

DSU::DSU(int n)
{
	this->n = n;
	parent = new int[n];
	size = new int[n];
	for (int i = 0; i < n; ++i) {
		parent[i] = i;
		size[i] = 1;
	}
}
int DSU::root(int x)
{
	if (x < n) {
		if (parent[x] == x)
			return x;
		return parent[x] = root(parent[x]);
	}
	else {
		std::cerr << "ERROR: DSU sizeOutOfBoundException\n";
		x = -1;
	}
	return x;
}
void DSU::merge(int x, int y)
{
	if (x < n && y < n) {
		x = root(x);
		y = root(y);
		if (x != y) {
			if (size[x] < size[y])
				std::swap(x, y);
			parent[y] = x;
			size[x] += size[y];
		}
	} else {
		std::cerr << "ERROR: DSU sizeOutOfBoundException\n";
	}
}
bool DSU::areInSame(int x, int y)
{
	if (root(x) == root(y))
		return true;
	return false;
}
DSU::~DSU()
{
	delete parent;
	delete size;
}

//TRIE
<<<<<<< HEAD
struct trie {
=======
struct trie{
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	trie* next[26];
	int totalwords;
	bool isEndofWord;
	bool junction;
};
trie *getnode() {
	trie *temp = new trie;
	for (int i = 0; i < 26; ++i)
	{
		temp->next[i] = NULL;
	}
	temp->totalwords = 0;
	temp->junction = false;
	return temp;
}
trie* addword(trie* root, string s)
{
	trie *curr = root;
	int L = s.size();
	for (int i = 0; i < L; ++i)
	{
<<<<<<< HEAD
		if (curr->next[s[i] - 'a'] == NULL) {
			if (!curr->isEndofWord)
				curr->junction = true;
			curr->next[s[i] - 'a'] = getnode();
=======
		if(curr->next[s[i]-'a'] == NULL){
			if(!curr->isEndofWord)
				curr->junction = true;
			curr->next[s[i]-'a'] = getnode();
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		}
		curr = curr->next[s[i] - 'A'];
		curr->totalwords++;
	}
	curr->isEndofWord = true;
	return root;
}
bool checkword(trie* root, string s)
{
	int L = s.size();
	for (int i = 0; i < L; ++i)
	{
<<<<<<< HEAD
		if (curr->next[s[i] - 'a'] == NULL)
=======
		if(curr->next[s[i]-'a'] == NULL)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			return false;
		curr = curr->next[s[i] - 'A'];
	}
	return curr->isEndofWord;
}
//TODO : REMOVE FROM TRIE

//BTREE
class BTreeNode
{
private:
	int t;
	int n;
	int *keys;
	BTreeNode **C;
	bool isLeaf;
	void insertNonFull(int k);
	void splitChild(int i, BTreeNode *y);
	bool isFull();
	void traverse();
	void merge(int idx);
	BTreeNode *search(int k);
	void borrowFromSucc(int idx);
	void borrowFromPred(int idx);
	void removeFromLeaf(int idx);
	void removeFromNonLeaf(int idx);
	void remove(int k);
	int getId(int k);
	int getPred(int idx);
	int getSucc(int idx);
public:
<<<<<<< HEAD
	BTreeNode(int t, bool isLeaf);
=======
	BTreeNode(int t, bool isLeaf); 
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	friend class BTree;
};

class BTree
{
private:
	BTreeNode *root;
	int t;
public:
	BTree(int t);
	void insert(int k);
	void traverse()	{ if (root != NULL) root->traverse(); }
	BTreeNode *search(int k) { if (root != NULL) return root->search(k); return NULL;}
	void remove(int k);
};

BTree::BTree(int t)
{
	this->t = t;
	this->root = NULL;
}

BTreeNode::BTreeNode(int t, bool isLeaf)
{
	this->t = t;
	this->isLeaf = isLeaf;
<<<<<<< HEAD
	this->keys = new int[2 * t - 1];
	this->C = new BTreeNode *[2 * t];
=======
	this->keys = new int[2*t-1];
	this->C = new BTreeNode *[2*t];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	this->n = 0;
}

void BTreeNode::traverse()
{
	for (int i = 0; i < n; ++i) {
<<<<<<< HEAD
		if (!isLeaf)
=======
		if(!isLeaf)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			C[i]->traverse();
		std::cout << keys[i] << " ";
	}
	if (!isLeaf)
		C[n]->traverse();
}

BTreeNode *BTreeNode::search(int k)
{
	int start = 0;
<<<<<<< HEAD
	int end = n - 1;
	while (start < end) {
		int mid = (start + end) >> 1;
		if (keys[mid] < k)
=======
	int end = n-1;
	while (start < end) {
		int mid = (start + end) >> 1;
		if(keys[mid] < k)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			start = mid + 1;
		else
			end = mid;
	}
	if (keys[end] == k)
		return this;
	if (isLeaf)
		return NULL;
<<<<<<< HEAD
	if (end == n - 1 && keys[end] < k)
		return C[end + 1]->search(k);
	return C[end]->search(k);
}

void BTree::insert(int k)
=======
	if (end == n-1 && keys[end] < k)
		return C[end+1]->search(k);
	return C[end]->search(k);
}

void BTree::insert(int k) 
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
{
	if (root == NULL) {
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	}
	else if (root->isFull()) {
		BTreeNode *newroot = new BTreeNode(t, false);
		newroot->C[0] = root;
		root = newroot;
		newroot = root->C[0];
		root->splitChild(0, newroot);
		root->insertNonFull(k);
	}
	else {
		root->insertNonFull(k);
	}
}

void BTreeNode::insertNonFull(int k)
{
	if (isLeaf) {
		int i = n;
<<<<<<< HEAD
		while (i > 0 && keys[i - 1] > k) {
			keys[i] = keys[i - 1];
=======
		while(i > 0 && keys[i-1] > k) {
			keys[i] = keys[i-1];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			i--;
		}
		keys[i] = k;
		n++;
	}
	else {
		int start = 0;
<<<<<<< HEAD
		int end = n - 1;
		while (start < end) {
			int mid = (start + end) >> 1;
			if (keys[mid] < k)
=======
		int end = n-1;
		while (start < end) {
			int mid = (start + end) >> 1;
			if(keys[mid] < k)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
				start = mid + 1;
			else
				end = mid;
		}
<<<<<<< HEAD
		if (end == n - 1 && keys[end] < k) {
=======
		if (end == n-1 && keys[end] < k){
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			end++;
		}
		if (C[end]->isFull()) {
			splitChild(end, C[end]);
			if (keys[end] < k)
				end++;
		}
		C[end]->insertNonFull(k);
	}
}

bool BTreeNode::isFull()
{
<<<<<<< HEAD
	return (n == (2 * t - 1));
=======
	return (n == (2*t-1));
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
}

void BTreeNode::splitChild(int index, BTreeNode* y)
{
	BTreeNode *z = new BTreeNode(t, y->isLeaf);
<<<<<<< HEAD
	y->n = t - 1;
	z->n = t - 1;
	if (!y->isLeaf) {
		for (int i = 0; i < t; ++i) {
			z->C[i] = y->C[i + t];
=======
	y->n = t-1;
	z->n = t-1;
	if (!y->isLeaf) {
		for (int i = 0; i < t; ++i) {
			z->C[i] = y->C[i+t];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		}
	}
	n++;
	for (int i = 0; i < z->n; ++i) {
<<<<<<< HEAD
		z->keys[i] = y->keys[i + t];
	}
	int curr = n;
	while (curr != (index)) {
		keys[curr] = keys[curr - 1];
		C[curr] = C[curr - 1];
		curr--;
	}
	keys[curr] = y->keys[y->n];
	C[curr + 1] = z;
=======
		z->keys[i] = y->keys[i+t];
	}
	int curr = n;
	while (curr != (index)) {
		keys[curr] = keys[curr-1];
		C[curr] = C[curr-1];
		curr--;
	}
	keys[curr] = y->keys[y->n];
	C[curr+1] = z;
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
}

void BTreeNode::merge(int idx)
{
	BTreeNode *y = C[idx];
	BTreeNode *z = C[idx + 1];
	int k = keys[idx];
<<<<<<< HEAD
	for (int i = idx + 1; i < n; ++i) {
		C[i] = C[i + 1];
		keys[i - 1] = keys[i];
=======
	for (int i = idx+1; i < n; ++i) {
		C[i] = C[i+1];
		keys[i-1] = keys[i];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	}
	n--;
	int currn = y->n;
	y->n += (z->n + 1);
	y->keys[currn] = k;
<<<<<<< HEAD
	for (int i = currn + 1; i < y->n; ++i) {
		y->keys[i] = z->keys[i - currn - 1];
	}
	if (!y->isLeaf) {
		for (int i = currn + 1; i <= y->n ; ++i) {
			y->C[i] = z->C[i - currn - 1];
=======
	for (int i = currn+1; i < y->n; ++i) {
		y->keys[i] = z->keys[i-currn-1];
	}
	if(!y->isLeaf) {
		for (int i = currn+1; i <= y->n ; ++i) {
			y->C[i] = z->C[i-currn-1];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		}
	}
	delete(z);
}

int BTreeNode::getId(int k)
{
	int start = 0;
<<<<<<< HEAD
	int end = n - 1;
	while (start < end) {
		int mid = (start + end) >> 1;
		if (keys[mid] < k)
=======
	int end = n-1;
	while (start < end) {
		int mid = (start + end) >> 1;
		if(keys[mid] < k)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}

int BTreeNode::getPred(int idx)
{
	BTreeNode *curr = C[idx];
<<<<<<< HEAD
	while (!curr->isLeaf) {
		curr = curr->C[curr->n];
	}
	return curr->keys[curr->n - 1];
=======
	while(!curr->isLeaf) {
		curr = curr->C[curr->n];
	}
	return curr->keys[curr->n-1];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
}

int BTreeNode::getSucc(int idx)
{
<<<<<<< HEAD
	BTreeNode *curr = C[idx + 1];
	while (!curr->isLeaf) {
=======
	BTreeNode *curr = C[idx+1];
	while(!curr->isLeaf) {
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		curr = curr->C[0];
	}
	return curr->keys[0];
}

void BTreeNode::removeFromLeaf(int idx)
{
	for (int i = idx; i < n; ++i) {
<<<<<<< HEAD
		keys[i] = keys[i + 1];
=======
		keys[i] = keys[i+1];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	}
	n--;
}

void BTreeNode::removeFromNonLeaf(int idx)
{
<<<<<<< HEAD
	if (C[idx]->n >= t) {
		keys[idx] = getPred(idx);
		C[idx]->remove(keys[idx]);
	}
	else if (C[idx + 1]->n >= t) {
		keys[idx] = getSucc(idx);
		C[idx + 1]->remove(keys[idx]);
=======
	if(C[idx]->n >= t) {
		keys[idx] = getPred(idx);
		C[idx]->remove(keys[idx]);
	}
	else if(C[idx+1]->n >= t) {
		keys[idx] = getSucc(idx);
		C[idx+1]->remove(keys[idx]);
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
	}
	else {
		int k = keys[idx];
		merge(idx);
		C[idx]->remove(k);
	}
}

void BTreeNode::borrowFromPred(int idx)
{
	BTreeNode *child = C[idx];
<<<<<<< HEAD
	BTreeNode *sibling = C[idx - 1];
	for (int i = child->n - 1; i >= 0; --i) {
		child->keys[i + 1] = child->keys[i];
	}
	child->keys[0] = keys[idx - 1];
	keys[idx - 1] = sibling->keys[sibling->n - 1];
	if (!child->isLeaf) {
		for (int i = child->n; i >= 0; --i) {
			child->C[i + 1] = child->C[i];
=======
	BTreeNode *sibling = C[idx-1];
	for (int i = child->n-1; i >= 0; --i) {
		child->keys[i+1] = child->keys[i];
	}
	child->keys[0] = keys[idx-1];
	keys[idx-1] = sibling->keys[sibling->n-1];
	if(!child->isLeaf) {
		for (int i = child->n; i >= 0; --i) {
			child->C[i+1] = child->C[i];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		}
		child->C[0] = sibling->C[sibling->n];
	}
	child->n += 1;
	sibling->n -= 1;
}

void BTreeNode::borrowFromSucc(int idx)
{
	BTreeNode *child = C[idx];
<<<<<<< HEAD
	BTreeNode *sibling = C[idx + 1];
	child->keys[child->n] = keys[idx];
	keys[idx] = sibling->keys[0];
	for (int i = 1; i < sibling->n; ++i) {
		sibling->keys[i - 1] = sibling->keys[i];
	}
	if (!child->isLeaf) {
		child->C[child->n + 1] = sibling->C[0];
		for (int i = 1; i <= sibling->n; ++i) {
			sibling->C[i - 1] = sibling->C[i];
=======
	BTreeNode *sibling = C[idx+1];
	child->keys[child->n] = keys[idx];
	keys[idx] = sibling->keys[0];
	for (int i = 1; i < sibling->n; ++i) {
		sibling->keys[i-1] = sibling->keys[i];
	}
	if(!child->isLeaf) {
		child->C[child->n+1] = sibling->C[0];
		for (int i = 1; i <= sibling->n; ++i) {
			sibling->C[i-1] = sibling->C[i];
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
		}
	}
	child->n += 1;
	sibling->n -= 1;
}

void BTreeNode::remove(int k)
{
	int idx = getId(k);
<<<<<<< HEAD
	if (keys[idx] == k) {
		if (isLeaf)
=======
	if(keys[idx] == k) {
		if(isLeaf)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			removeFromLeaf(idx);
		else
			removeFromNonLeaf(idx);
	}
<<<<<<< HEAD
	else if (isLeaf) {
		std::cerr << "Sorry the key doesnot exist";
	}
	else {
		if (idx == n - 1 && keys[idx] < k) {
			idx++;
			if (C[idx]->n <= t - 1) {
				if (C[idx - 1]->n >= t) {
					borrowFromPred(idx);
				}
				else {
					merge(idx - 1);
=======
	else if(isLeaf) {
		std::cerr << "Sorry the key doesnot exist";
	}
	else {
		if(idx == n-1 && keys[idx] < k) {
			idx++;
			if(C[idx]->n <= t-1) {
				if(C[idx-1]->n >= t) {
					borrowFromPred(idx);
				}
				else {
					merge(idx-1);
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
					idx--;
				}
			}
		}
<<<<<<< HEAD
		else if (idx == 0 && C[idx]->n <= t - 1) {
			if (C[idx + 1]->n >= t) {
=======
		else if(idx == 0 && C[idx]->n <= t-1) {
			if(C[idx+1]->n >= t) {
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
				borrowFromSucc(idx);
			}
			else {
				merge(idx);
			}
		}
<<<<<<< HEAD
		else if (idx > 0) {
			if (C[idx]->n <= t - 1) {
				if (C[idx - 1]->n >= t) {
					borrowFromPred(idx);
				}
				else if (C[idx + 1]->n >= t - 1) {
=======
		else if(idx > 0) {
			if(C[idx]->n <= t-1) {
				if(C[idx-1]->n >= t) {
					borrowFromPred(idx);
				}
				else if(C[idx+1]->n >= t-1) {
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
					borrowFromSucc(idx);
				}
				else {
					merge(idx);
				}
			}
		}
		C[idx]->remove(k);
	}
}

void BTree::remove(int k)
{
<<<<<<< HEAD
	if (root == NULL)
		std::cerr << "Sorry the tree is empty";
	else {
		root->remove(k);
		if (root->n == 0) {
			BTreeNode *temproot = root;
			if (root->isLeaf)
=======
	if(root == NULL)
		std::cerr << "Sorry the tree is empty";
	else {
		root->remove(k);
		if(root->n == 0) {
			BTreeNode *temproot = root;
			if(root->isLeaf)
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
				root = NULL;
			else
				root = root->C[0];
			delete(temproot);
		}
	}
}
//DIRECTED GRAPH
class DGraph
{
	int n;
	std::vector<std::vector<int> > adj;
	std::vector<std::vector<int> > radj;
	std::vector<bool> visited;
public:
	DGraph();
	DGraph(int n);
	void add(int u, int v);
	void dfs(int u);
	void dfsutil(int u);
};
DGraph::DGraph() { this->n = 0; }
DGraph::DGraph(int n) { this->n = n; this->adj.resize(n); this->radj.resize(n); }
void DGraph::add(int u, int v) { this->adj[u].pb(v); this->radj[v].pb(u); this->visited.resize(n);}
void DGraph::dfs(int u)
{
	std::fill(visited.begin(), visited.end(), false);
	this->dfsutil(u);
}
void DGraph::dfsutil(int u)
{
	visited[u] = true;
<<<<<<< HEAD
	for (int v : adj[u])
		if (!visited[v])
=======
	for (int v: adj[u])
		if(!visited[v])
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			dfs(v);
}
//UNDIRECTED GRAPH - Adjacency List
class Graph
{
	int n;
	std::vector<std::vector<int> > adj;
	std::vector<bool> visited;
public:
	DGraph();
	DGraph(int n);
	void add(int u, int v);
	void dfs(int u);
	void dfsutil(int u);
};
DGraph::DGraph() { this->n = 0; }
DGraph::DGraph(int n) { this->n = n; this->adj.resize(n); }
void DGraph::add(int u, int v) { this->adj[u].pb(v); this->adj[v].pb(u); this->visited.resize(n);}
void DGraph::dfs(int u)
{
	std::fill(visited.begin(), visited.end(), false);
	this->dfsutil(u);
}
void DGraph::dfsutil(int u)
{
	visited[u] = true;
	std::cout << u << " ";
<<<<<<< HEAD
	for (int v : adj[u])
		if (!visited[v])
=======
	for (int v: adj[u])
		if(!visited[v])
>>>>>>> 53449f3a16104acd718ba1301d99eb884e2f932f
			dfs(v);
}
#endif