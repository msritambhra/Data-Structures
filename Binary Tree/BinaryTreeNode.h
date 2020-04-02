template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode<int> * left;
	BinaryTreeNode<int> * right;

	BinaryTreeNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	~BinaryTreeNode() {
        	delete left;
		delete right;
    	}

};
