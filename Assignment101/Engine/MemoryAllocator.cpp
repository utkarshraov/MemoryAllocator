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
		int j = 50;
		DEBUG_PRINT("i am in init!");
		
		int numBlocks = 30;
		void * temp;
		temp = (unsigned char*)heap.address + heapSize - (30 * sizeof(BlockDescriptor));
		BlockDescriptor tempBD;
		tempBD.size = 0;
		tempBD.address = temp;
		
		for (int i = 0; i < numBlocks; i++)
		{
			blockDescriptors.insertBD(tempBD);
			tempBD.address = (unsigned char*)tempBD.address + sizeof(BlockDescriptor);
			tempBD.size = 0;
			DEBUG_PRINT("Assigning block descriptors");
		}
		heap.size -= (size_t)(30 * sizeof(BlockDescriptor));
		BlockDescriptor newHeap;
		blockDescriptors.getBlock(newHeap);
		newHeap.address = heap.address;
		newHeap.size = heap.size;
		freeBlocks.insertBD(heap);
		DEBUG_PRINT("init ended");
	}

	void * MemoryAllocator::alloc(size_t blockSize)
	{
		DEBUG_PRINT("I am in alloc");
		if (blockSize < heap.size) {
			DEBUG_PRINT("IT FITS");
			BlockDescriptor tempBD;
			blockDescriptors.getBlock(tempBD);
			assert(freeBlocks.getAvailableBlock(blockSize,tempBD));
			if (tempBD.size - blockSize > 16)
			{
				divide(tempBD, blockSize);
				DEBUG_PRINT("size before = %d address = %d heap address = %d", tempBD.size,&tempBD,&heap);
				tempBD.size -= blockSize;
				DEBUG_PRINT("size after = %daddress = %d heap address = %d", tempBD.size,&tempBD,&heap);
				
				heap.size -= blockSize;
			}
			else { 
				usedBlocks.insertBD(tempBD); 
				freeBlocks.removeBD(tempBD);
				heap.size -= tempBD.size;
			}
			//assert(garbageCollection());
			return tempBD.address;
		}
		else
		{
			//assert(garbageCollection());

			DEBUG_PRINT("There was no memory you idiot");
			return nullptr;
		}
	}

	void MemoryAllocator::divide(BlockDescriptor & toDivide, size_t size)
	{
		BlockDescriptor  temp;
		blockDescriptors.getBlock(temp);
		temp.address = (unsigned char*)toDivide.address + toDivide.size - size;
		temp.size = size;
		usedBlocks.insertBD(temp);
		DEBUG_PRINT("divide method called");
	}

	bool MemoryAllocator::dealloc(void * pointer)
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
				heap.size += current->bd.size;
				freeBlocks.orderedInsertBD(current->bd);
				DEBUG_PRINT("succesful free");
				current = current->next;
				
				return true;
			}
			else
			{
				DEBUG_PRINT("iterate through LL");
				previous = current;
				current = current->next;
			}
		}
		return false;
	}

	bool MemoryAllocator::garbageCollection()
	{
		DEBUG_PRINT("garbage collection started");
		LinkedListBD::node * currentNode = new LinkedListBD::node();
		LinkedListBD::node * previousNode = new LinkedListBD::node();
		currentNode = freeBlocks.head;
		while (currentNode->next != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->next;
			if ((unsigned char *)previousNode->bd.address + previousNode->bd.size == (unsigned char*)currentNode->bd.address)
			{
				DEBUG_PRINT("combined something");
				previousNode->bd.size += currentNode->bd.size;
				previousNode->next = currentNode->next;
				blockDescriptors.insertBD(currentNode->bd);
			}
		}
		DEBUG_PRINT("Garbage collection completed");
		return true;
	}

	void MemoryAllocator::printAllBlocks(LinkedListBD list)
	{
		LinkedListBD::node * currentNode = new LinkedListBD::node();
		currentNode = list.head;
		while (currentNode != nullptr)
		{
			DEBUG_PRINT("address %d and size %d",currentNode->bd.address,currentNode->bd.size);
			currentNode = currentNode->next;
		}
	}
