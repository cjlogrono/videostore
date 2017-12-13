#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include <string>
#include <assert.h>
#include "binaryTree.h"

using namespace std;

namespace binaryTree{

	template <class elemType>
	bool bSearchTree<elemType>::isEmpty() const{

		return (root == NULL);
	}

	template <class elemType>
	bSearchTree<elemType>::bSearchTree(){

		root = NULL;
		totalNodes = 0;
	}

	template <class elemType>
	void bSearchTree<elemType>::inOrderTraversal() const{

		inOrder(root);
	}

	template <class elemType>
	void bSearchTree<elemType>::preOrderTraversal() const{

		preOrder(root);
	}

	template <class elemType>
	void bSearchTree<elemType>::postOrderTraversal() const{

		postOrder(root);
	}

	template <class elemType>
	int bSearchTree<elemType>::treeHeight() const{

		return height(root);
	}

	template <class elemType>
	int bSearchTree<elemType>::treeNodeCount() const{

		return nodeCount(root);
	}

	template <class elemType>
	int bSearchTree<elemType>::treeLeavesCount() const{

		return leavesCount(root);
	}

	template <class elemType>
	void bSearchTree<elemType>::inOrder(binaryTreeNode<elemType> *p) const{

		if(p != NULL){

			inOrder(p->lLink);
			p->info.printInfo();
			cout << endl;
			inOrder(p->rLink);
		}
	}

	template <class elemType>
	void bSearchTree<elemType>::preOrder(binaryTreeNode<elemType> *p) const{

		if(p != NULL){

			p->info.printInfo();
			cout << endl;
			preOrder(p->lLlink);
			preOrder(p->rLink);
		}
	}

	template <class elemType>
	void bSearchTree<elemType>::postOrder(binaryTreeNode<elemType> *p) const{

		if(p != NULL){

			postOrder(p->lLlink);
			postOrder(p->rLink);
			p->info.printInfo();
			cout << endl;
		}
	}

	template <class elemType>
	int bSearchTree<elemType>::height(binaryTreeNode<elemType> *p) const{

		if(p != NULL)
			return 0;
		else
			return 1 + max(height(p->lLink), height(p->rLink));
	}

	template <class elemType>
	int bSearchTree<elemType>::max(int x, int y) const{

		if(x >= y)
			return x;
		else
			return y;
	}

	template <class elemType>
	int bSearchTree<elemType>::nodeCount(binaryTreeNode<elemType> *p) const{ 

		return totalNodes;
	}

	template <class elemType>
	int bSearchTree<elemType>::leavesCount(binaryTreeNode<elemType> *p) const{ 

		if(p == NULL)
			return 0;
		else if(p->rLink == NULL && p->lLink == NULL)
			return 1;
		else
			return leavesCount(p->rLink) + leavesCount(p->lLink);
	}

	template <class elemType>
	void bSearchTree<elemType>::copyTree(binaryTreeNode<elemType>* &copiedTreeRoot, binaryTreeNode<elemType>* otherTreeRoot){

			if(otherTreeRoot == NULL)
				copiedTreeRoot = NULL;
			else{

				copiedTreeRoot = new binaryTreeNode<elemType>;
				copiedTreeRoot->info = otherTreeRoot->info;
				copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
				copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
			}

			otherTreeRoot.nodeCount = copiedTreeRoot.nodeCount;
	}

	template <class elemType>
	void bSearchTree<elemType>::destroy(binaryTreeNode<elemType>* &p){

		if(p != NULL){

			destroy(p->lLink);
			destroy(p->rLink);
			delete p;
			p = NULL;
		}
	}

	template <class elemType>
	void bSearchTree<elemType>::destroyTree(){

		destroy(root);
	}

	template <class elemType>
	bSearchTree<elemType>::bSearchTree(const bSearchTree<elemType>& otherTree){

		if(otherTree.root == NULL){
			nodeCount = 0;
			root = NULL;
		}else
			copyTree(root, otherTree.root);
	}

