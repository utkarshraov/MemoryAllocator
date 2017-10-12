#pragma once
#include "BlockDescriptor.h"

class LinkedListBD {
public:
	
	struct node{
		node * next;
		BlockDescriptor bd;
	};

	node * head;
	LinkedListBD();
	bool insertBD(BlockDescriptor &toInsert);
	bool removeBD(BlockDescriptor toRemove);
	bool orderedInsertBD(BlockDescriptor &toInsert);
	bool getAvailableBlock(size_t blockSize,BlockDescriptor & availableBD);
	void getBlock(BlockDescriptor & temp);
};