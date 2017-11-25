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
	return heap->alloc(size, alignment);
}

void * operator new[](size_t size)
{
	return _aligned_malloc(size, 4);
}

void operator delete(void * pointer)
{
	assert(pointer != 0);
	_aligned_free(pointer);
}
void operator delete(void * pointer, MemoryAllocator * heap, unsigned int align)
{
	assert(pointer != 0);
	assert(heap != NULL);
	if (heap->isAddressInHeap(pointer) && heap->isAddressAllocated(pointer))
	{
		heap->dealloc(pointer);
	}
}

void operator delete[](void * pointer)
{
	assert(pointer != 0);
	_aligned_free(pointer);
}