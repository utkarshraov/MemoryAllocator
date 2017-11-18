#pragma once
#include<stdlib.h>
#include "MemoryAllocator.h"
#include<assert.h>
enum ALIGNMENT {
	DEFAULT,
	ALIGN_16,
	ALIGN_32
};

void * operator new(size_t size)
{
	return _aligned_malloc(size, 4);
}

void * operator new(size_t size, ALIGNMENT align)
{
	switch (align)
	{
	case DEFAULT:
		return _aligned_malloc(size, 4);
		break;
	case ALIGN_16:
		return _aligned_malloc(size, 16);
		break;
	case ALIGN_32:
		return _aligned_malloc(size, 32);
		break;
	}
}

void * operator new(size_t size, MemoryAllocator * heap, unsigned int alignment)
{
	assert(heap != NULL);
	heap->alloc(size, alignment);
}

