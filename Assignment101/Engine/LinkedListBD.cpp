#include "LinkedListBD.h"
#include "BlockDescriptor.h"

LinkedListBD::LinkedListBD()
{
	head=nullptr;
	head->next = nullptr;
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

BlockDescriptor LinkedListBD::getAvailableBlock(size_t blockSize)
{
	BlockDescriptor returnBD;
	returnBD.address = head;
	returnBD.size = 64;
	return returnBD;
}