#pragma once
#include "BlockDescriptor.h"

class LinkedListBD {
public:
	
	struct node{
		void * next;
		BlockDescriptor bd;
	};

	node * head;
	LinkedListBD();
	bool insertBD(BlockDescriptor toInsert);
	bool removeBD(BlockDescriptor toRemove);
	BlockDescriptor getAvailableBlock(size_t blockSize);
};