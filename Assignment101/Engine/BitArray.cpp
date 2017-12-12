#pragma once
#include "BitArray.h"
#include<assert.h>
#include"MemoryManagement.h"

 BitArray * BitArray::Create(size_t numBits, bool initToZero, MemoryAllocator * heap)
{
	 assert(numBits && "bit array size can't be 0");
	 assert(heap && "invalid heap passed");
#ifdef _WIN32
	 const size_t bitPerByte = 32;
	 bits = reinterpret_cast<uint32_t *>(operator new(numBits / bitPerByte, heap));
#elif _WIN64
	 const size_t bitPerByte = 64;
	 bits = reinterpret_cast<uint64_t *>(operator new(numBits / bitPerByte, heap));
#endif
	 
	 assert(bits);
	 memset(bits, initToZero ? 0 : 1, numBits / bitPerByte);


}