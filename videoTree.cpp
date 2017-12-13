#ifndef VIDEOTREE_CPP
#define VIDEOTREE_CPP

#include <iostream>
#include <string>
#include "videoTree.h"

using namespace std;

namespace videoT{

	void videoTree::searchVideoList(string title, bool& found, binaryTreeNode<videoType>* & current){

		found = false;

		videoType temp;

		temp.setVideoInfo(title, "", "", "", "", "", 0);

		if(root == NULL)
			cout << "Cannot search an empty list. " << endl;
		else{

			current = root;

			found = false;

			while(!found && current != NULL)
				if(current->info == temp)
					found = true;
				else if(current->info > temp)
					current = current->lLink;
				else
					current = current->rLink;
		}
	}

	void videoTree::inOrderTitle(binaryTreeNode<videoType> *p){

		if(p != NULL){

			inOrderTitle(p->lLink);
			p->info.printTitle();
			inOrderTitle(p->rLink);
		}
	}

	void videoTree::videoPrintTitle(){

		inOrderTitle(root);
	}

	bool videoTree::videoSearch(string title){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);
		
		return found;
	}

	bool videoTree::isVideoAvailable(string title){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);

		if(found)
			if(temp->info.getNoOfCopiesInStock() > 0)
				return true;
			else
				return false;
		else
			return false;	
	}

	void videoTree::videoCheckOut(string title){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);

		if(found)
			temp->info.checkOut();
	}

	void videoTree::videoCheckIn(string title){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);
		temp->info.checkIn();	
	}

	bool videoTree::videoCheckTitle(string title){

		return videoSearch(title);
	}

	void videoTree::videoUpdateInStock(string title, int num){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);
		temp->info.updateInStock(num);
	}

	void videoTree::videoSetCopiesInStock(string title, int num){

		bool found;

		binaryTreeNode<videoType> *temp;

		searchVideoList(title, found, temp);
		temp->info.setCopiesInStock(num);
	}
}
#endif //BINARYTREE_CPP