#include "../../code/data_structures/multiset_hash.h"

void testAdd(){
	MultisetHash a({1, 2, 2, 5});

	MultisetHash b;

	b.add(1);
	assert(a.getHash() != b.getHash());

	b.add(2);
	assert(a.getHash() != b.getHash());

	b.add(2);
	assert(a.getHash() != b.getHash());

	b.add(5);
	assert(a.getHash() == b.getHash());
}

void testAdd2(){
	MultisetHash a({1, 2, 2, 5});

	MultisetHash b;

	b.add(1, 1);
	assert(a.getHash() != b.getHash());

	b.add(2, 2);
	assert(a.getHash() != b.getHash());

	b.add(5, 1);
	assert(a.getHash() == b.getHash());
}

void testRemove(){
	MultisetHash a({1, 2, 2, 5});

	MultisetHash b({1, 2, 5});

	assert(a.getHash() != b.getHash());

	b.add(2);
	assert(a.getHash() == b.getHash());

	b.add(2);
	assert(a.getHash() != b.getHash());

	b.rem(2);
	assert(a.getHash() == b.getHash());

	b.rem(5);
	assert(a.getHash() != b.getHash());
}

void testRemove2(){
	MultisetHash a({1, 2, 2, 5});

	MultisetHash b({1, 2, 5});

	assert(a.getHash() != b.getHash());

	b.rem(2);
	assert(a.getHash() != b.getHash());

	a.rem(2, 2);
	assert(a.getHash() == b.getHash());
}

void testAddMultiset(){
	MultisetHash a({1, 2, 2, 5});
	MultisetHash b({1, 2, 5});

	MultisetHash c({1, 1, 2, 2, 2, 5, 5});

	assert(a.getHash() != b.getHash());
	assert(a.getHash() != c.getHash());
	assert(b.getHash() != c.getHash());

	b.addMultiset(a);
	assert(b.getHash() == c.getHash());
}

void testRemMultiset(){
	MultisetHash a({1, 2, 2, 5});
	MultisetHash b({1, 2, 5});

	MultisetHash c({1, 1, 2, 2, 2, 5, 5});

	assert(a.getHash() != b.getHash());
	assert(a.getHash() != c.getHash());
	assert(b.getHash() != c.getHash());

	c.remMultiset(a);
	assert(b.getHash() == c.getHash());
}

int main(){
	testAdd();
	testAdd2();
	testRemove();
	testRemove2();
	testAddMultiset();
	testRemMultiset();

	return 0;
}
