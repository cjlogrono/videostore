#ifndef PERSONTREE_CPP
#define PERSONTREE_CPP

#include <iostream>
#include <string>
#include "personTree.h"

using namespace std;

namespace personT{

	void personTree::searchPersonList(string name, bool& found, binaryTreeNode<personType>* & current){

		found = false;

		personType temp;

		temp.setPersonInfo(name, "", "", "", "");

		if(root == NULL)
			cout << endl;
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

	void personTree::inOrderPerson(binaryTreeNode<personType> *p){

		if(p != NULL){

			inOrderPerson(p->lLink);
			p->info.getName();
			inOrderPerson(p->rLink);
		}
	}

	void personTree::personPrintNames(){

		inOrderPerson(root);
	}

	bool personTree::personSearch(string name){

		bool found;

		binaryTreeNode<personType> *temp;

		searchPersonList(name, found, temp);
		
		return found;
	}

	void personTree::personSetMovie(string name, string title){

		bool found;

		binaryTreeNode<personType> *temp;

		searchPersonList(name, found, temp);

		if(found)
			temp->info.setMovie(title);
	}

	void personTree::personRemoveMovie(string name, string title){

		bool found;

		binaryTreeNode<personType> *temp;

		searchPersonList(name, found, temp);
		temp->info.removeMovie(title);	
	}
}
#endif //PERSONTREE_CPP