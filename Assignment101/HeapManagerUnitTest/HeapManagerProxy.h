#ifndef __HEAP_MANAGER_PROXY_H
#define __HEAP_MANAGER_PROXY_H
#pragma once
#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "MemoryAllocator.h"

class HeapManager;


namespace HeapManagerProxy
{

MemoryAllocator *	CreateHeapManager( void * i_pMemory, size_t i_sizeMemory, unsigned int i_numDescriptors );
void			Destroy( MemoryAllocator * i_pManager );

void *			alloc(MemoryAllocator * i_pManager, size_t i_size );
void *			alloc(MemoryAllocator * i_pManager, size_t i_size, unsigned int i_alignment );
bool			free(MemoryAllocator * i_pManager, void * i_ptr );

void			Collect(MemoryAllocator * i_pManager );

bool			Contains( const MemoryAllocator * i_pManager, void * i_ptr );
bool			IsAllocated( const MemoryAllocator * i_pManager, void * i_ptr );

/*size_t			GetLargestFreeBlock( const HeapManager * i_pManager );
size_t			GetTotalFreeMemory( const HeapManager * i_pManager );

void			ShowFreeBlocks( const HeapManager * i_pManager );
void			ShowOutstandingAllocations( const HeapManager * i_pManager );*/

} // namespace HeapManagerProxy

#endif // __HEAP_MANAGER_PROXY_H