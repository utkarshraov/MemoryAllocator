#include "FixedSizeAllocator.h"
#include "MemoryAllocator.h"

void main()
{
	void * mem = _aligned_malloc(100000,4);
	void * object = _aligned_malloc(sizeof(MemoryAllocator),4);
	
	MemoryAllocator heap = MemoryAllocator(mem, 100000, 200);
	void * a1 = heap.alloc(8);
	void * a2 = heap.alloc(16);
	assert(heap.dealloc(a1));
	assert(heap.dealloc(a2));
}