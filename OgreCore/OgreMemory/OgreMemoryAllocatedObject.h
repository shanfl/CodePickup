/*
-----------------------------------------------------------------------------
This source file is part of OGRE
(Object-oriented Graphics Rendering Engine)
For the latest info, see http://www.ogre3d.org/

Copyright (c) 2000-2011 Torus Knot Software Ltd

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
-----------------------------------------------------------------------------
*/

#ifndef __AllocatedObject_H__
#define __AllocatedObject_H__

namespace Ogre
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Memory
	*  @{
	*/

	/** A set of categories that indicate the purpose of a chunk of memory
	being allocated. 
	These categories will be provided at allocation time in order to allow
	the allocation policy to vary its behaviour if it wishes. This allows you
	to use a single policy but still have variant behaviour. The level of 
	control it gives you is at a higher level than assigning different 
	policies to different classes, but is the only control you have over
	general allocations that are primitive types.
	*/
	enum MemoryCategory
	{
		/// General purpose
		MEMCATEGORY_GENERAL = 0,
		/// Geometry held in main memory
		MEMCATEGORY_GEOMETRY = 1, 
		/// Animation data like tracks, bone matrices
		MEMCATEGORY_ANIMATION = 2, 
		/// Nodes, control data
		MEMCATEGORY_SCENE_CONTROL = 3,
		/// Scene object instances
		MEMCATEGORY_SCENE_OBJECTS = 4,
		/// Other resources
		MEMCATEGORY_RESOURCE = 5,
		/// Scripting
		MEMCATEGORY_SCRIPTING = 6,
		/// Rendersystem structures
		MEMCATEGORY_RENDERSYS = 7,

		
		// sentinel value, do not use 
		MEMCATEGORY_COUNT = 8
	};
	/** @} */
	/** @} */

}

//#include "OgrePrerequisites.h"
#include <cstddef>

// Anything that has done a #define new <blah> will screw operator new definitions up
// so undefine

#ifdef new
#  undef new
#endif
#ifdef delete
#  undef delete
#endif

namespace Ogre
{
	/** \addtogroup Core
	*  @{
	*/
	/** \addtogroup Memory
	*  @{
	*/
	/** Superclass for all objects that wish to use custom memory allocators
		when their new / delete operators are called.
		Requires a template parameter identifying the memory allocator policy 
		to use (e.g. see StdAllocPolicy). 
	*/
	template <class Alloc>
	class  AllocatedObject
	{
	public:
		explicit AllocatedObject()
		{ }

		~AllocatedObject()
		{ }

		/// operator new, with debug line info
		void* operator new(size_t sz, const char* file, int line, const char* func)
		{
			return Alloc::allocateBytes(sz, file, line, func);
		}

		void* operator new(size_t sz)
		{
			return Alloc::allocateBytes(sz);
		}

		/// placement operator new
		void* operator new(size_t sz, void* ptr)
		{
			(void) sz;
			return ptr;
		}

		/// array operator new, with debug line info
		void* operator new[] ( size_t sz, const char* file, int line, const char* func )
		{
			return Alloc::allocateBytes(sz, file, line, func);
		}

		void* operator new[] ( size_t sz )
		{
			return Alloc::allocateBytes(sz);
		}

		void operator delete( void* ptr )
		{
			Alloc::deallocateBytes(ptr);
		}

		// Corresponding operator for placement delete (second param same as the first)
		void operator delete( void* ptr, void* )
		{
			Alloc::deallocateBytes(ptr);
		}

		// only called if there is an exception in corresponding 'new'
		void operator delete( void* ptr, const char* , int , const char*  )
		{
			Alloc::deallocateBytes(ptr);
		}

		void operator delete[] ( void* ptr )
		{
			Alloc::deallocateBytes(ptr);
		}


		void operator delete[] ( void* ptr, const char* , int , const char*  )
		{
			Alloc::deallocateBytes(ptr);
		}
	};


	/** @} */
	/** @} */

}
#endif
