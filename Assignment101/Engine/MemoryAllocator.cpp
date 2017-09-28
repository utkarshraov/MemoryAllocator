#include<stdio.h>
#include<stdlib.h>
#include "BlockDescriptor.h"
#include "LinkedListBD.h"

class MemoryAllocator {

	BlockDescriptor heap;
	LinkedListBD blockDescriptors;
	LinkedListBD freeBlocks;
	LinkedListBD usedBlocks;
	MemoryAllocator(size_t heapSize) {
		void * temp = _aligned_malloc(heapSize,4);
		heap.size = heapSize;
		heap.address = temp;
		
		int numBlocks = 30;
		temp = (unsigned char*)temp + heapSize - (30 * sizeof(BlockDescriptor));
		BlockDescriptor tempBD;
		tempBD.address = temp;
		
		for (int i = 0; i < numBlocks; i++)
		{
			blockDescriptors.insertBD(tempBD);
			tempBD.address = (unsigned char*)tempBD.address + sizeof(BlockDescriptor);
		}
	}

	void * alloc(size_t blockSize)
	{
		BlockDescriptor tempBD;
		tempBD = blockDescriptors.head->bd;
		if (blockSize < heap.size) {
			tempBD = freeBlocks.getAvailableBlock(blockSize);
			usedBlocks.insertBD(tempBD);
			freeBlocks.removeBD(tempBD);
		}

	}

};