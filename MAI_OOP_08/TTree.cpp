#include "TTree.h"


TNode::TNode():link(nullptr),left(nullptr),right(nullptr) {
}

TNode::TNode(void * link):link(link),left(nullptr),right(nullptr) {
}


TTree::TTree() : root(nullptr),size(0) {
	//std::cout << "BinTree: Created" << std::endl;
}

TTree::TTree(const TTree& orig) {
	root = orig.root;
	size = orig.size;
}

void TTree::Insert(TNode*& node,void * link) {
	if (node==nullptr) {
		node = new TNode(link);
		size++;
	}
	else {
		if (link < node->link){ 
			Insert(node->left, link);
		}
		else if (link > node->link) //
			Insert(node->right, link);
		if (link == node->link)
		{
			printf("Such adress has already existed.");
		}
	}
}

void TTree::Pop() {
	TNode* temp = root;
	if (temp==nullptr) {
		std::cout << "Tree is empty" << std::endl;
		return;
	}
	if (temp->left == nullptr) {
		size--;
		root = temp->right;
		return;
	}
	while (temp->left->left != nullptr) {
		temp = temp->left;
	}
	temp->left = nullptr;
	size--;
}


TNode* TTree::Root() {
	return root;
}

bool TTree::Empty() const {
	return !size;
}

void TTree::DistructTree(TNode *node) {
	if (node->right != nullptr) {
		DistructTree(node->right);
	}
	if (node->left != nullptr) {
		DistructTree(node->left);
	}
	delete node;
}
TNode::~TNode() {
	left = nullptr;
	right = nullptr;
	link = nullptr;
}
TTree::~TTree() {
	//delete root;
	if(root!=nullptr)
	DistructTree(root);
	std::cout << "BinTree: Deleted" << std::endl;
}

TNode* TTree::Minimum() const {
	TNode* temp = root;
	while(temp->left!=nullptr) {
		temp = temp->left;
	}
	return temp;
}

//#include "Figure.h"
//template class TTree<Figure>;
////template std::ostream& operator<<(std::ostream& os, const TTree<Figure>& figure);