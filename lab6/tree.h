#pragma once
#include <string>;
#include <vector>;
#include <iostream>;
#include <fstream>;
#include <algorithm>
using namespace std;

class Node {
	string word;
	vector <int> indexes;
	Node* right;
	Node* left;
public:
	Node(string , int );
	~Node();
	friend class Tree;
};

class Tree {
	Node* root;
	void add_node_rec(Node*& , string , int );
	void print_rec(Node*& , int );
	void find_lines_rec(Node*& , vector <int>&, int&);
public:
	Tree();
	~Tree();
	void print();
	void add_node(string , int );
	vector <int> find_lines();
};