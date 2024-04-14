#pragma once

class Node
{
	int element;
	int priority;
	//Node* parent;
	//Node* child_left;
	//Node* child_right;

public:
	Node(int e, int p);
	Node();
	friend class Heap;
};

class Heap
{
	Node* tab;
	//Node* root;
	int size;
	int capacity;
	


public:
	Heap();
	~Heap();
	

	void increase_capacity();
	void insert(int e, int p);
	void extract_max();
	void find_max() const;
	//void modify_key(int e, int p);
	int return_size();
	void show() const;
};