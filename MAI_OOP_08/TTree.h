#ifndef TBINTREE_H
#define TBINTREE_H
#include <memory>
#include <iostream>
class TNode {
public:
	TNode();
	TNode(void * link);
	~TNode();
	void * link;
	TNode* left;
	TNode* right;
};
class TTree {
public:
	TTree();
	TTree(const TTree& orig);

	void Insert(TNode*& node, void * link);
	void Pop();
	TNode* Root();
	bool Empty() const;
	TNode* Minimum() const;	
	void DistructTree(TNode* node);
	int size;
	TNode* root;
	virtual ~TTree();
private:



};

#endif /* TBINTREE_H */