#pragma once

#include<stdlib.h>
#include "MemoryAllocator.h"
#include<assert.h>


enum ALIGNMENT {
	DEFAULT,
	ALIGN_16,
	ALIGN_32
};

void * operator new(size_t size);

void * operator new(size_t size, ALIGNMENT align);

void * operator new(size_t size, MemoryAllocator * heap, unsigned int alignment);

void * operator new[](size_t size);

void operator delete(void * pointer);

void operator delete(void * pointer, MemoryAllocator * heap, unsigned int align);

void operator delete[](void * pointer);