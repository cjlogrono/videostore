#ifndef VIDEOTREE_H
#define VIDEOTREE_H


#include <iostream>
#include "binaryTree.h"
#include "videoType.h"


using namespace std;
using namespace video;
using namespace binaryTree;

namespace videoT{

	class videoTree: public bSearchTree<videoType>{

		public:

			bool videoSearch(string title);

			bool isVideoAvailable(string title);

			void videoCheckOut(string title);

			void videoCheckIn(string title);

			bool videoCheckTitle(string title);

			void videoUpdateInStock(string title, int num);

			void videoSetCopiesInStock(string title, int num);

			void videoPrintTitle();

		private:

			void searchVideoList(string title, bool& found, binaryTreeNode<videoType>* &current);

			void inOrderTitle(binaryTreeNode<videoType> *p);
	};
} //queue

#endif //VIDEOTREE_H
#include "videoTree.cpp"