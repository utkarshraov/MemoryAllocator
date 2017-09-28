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
	MemoryAllocator(size_t heapSize) {
		void * temp = _aligned_malloc(heapSize,4);
		heap.size = heapSize;
		heap.address = temp;
		DEBUG_PRINT("i am in init!");
		
		int numBlocks = 30;
		temp = (unsigned char*)temp + heapSize - (30 * sizeof(BlockDescriptor));
		BlockDescriptor tempBD;
		tempBD.address = temp;
		DEBUG_PRINT("TEMP VAR ASSIGNED");
		
		for (int i = 0; i < numBlocks; i++)
		{
			blockDescriptors.insertBD(tempBD);
			tempBD.address = (unsigned char*)tempBD.address + sizeof(BlockDescriptor);
			DEBUG_PRINT("Assigning block descriptors");
		}
	}

	void * alloc(size_t blockSize)
	{
		DEBUG_PRINT("I am in alloc");
		BlockDescriptor tempBD;
		tempBD = blockDescriptors.head->bd;
		if (blockSize < heap.size) {
			DEBUG_PRINT("IT FITS");
			tempBD = freeBlocks.getAvailableBlock(blockSize);
			usedBlocks.insertBD(tempBD);
			freeBlocks.removeBD(tempBD);
			return tempBD.address;
		}
		else
		{
			DEBUG_PRINT("There was no memory you idiot");
			return nullptr;
		}
	}

};

