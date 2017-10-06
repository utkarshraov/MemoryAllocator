#include "LinkedListBD.h"
#include "BlockDescriptor.h"
#include "DebugStatement.h"

LinkedListBD::LinkedListBD()
{
	head = nullptr;
}

bool LinkedListBD::insertBD(BlockDescriptor toInsert) {
	LinkedListBD::node * tempNode = new LinkedListBD::node();
	tempNode->next = head;
	tempNode->bd = toInsert;
	head = tempNode;
	return true;
}
bool LinkedListBD::removeBD(BlockDescriptor toRemove) {
	LinkedListBD::node * currentNode = new LinkedListBD::node();
	LinkedListBD::node * previousNode = new LinkedListBD::node();
	currentNode = head;
	previousNode = nullptr;
	while (currentNode->next != nullptr) {
		
		if (currentNode->bd.address == toRemove.address) {
			previousNode->next = currentNode->next;
			return true;
		}
		else
		{
			previousNode = currentNode;
			currentNode = (node*)currentNode->next;
		}
	}
	return false;
}

bool LinkedListBD::getAvailableBlock(size_t blockSize,BlockDescriptor & availableBD)
{
	LinkedListBD::node* current = new LinkedListBD::node();
	current = head;
	while (current != nullptr)
	{
		if (current->bd.size > blockSize)
		{
			availableBD.address = current->bd.address;
			availableBD.size = current->bd.size;
			return true;
		}
		else
			current = current->next;

	}
	DEBUG_PRINT("no available block, garbage collection");
	return false;
}

BlockDescriptor LinkedListBD::getBlock()
{
	if (head != nullptr)
	{
		BlockDescriptor temp = head->bd;
		head = head->next;
		return temp;
	}
	else
	{
		DEBUG_PRINT("no available block descriptors");
		return head->bd;
	}
}