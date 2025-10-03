#include "rb.h"
using ptr = RedBlackTree::ptr;

RedBlackTree::RedBlackTree(){}

const ptr RedBlackTree::getRoot() const
{
return root;
}

ptr RedBlackTree::insert(int data)
{
	ptr newnodePtr = new node(data);
	if (!root) {
		root = newnodePtr;
		root->color = 0; // set root color as black
		return newnodePtr;
	}
	insert(root, newnodePtr);
	return newnodePtr;
}

// auxiliary function to perform RBT insertion of a node
// you may assume start is not nullptr
void RedBlackTree::insert(ptr start, ptr newnodePtr)
{
// choose direction
	if(start->data >= newnodePtr->data){
		if(start->left == nullptr){
			start->left = newnodePtr;
			newnodePtr->parent = start;
			if(start->color==1) fixup(newnodePtr);
		}
		else{
			insert(start->left,newnodePtr);
		}
	}
	else{
		if(start->right == nullptr){
			start->right = newnodePtr;
			newnodePtr->parent = start;
			if(start->color==1) fixup(newnodePtr);
		}
		else{
		insert(start->right,newnodePtr);
		}
	}
	return;
}

// Credits to Adrian Schneider
void RedBlackTree::printRBT(ptr start, const std::string& prefix, bool isLeftChild) const
{
if (!start) return;

std::cout << prefix;
std::cout << (isLeftChild ? "|--" : "|__" );
// print the value of the node
std::cout << start->data << "(" << start->color << ")" << std::endl;
// enter the next tree level - left and right branch
printRBT(start->left, prefix + (isLeftChild ? "│ " : " "), true);
printRBT(start->right, prefix + (isLeftChild ? "│ " : " "), false);
}

// Function performing right rotation
// of the passed node, !!!rotation is always done through its parent
void RedBlackTree::rightrotate(ptr loc)
{
	auto par = loc->parent;
	auto gpar = par->parent;
	bool par_r = (par==gpar->right);
	loc->parent = gpar;
	par->parent = loc;
	par->left = loc->right;
	if (loc->right) loc->right->parent = par;
	loc->right = par;
	if(gpar!=nullptr){
		if(par_r) gpar->right = loc;
		else gpar->left = loc;
	}
	else{
		root = loc;
	}
}

// Function performing left rotation
// of the passed node
void RedBlackTree::leftrotate(ptr loc)
{
	auto par = loc->parent;
	auto gpar = par->parent;
	bool par_r = (par == gpar->right);
	loc->parent = gpar;
	par->parent = loc;
	par->right = loc->left;
	if (loc->left) loc->left->parent = par;
	loc->left = par;
	if(gpar!=nullptr){
		if(par_r) gpar->right = loc;
		else gpar->left = loc;
	}
	else{
		root=loc;
	}
}

// This function fixes violations
// caused by RBT insertion
void RedBlackTree::fixup(ptr loc)
{
	auto par = loc->parent;
	auto gpar = par->parent;
	auto u = (par==gpar->right) ? (gpar->left) : (gpar->right);
	// case:1
	if(u){
		if(u->color==1){
			u->color = 0; par->color = 0;
			if(gpar!=root){
				gpar->color = 1;
				if((gpar->parent)->color==1) {
					fixup(gpar);
					return;
				}
				else return;
			}
			else{
				return;
			}
		}
		else{
			// case:2
			if(gpar->right==par){
				if(loc==par->left) {rightrotate(loc); fixup(par); return;}
				else{
					leftrotate(par); par->color = 0; gpar->color = 1; return;
				}
			}
			else{
				if(loc==par->right) {leftrotate(loc); fixup(par); return;}
				else{
					rightrotate(par); par->color = 0; gpar->color = 1; return;
				}
			}
		}
	}
	else{
			// case:2
			if(gpar->right==par){
				if(loc==par->left) {rightrotate(loc); fixup(par); return;}
				else{
					leftrotate(par); par->color = 0; gpar->color = 1; return;
				}
			}
			else{
				if(loc==par->right) {leftrotate(loc); fixup(par); return;}
				else{
					rightrotate(par); par->color = 0; gpar->color = 1; return;
				}
			}
	}

}

// Function to print inorder traversal
// of the fixated tree
void RedBlackTree::inorder(ptr start) const
{
if (!start)
return;
 
inorder(start->left);
std::cout << start->data << " ";
inorder(start->right);
}