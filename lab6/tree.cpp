#include "tree.h"

Node::Node(string word, int index) {
	this->word = word;
	this->indexes.push_back(index);
	this->left = NULL;
	this->right = NULL;
}
Node::~Node() {
	delete left;
	delete right;
}
Tree::Tree() {
	root = NULL;
}
Tree::~Tree() {
	delete root;
}
void Tree::add_node_rec(Node*& parent, string word, int index) {
	if (!parent) {
		parent = new Node(word, index);
		return;
	}
	else {
		if (parent->word < word)
			add_node_rec(parent->right, word, index);
		else if (parent->word > word)
			add_node_rec(parent->left, word, index);
		else if (!strcmp(parent->word.c_str(), word.c_str())) 
			if (find(parent->indexes.begin(), parent->indexes.end(), index) == parent->indexes.end())
				parent->indexes.push_back(index);
	}
}
void Tree::add_node(string word, int index) {
	add_node_rec(root, word, index);
}
void Tree::print_rec(Node*& parent, int tabs) {
	char space = ' ';
	char under = '_';
	for (int i = 0; i < tabs; i++)
		cout << string(3, space) << "|";
	cout << string(2, under);
	if (parent != NULL)
	{
		cout << parent->word << " [ ";
		for (int i = 0; i < parent->indexes.size(); i++) {
			if (i == (parent->indexes.size() - 1))
				cout << parent->indexes[i] << " ]";
			else
				cout << parent->indexes[i] << ", ";
		}cout << endl;
		if(parent->right)
			print_rec(parent->right, tabs + 1);
		if (parent->left)
			print_rec(parent->left, tabs + 1);
	}
	else
		cout << "\n";

}
void Tree::print() {
	this->print_rec(root, 0);
}
void Tree::find_lines_rec(Node*& parent, vector <int>& index, int &position) { 
	if (parent && (position) == 0) {
		for (size_t i = 0; i < parent->indexes.size(); i++)
			index.push_back(parent->indexes[i]);
		position++;
		if (parent->left) 
			find_lines_rec(parent->left, index, position);
		if (parent->right)
			find_lines_rec(parent->right, index, position);
		
	}
	vector <int> numsToBeDeleted;
	if (parent && (position) != 0) {
		for (size_t i = 0; i < index.size(); i++)
			if (!(find(parent->indexes.begin(), parent->indexes.end(), index[i]) != parent->indexes.end()))
				numsToBeDeleted.push_back(index[i]);

		for (size_t i = 0; i < numsToBeDeleted.size(); i++) {
			vector<int>::iterator position = find(index.begin(), index.end(), numsToBeDeleted[i]);
			index.erase(position);
		}
		numsToBeDeleted.clear();

		position++;
		if (parent->left)
			find_lines_rec(parent->left, index, position);
		if (parent->right)
			find_lines_rec(parent->right, index, position);
	}
}
vector <int> Tree::find_lines() {
	vector <int> vec;
	int pos = 0;
	find_lines_rec(root, vec, pos);
	return vec;
}

