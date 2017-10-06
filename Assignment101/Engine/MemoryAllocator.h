#pragma once
#include<stdio.h>
#include<stdlib.h>
#include "BlockDescriptor.h"
#include "LinkedListBD.h"
#include "DebugStatement.h"

class MemoryAllocator {
public:
	BlockDescriptor heap;
	LinkedListBD blockDescriptors;
	LinkedListBD freeBlocks;
	LinkedListBD usedBlocks;
	MemoryAllocator(size_t heapSize);

	void * alloc(size_t blockSize);

	void divide(BlockDescriptor & toDivide, size_t size);

	void dealloc(void * pointer);

};
