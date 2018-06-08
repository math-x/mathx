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
	if(x < n) {
		if(parent[x] == x)
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
	if(x < n && y < n) {
		x = root(x);
		y = root(y);
		if(x != y) {
			if(size[x] < size[y])
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
	if(root(x) == root(y))
		return true;
	return false;
}
DSU::~DSU()
{
	delete parent;
	delete size;
}
#endif