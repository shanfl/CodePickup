#ifndef _NED_ALLOCATOR_H_
#define _NED_ALLOCATOR_H_


#if  OGRE_MEMORY_ALLOCATOR == OGRE_MEMORY_ALLOCATOR_NED

#include "OgreMemoryAllocatedObject.h"
#include "OgreMemorySTLAllocator.h"

///////////////////////////////////////////////////
#  include "OgreMemoryNedAlloc.h"
namespace Ogre
{
	// configure default allocators based on the options above
	// notice how we're not using the memory categories here but still roughing them out
	// in your allocators you might choose to create different policies per category

	// configurable category, for general malloc
	// notice how we ignore the category here, you could specialise
	template <MemoryCategory Cat> class CategorisedAllocPolicy : public NedAllocPolicy{};
	template <MemoryCategory Cat, size_t align = 0> class CategorisedAlignAllocPolicy : public NedAlignedAllocPolicy<align>{};
}

#endif
#endif