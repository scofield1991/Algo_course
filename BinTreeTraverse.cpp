#include <iostream>

using namespace std;

class VarBinNode
{
public:
	virtual ~VarBinNode() {}
	virtual bool isLeaf() = 0;
};



class LeafNode: public VarBinNode
{
private:
	int var;

public:
	LeafNode(const int &val): var(val) {}
	bool isLeaf() { return true; }
	int value() { return var; }
};

// 1: *, 2: /, 3: +, 4: -
class IntlNode: public VarBinNode
{
private:
	VarBinNode *left;
	VarBinNode *right;
	int opx;

public:
	IntlNode(const int &op, VarBinNode *l, VarBinNode *r) :
	 opx(op), left(l), right(r) {};	 
	 bool isLeaf() { return false;}
	 VarBinNode* leftChild() { return left; }
	 VarBinNode* rightChild() { return right; }
	 int  value() { return opx; }
};

void traverse(VarBinNode* root)
{
	if(root == NULL) return;
	if(root->isLeaf())
		cout << "Leaf: " << ((LeafNode *)root)->value() << endl;
	else
	{
		cout << "Internal: "
			 << ((IntlNode*)root)->value() << endl;
		traverse(((IntlNode*)root)->leftChild());
		traverse(((IntlNode*)root)->rightChild());
	}
}

int main()
{
	LeafNode *leftChild, *rightChild;
	leftChild = new LeafNode(1);
	rightChild = new LeafNode(3);
	IntlNode root(3, leftChild, rightChild);
	traverse(&root);
}
