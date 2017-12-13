#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

using namespace std;

namespace binaryTree{

	template<class elemType>
	struct binaryTreeNode{

		elemType info;
		binaryTreeNode<elemType> *lLink;
		binaryTreeNode<elemType> *rLink;
	};

	template <class elemType>
	class bSearchTree{

		public:

			bool search(const elemType& searchItem) const;

			void insert(const elemType& insertItem);

			void deleteNode(const elemType& deleteItem);

			const bSearchTree<elemType>& operator=(const bSearchTree<elemType>&);

			bool isEmpty() const;

			void inOrderTraversal() const;

			void preOrderTraversal() const;

			void postOrderTraversal() const;

			int treeHeight() const;

			int treeNodeCount() const;

			int treeLeavesCount() const;

			void destroyTree();

			bSearchTree(const bSearchTree<elemType>& otherTree);

			bSearchTree();

			~bSearchTree();

		protected:

			binaryTreeNode<elemType> *root;

		private:

			void copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot);

			void destroy(binaryTreeNode<elemType>* &p);

			void inOrder(binaryTreeNode<elemType> *p) const;

			void preOrder(binaryTreeNode<elemType> *p) const;

			void postOrder(binaryTreeNode<elemType> *p) const;

			int height(binaryTreeNode<elemType> *p) const;

			int max(int x, int y) const;

			int nodeCount(binaryTreeNode<elemType> *p) const;

			int leavesCount(binaryTreeNode<elemType> *p) const;

			void deleteFromTree(binaryTreeNode<elemType>* &p);

			int totalNodes;
	};
} //queue

#endif //BINARYTREE_H
#include "binaryTree.cpp"