#pragma once
#include "BlockDescriptor.h"
#include<stdio.h>

class MemoryAllocator {

	BlockDescr
	
	MemoryAllocator(size_t);

	void * allocate(size_t);

	bool dealloc(BlockDescriptor);
};