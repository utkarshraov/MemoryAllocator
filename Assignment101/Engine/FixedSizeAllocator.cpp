#include"FixedSizeAllocator.h"

void FSA::setAddresses()
{
	void * temp = FSAStart;
	for (size_t i = 0; i < totalBlocks-1; i++)
	{
		memAddress[i] = temp;
		uintptr_t value = reinterpret_cast<uintptr_t>(temp) + blockWidth;
		temp = reinterpret_cast<void*>(value);
	}
}

void * FSA::getBlock()
{
	size_t index = bArray->firstClear();
	bArray->setBit(index);
	return memAddress[index];
}

bool FSA::returnBlock(void * pointer)
{
	if (isAllocated(pointer))
	{
		size_t i = 0;
		for (i = 0; i < totalBlocks-1; i++)
		{
			if (memAddress[i] == pointer)
				break;
		}
		bArray->clearBit(i);
		return true;
	}
	else
		return false;
}

bool FSA::contains(void * pointer) const
{
	if (pointer >= FSAStart && pointer <= FSAEnd)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool FSA::isAllocated(void * pointer) const
{
	assert(contains(pointer));
	size_t i = 0;
	for (i = 0; i < totalBlocks-1; i++)
	{
		if (memAddress[i] == pointer)
			return true;
	}
	return false;
}