	template <class elemType>
	bSearchTree<elemType>::~bSearchTree(){

		destroy(root);
	}

	template <class elemType>
	const bSearchTree<elemType>& bSearchTree<elemType>::operator=(const bSearchTree<elemType>& otherTree){

		if(this != &otherTree){

			if(root != NULL)
				destroy(root);
			if(otherTree.root == NULL)
				root = NULL;
			else
				copyTree(root, otherTree.root);
		}

		return *this;
	}

	template <class elemType>
	bool bSearchTree<elemType>::search(const elemType& searchItem) const{

		binaryTreeNode<elemType> * current;
		bool found = false;

		if(root == NULL)
			cout << "Cannot search the empty tree." << endl;
		else{

			current = root;

			while(current != NULL && !found){

				if(current->info == searchItem)
					found = true;
				else if(current->info > searchItem)
					current = current->lLink;
				else
					current = current->rLink;
			}
		}

		return found;
	}

	template <class elemType>
	void bSearchTree<elemType>::insert(const elemType& insertItem){

		binaryTreeNode<elemType> *current;
		binaryTreeNode<elemType> *trailCurrent;
		binaryTreeNode<elemType> *newNode;

		newNode = new binaryTreeNode<elemType>;
		assert(newNode != NULL);
		newNode->info = insertItem;
		newNode->lLink = NULL;
		newNode->rLink = NULL;

		if(root == NULL)
			root = newNode;
		else{

			current = root;

			while(current != NULL){

				trailCurrent = current;

				if(current->info == insertItem){

					cout << "The insert item is already in the list-";
					cout << "duplicates are not allowed." << insertItem << endl;
					return;
				}else if(current->info > insertItem)
					current = current->lLink;
				else
					current = current->rLink;
			}

			if(trailCurrent->info > insertItem)
				trailCurrent->lLink = newNode;
			else
				trailCurrent->rLink = newNode;
		}

		if(trailCurrent->info != insertItem){

				totalNodes++;
		}
	}

	template <class elemType>
	void bSearchTree<elemType>::deleteFromTree(binaryTreeNode<elemType>* &p){

		binaryTreeNode<elemType> *current;
		binaryTreeNode<elemType>  *trailCurrent;
		binaryTreeNode<elemType> *temp;

		if(p == NULL)
			cout << "Error: The node to be deleted is NULL." << endl;
		else if(p->lLink == NULL && p->rLink == NULL){

			temp = p;
			p = NULL;
			delete temp;
		}else if(p->lLink == NULL){

			temp = p;
			p = temp->rLink;
			delete temp;
		}else if(p->rLink == NULL){

			temp = p;
			p = temp->lLink;
			delete temp;
		}else{

			current = p->lLink;
			trailCurrent = NULL;

			while(current->rLink != NULL){

				trailCurrent = current;
				current = current->rLink;
			}

			p->info = current->info;

			if(trailCurrent == NULL)
				p->lLink = current->lLink;
			else
				trailCurrent->rLink = current->lLink;

			delete current;
		}

		if(p != NULL){

			totalNodes--;
		}
	}

	template <class elemType>
	void bSearchTree<elemType>::deleteNode(const elemType& deleteItem){

		binaryTreeNode<elemType> *current;
		binaryTreeNode<elemType>  *trailCurrent;
		bool found =false;

		if(root == NULL)
			cout << "Cannot delete from empty tree." << endl;
		else{

			current = root;
			trailCurrent = root;

			while(current != NULL && !found){

				if(current->info == deleteItem)
					found = true;
				else{

					trailCurrent = current;

					if(current->info > deleteItem)
						current = current->lLink;
					else
						current = current->rLink;
				}
			}

			if(current == NULL)
				cout << "The delete item is not in the tree." << endl;
			else if(found){

				if(current == root)
					deleteFromTree(root);
				else if(trailCurrent->info > deleteItem)
					deleteFromTree(trailCurrent->lLink);
				else
					deleteFromTree(trailCurrent->rLink);
			}
		}
	}
}
#endif //BINARYTREE_CPP