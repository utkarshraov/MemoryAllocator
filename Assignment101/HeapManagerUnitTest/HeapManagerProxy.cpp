
#include "HeapManagerProxy.h"

#include <assert.h>
#include <stdio.h>
#include "MemoryAllocator.h"


namespace HeapManagerProxy
{

MemoryAllocator * CreateHeapManager( void * i_pMemory, size_t i_sizeMemory, unsigned int i_numDescriptors )
{
	return MemoryAllocator::makeHeap( i_pMemory, i_sizeMemory, i_numDescriptors );
}

void Destroy( MemoryAllocator * i_pManager )
{
	assert( i_pManager );

	i_pManager->~MemoryAllocator();
}

void * alloc( MemoryAllocator * i_pManager, size_t i_size )
{
	assert( i_pManager );
	return i_pManager->alloc( i_size );
}

void * alloc( MemoryAllocator * i_pManager, size_t i_size, unsigned int i_alignment )
{
	assert( i_pManager );

	return i_pManager->alloc( i_size, i_alignment );
}

bool free( MemoryAllocator * i_pManager, void * i_ptr )
{
	assert( i_pManager );

	return i_pManager->dealloc( i_ptr );
}

void Collect( MemoryAllocator * i_pManager )
{
	assert( i_pManager );

	i_pManager->garbageCollection();
}


bool Contains( const MemoryAllocator * i_pManager, void * i_ptr )
{
	assert( i_pManager );

	return i_pManager->isAddressInHeap( i_ptr );
}

bool IsAllocated( const MemoryAllocator * i_pManager, void * i_ptr )
{
	assert( i_pManager );

	return i_pManager->isAddressAllocated( i_ptr );
}

/*size_t GetLargestFreeBlock( const HeapManager * i_pManager )
{
	assert( i_pManager );

	//return i_pManager->getLargestFreeBlock();
}

size_t GetTotalFreeMemory( const HeapManager * i_pManager )
{
	assert( i_pManager );

	//return i_pManager->getTotalFreeMemory();
}

void ShowFreeBlocks( const HeapManager * i_pManager )
{
	assert( i_pManager );

	i_pManager->ShowFreeBlocks();
}*/

void ShowOutstandingAllocations( const HeapManager * i_pManager )
{
	assert( i_pManager );

#ifdef __TRACK_ALLOCATIONS
	i_pManager->ShowOutstandingAllocations();
#else
	printf( "HeapManager compiled without __TRACK_ALLOCATIONS defined.\n" );
#endif

}

} // namespace HeapManagerProxy