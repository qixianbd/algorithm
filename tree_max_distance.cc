/*
 * tree_max_distance.cc
 *
 *  Created on: 2014年9月23日
 *      Author: qmwx
 */

#include "tree.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>



using namespace std;

struct Node;

static int height(Node *root)
{
	if(NULL == root){
		return 0;
	}
	int leftHeight = height(root->left)+1;
	int rightHeight = height(root->right)+1;
	return max(leftHeight, rightHeight);
}

static int maxDis(Node *root)
{
	if(NULL == root){
		return 0;
	}
	int leftHight = height(root->left)-1;
	int rightHight = height(root->right)-1;
	int throughRootDis = leftHight + rightHight;

	int leftDis = maxDis(root->left);
	int rightDis = maxDis(root->right);

	int ret = max(throughRootDis, leftDis, rightDis);
	return ret;
}

static int helper(Node *root, int& depth)
{
	if(NULL == root){
		depth = 0;
		return 0;
	}

	int ld, rd;
	int maxLeft = helper(root->left, ld);
	int maxRight = helper(root->right, rd);

	depth = std::max(ld, rd) + 1;
	return std::max(maxLeft, std::max(maxRight, ld + rd));
}

static Node* insertNode(Node * root, int value)
{
	if(NULL == root){
		root = new Node();
		root->value = value;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	Node *p = root;
	Node **q = &p;
	while(p){
		if(value <= p->value){
			q = &(p->left);
			p = p->left;
		}
		else{
			q = &(p->right);
			p = p->right;
		}
	}
	(*q) = new Node();
	(*q)->value = value;
	(*q)->left = NULL;
	(*q)->right  = NULL;

	return root;
}

static Node* constructTree(vector<int>& array)
{
	Node * root = NULL;
	for(unsigned int i = 0; i < array.size(); i++){
		root = insertNode(root, array[i]);
	}
	return root;
}

int maxDistance(Node *root)
{
	int depth;
	return helper(root, depth);
}

void traversePrint(const Node *root)
{
	if(NULL == root){
		return ;
	}
	cout << root->value << " ";
	traversePrint(root->left);
	traversePrint(root->right);
}

int main()
{
	int a[] = {8, 6, 10, 5, 7, 9, 11};
	int len = sizeof(a)/sizeof(a[0]);
	vector<int> array(a, a+len );
	Node *root = constructTree(array);
	traversePrint(root);
	cout << endl;
	int dis = maxDis(root);
	cout << dis << endl;
	int h= height(root);
	cout << h << endl;
	return 0;
}



