#include "LinkedListBD.h"
#include "BlockDescriptor.h"
#include "DebugStatement.h"

LinkedListBD::LinkedListBD()
{
	head = nullptr;
}

bool LinkedListBD::insertBD(BlockDescriptor &toInsert) {
	LinkedListBD::node * tempNode = new LinkedListBD::node();
	tempNode->next = head;
	tempNode->bd = toInsert;
	head = tempNode;
	return true;
}

bool LinkedListBD::orderedInsertBD(BlockDescriptor &toInsert) {
	LinkedListBD::node * currentNode = new LinkedListBD::node();
	LinkedListBD::node * previousNode = new LinkedListBD::node();
	currentNode = head;
	previousNode = nullptr;
	if (head == nullptr)
	{
		DEBUG_PRINT("ordered insert at head");
		head->bd = toInsert;
		head->next = nullptr;
		return true;
	}
	while (currentNode != nullptr)
	{
		if (toInsert.address < currentNode->bd.address)
		{
			if (currentNode == head)
			{
				DEBUG_PRINT("ordered insert before head");
				head->bd = toInsert;
				head->next = currentNode;
				return true;
			}
			DEBUG_PRINT("inserted in between something");
			LinkedListBD::node * tempNode = new LinkedListBD::node();
			tempNode->bd = toInsert;
			tempNode->next = currentNode;
			previousNode->next = tempNode;
			return true;
		}
		previousNode = currentNode;
		currentNode = currentNode->next;
	}
	LinkedListBD::node * tempNode = new LinkedListBD::node();
	tempNode->bd = toInsert;
	tempNode->next = currentNode;
	previousNode->next = tempNode;
	DEBUG_PRINT("ordered insert at end of free");
	return true;

}
bool LinkedListBD::removeBD(BlockDescriptor toRemove) {
	LinkedListBD::node * currentNode = new LinkedListBD::node();
	LinkedListBD::node * previousNode = new LinkedListBD::node();
	currentNode = head;
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

void LinkedListBD::getBlock(BlockDescriptor &temp)
{
	if (head != nullptr)
	{
		temp = head->bd;
		head = head->next;
	}
	else
	{
		DEBUG_PRINT("no available block descriptors");
	}
}