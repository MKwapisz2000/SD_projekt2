#pragma once

class Node
{
	int element;
	int priority;
	
public:
	Node(int e, int p);
	Node();
	friend class Heap;
};

class Heap
{
	Node* tab;
	int size;
	int capacity;
	
public:
	Heap();
	~Heap();
	
	void increase_capacity();
	void insert(int e, int p);
	void extract_max();
	void find_max() const;
	void modify_key(int e, int p);
	void increase_key(int index, int p, int i);
	void decrease_key(int index, int p, int i);
	int return_size();
	void show() const;
	void clear();
};