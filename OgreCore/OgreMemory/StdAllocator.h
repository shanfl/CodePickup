#ifndef _STD_ALLOCATOR_H_
#define _STD_ALLOCATOR_H_



#if  OGRE_MEMORY_ALLOCATOR == OGRE_MEMORY_ALLOCATOR_STD

#include "OgreMemoryStdAlloc.h"
#include "OgreMemoryAllocatedObject.h"
#include "OgreMemorySTLAllocator.h"

namespace Ogre
{
	// configure default allocators based on the options above
	// notice how we're not using the memory categories here but still roughing them out
	// in your allocators you might choose to create different policies per category

	// configurable category, for general malloc
	// notice how we ignore the category here
	template <MemoryCategory Cat> 
	class CategorisedAllocPolicy : public StdAllocPolicy
	{

	};

	template <MemoryCategory Cat, size_t align = 0> 
	class CategorisedAlignAllocPolicy : 
		public StdAlignedAllocPolicy<align>
	{
	};

	// if you wanted to specialise the allocation per category, here's how it might work:
	// template <> class CategorisedAllocPolicy<MEMCATEGORY_SCENE_OBJECTS> : public YourSceneObjectAllocPolicy{};
	// template <size_t align> class CategorisedAlignAllocPolicy<MEMCATEGORY_SCENE_OBJECTS, align> : public YourSceneObjectAllocPolicy<align>{};
	
	
}
#endif

#endif