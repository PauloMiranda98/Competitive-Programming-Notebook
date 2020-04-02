#include "../../code/data_structures/implicit_treap.h"

void testInsert(){
	ImplicitTreap tree;
	tree.insert(0, 10);
	tree.insert(1, 20);
	tree.insert(2, 30);
	tree.insert(1, 5);

	assert(tree.at(0) == 10);
	assert(tree.at(1) == 5);
	assert(tree.at(2) == 20);
	assert(tree.at(3) == 30);
}

void testErase(){
	ImplicitTreap tree;
	tree.insert(0, 10);
	tree.insert(1, 5);
	tree.insert(2, 20);
	tree.insert(3, 30);

	tree.erase(2);

	assert(tree.at(0) == 10);
	assert(tree.at(1) == 5);
	assert(tree.at(2) == 30);
}

void testQuery(){
	ImplicitTreap tree;
	tree.insert(0, 10);
	tree.insert(1, 20);
	tree.insert(2, 30);
	tree.insert(3, 5);

	assert(tree.query(0, 2) == 60);
	assert(tree.query(1, 1) == 20);
	assert(tree.query(2, 3) == 35);
}

void testReverse(){
	ImplicitTreap tree;
	tree.insert(0, 10);
	tree.insert(1, 20);
	tree.insert(2, 30);
	tree.insert(3, 5);

	tree.reverse(1, 3);

	assert(tree.at(0) == 10);
	assert(tree.at(1) == 5);
	assert(tree.at(2) == 30);
	assert(tree.at(3) == 20);

	tree.reverse(1, 2);

	assert(tree.at(0) == 10);
	assert(tree.at(1) == 30);
	assert(tree.at(2) == 5);
	assert(tree.at(3) == 20);
}

int main(){
	testInsert();
	testErase();
	testQuery();
	testReverse();
	return 0;
}
