#include "FixedSizeAllocator.h"
#include "MemoryAllocator.h"

void main()
{
	void * mem = _aligned_malloc(100000,4);
	MemoryAllocator * heap = new MemoryAllocator(mem, 100000, 200);
	FSA * size8 = new FSA(10, heap, 8);
	void * alloc1 = size8->getBlock();
	assert(size8->returnBlock(alloc1));
}