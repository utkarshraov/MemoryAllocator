#pragma once
#include "BitArray.h"

#include"MemoryManagement.h"


 BitArray * BitArray::Create(size_t numBits, bool initToZero, MemoryAllocator * heap)
{
	 return new BitArray(numBits, initToZero, heap);
}

 void BitArray::setAll(bool setValue)
 {
	 assert(bits);
	 memset(bits, setValue ? 0 : 1, sizeOfArray / bitPerByte);
 }

void BitArray::setBit(size_t index)
{
	assert(index > 0);
	size_t bitIndex = index / bitPerByte;
	size_t offset = index % bitPerByte;

#ifdef _WIN32
	uint32_t mask = 1;
#elif _WIN64
	uint64_t mask = 1;
#endif
	mask << offset;
	bits[index] = bits[index] | mask;
}

void BitArray::clearBit(size_t index)
{
	assert(index > 0);
	size_t bitIndex = index / bitPerByte;
	size_t offset = index % bitPerByte;

#ifdef _WIN32
	uint32_t mask = 1;
#elif _WIN64
	uint64_t mask = 1;
#endif
	mask << offset;
	bits[index] = bits[index] - mask;
}

bool BitArray::isSet(size_t index) const
{
	assert(index > 0);
	size_t bitIndex = index / bitPerByte;
	size_t offset = index % bitPerByte;

#ifdef _WIN32
	uint32_t mask = 1;
	uint32_t temp = bits[index];
#elif _WIN64
	uint64_t mask = 1;
	uint64_t temp = bits[index];
#endif
	mask << offset;
	
	temp = temp | mask;
	if (temp == bits[index])
		return true;
	else 
		return false;
}

bool BitArray::isClear(size_t index) const
{
	assert(index > 0);
	size_t bitIndex = index / bitPerByte;
	size_t offset = index % bitPerByte;

#ifdef _WIN32
	uint32_t mask = 1;
	uint32_t temp = bits[index];
#elif _WIN64
	uint64_t mask = 1;
	uint64_t temp = bits[index];
#endif
	mask << offset;
	temp = temp - mask;
	if (temp == bits[index])
		return true;
	else 
		return false;
}