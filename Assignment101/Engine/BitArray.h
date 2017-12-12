#pragma once
#include<stdlib.h>
#include<cstdint>
#include "MemoryAllocator.h"
#include<string.h>

class BitArray
{
public:
	BitArray * Create(size_t numBits, bool initToZero, MemoryAllocator * heap);
	~BitArray();
	size_t firstSet();
	size_t firstClear();
	bool isClear(size_t index) const;
	bool isSet(size_t index) const;
	void setBit(size_t index);
	void clearBit(size_t index);
	void setAll();
	void clearAll();

private:
#ifdef _WIN32
		uint32_t * bits;
#elif _WIN64
		uint64_t * bits;
#endif


};