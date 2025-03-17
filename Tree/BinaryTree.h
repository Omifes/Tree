#ifndef BINATY_TREE
#define BINATY_TREE

template<class T>
class BinmatyTree
{
private:
	struct Node {
		T key_;
		Node* left_;
		Node* right_;
		Node* p_;
		Node(const T& key) : key_(key), left_(nullptr), right_(nullptr), p_(nullptr) {}
	};

	Node* root_
};




#endif

