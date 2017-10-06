#include<stdio.h>
#include<stdlib.h>
#include "BlockDescriptor.h"
#include "LinkedListBD.h"
#include "DebugStatement.h"
#include "MemoryAllocator.h"
#include<assert.h>

	BlockDescriptor heap;
	LinkedListBD blockDescriptors;
	LinkedListBD freeBlocks;
	LinkedListBD usedBlocks;
	MemoryAllocator:: MemoryAllocator(size_t heapSize) {
		heap.address = _aligned_malloc(heapSize,4);
		heap.size = heapSize;
		DEBUG_PRINT("i am in init!");
		
		int numBlocks = 30;
		void * temp;
		temp = (unsigned char*)heap.address + heapSize - (30 * sizeof(BlockDescriptor));
		BlockDescriptor tempBD;
		tempBD.size = 0;
		tempBD.address = temp;
		DEBUG_PRINT("TEMP VAR ASSIGNED");
		
		for (int i = 0; i < numBlocks; i++)
		{
			blockDescriptors.insertBD(tempBD);
			tempBD.address = (unsigned char*)tempBD.address + sizeof(BlockDescriptor);
			tempBD.size = 0;
			DEBUG_PRINT("Assigning block descriptors");
		}
		heap.size -= (size_t)(30 * sizeof(BlockDescriptor));
		BlockDescriptor newHeap = blockDescriptors.getBlock();
		newHeap.address = heap.address;
		newHeap.size = heap.size;
		freeBlocks.insertBD(newHeap);
		DEBUG_PRINT("init ended");
	}

	void * MemoryAllocator::alloc(size_t blockSize)
	{
		DEBUG_PRINT("I am in alloc");
		if (blockSize < heap.size) {
			DEBUG_PRINT("IT FITS");
			BlockDescriptor tempBD = blockDescriptors.getBlock();
			assert(freeBlocks.getAvailableBlock(blockSize,tempBD));
			if (tempBD.size - blockSize > 16)
			{
				divide(tempBD, blockSize);
			}
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

	void MemoryAllocator::divide(BlockDescriptor & toDivide, size_t size)
	{
		BlockDescriptor temp = blockDescriptors.getBlock();
		temp.address = (unsigned char*)toDivide.address + size;
		temp.size = toDivide.size - size;
		toDivide.size = size;
		freeBlocks.orderedInsertBD(temp);
		DEBUG_PRINT("divide method called");
	}

	void MemoryAllocator::dealloc(void * pointer)
	{
		LinkedListBD::node *current = new LinkedListBD::node();
		current = usedBlocks.head;
		LinkedListBD::node *previous = new LinkedListBD::node();

		DEBUG_PRINT("dealloc started");
		while (current != nullptr)
		{
			if (current->bd.address == pointer)
			{
			
				previous->next = current->next;
				freeBlocks.orderedInsertBD(current->bd);
				DEBUG_PRINT("succesful free");
				current = current->next;
			}
			else
			{
				DEBUG_PRINT("iterate through LL");
				previous = current;
				current = current->next;
			}
		}
	}


