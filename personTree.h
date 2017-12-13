#ifndef PERSONTREE_H
#define PERSONTREE_H

#include <iostream>
#include "binaryTree.h"
#include "personType.h"


using namespace std;
using namespace person;
using namespace binaryTree;

namespace personT{

	class personTree: public bSearchTree<personType>{

		public:

			bool personSearch(string name);

			void personSetMovie(string name, string title);

			void personRemoveMovie(string name, string title);

			void personPrintNames();

		private:

			void searchPersonList(string name, bool& found, binaryTreeNode<personType>* &current);

			void inOrderPerson(binaryTreeNode<personType> *p);
	};
} //queue

#endif //PERSONTREE_H
#include "personTree.cpp"