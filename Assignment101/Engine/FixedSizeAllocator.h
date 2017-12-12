#pragma once
#include"MemoryAllocator.h"
#include "BitArray.h"
#include<vector>

class FSA
{
public:
	FSA(size_t numBlocks, MemoryAllocator * heap, size_t blockSize)
	{
		assert(numBlocks);
		assert(heap);
		assert(blockSize);
		thisHeap = heap;
		FSAStart = thisHeap->alloc((blockSize * numBlocks));
		uintptr_t temp = reinterpret_cast<uintptr_t>(FSAStart) + (blockSize*numBlocks);
		FSAEnd = reinterpret_cast<void*>(temp);
		totalBlocks = numBlocks;
		blockWidth = blockSize;
		bArray = BitArray::Create(numBlocks,0, thisHeap);
		memAddress = new void*[numBlocks];
		setAddresses();
		
	}
	void * getBlock();
	bool returnBlock(void * pointer);
	bool contains(void * pointer) const;
	bool isAllocated(void * pointer) const;
private:
	BitArray * bArray;
	MemoryAllocator * thisHeap;
	size_t blockWidth;
	void ** memAddress;
	size_t totalBlocks;
	void * FSAStart;
	void * FSAEnd;
	void setAddresses();
};