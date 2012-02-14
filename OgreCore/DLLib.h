 // PLATFORM.H
#define OGRE_PLATFORM_WIN32 1
#define OGRE_PLATFORM_LINUX 2
#define OGRE_PLATFORM_APPLE 3
#define OGRE_PLATFORM_SYMBIAN 4
#define OGRE_PLATFORM_APPLE_IOS 5
#define OGRE_PLATFORM_ANDROID 6
#define OGRE_PLATFORM_TEGRA2 7
#define OGRE_PLATFORM_NACL 8

#define OGRE_COMPILER_MSVC 1
#define OGRE_COMPILER_GNUC 2
#define OGRE_COMPILER_BORL 3
#define OGRE_COMPILER_WINSCW 4
#define OGRE_COMPILER_GCCE 5

#define OGRE_ENDIAN_LITTLE 1
#define OGRE_ENDIAN_BIG 2

#define OGRE_ARCHITECTURE_32 1
#define OGRE_ARCHITECTURE_64 2

/* Finds the compiler type and version.
*/
#if defined( __GCCE__ )
#   define OGRE_COMPILER OGRE_COMPILER_GCCE
#   define OGRE_COMP_VER _MSC_VER
//#	include <staticlibinit_gcce.h> // This is a GCCE toolchain workaround needed when compiling with GCCE 
#elif defined( __WINSCW__ )
#   define OGRE_COMPILER OGRE_COMPILER_WINSCW
#   define OGRE_COMP_VER _MSC_VER
#elif defined( _MSC_VER )
#   define OGRE_COMPILER OGRE_COMPILER_MSVC
#   define OGRE_COMP_VER _MSC_VER
#elif defined( __GNUC__ ) || defined __MINGW32__
#   define OGRE_COMPILER OGRE_COMPILER_GNUC
#   define OGRE_COMP_VER (((__GNUC__)*100) + \
        (__GNUC_MINOR__*10) + \
        __GNUC_PATCHLEVEL__)

#elif defined( __BORLANDC__ )
#   define OGRE_COMPILER OGRE_COMPILER_BORL
#   define OGRE_COMP_VER __BCPLUSPLUS__
#   define __FUNCTION__ __FUNC__ 
#else
#   pragma error "No known compiler. Abort! Abort!"

#endif
 /* Finds the current platform */

#if defined( __SYMBIAN32__ ) 
#   define OGRE_PLATFORM OGRE_PLATFORM_SYMBIAN
#elif defined( __WIN32__ ) || defined( _WIN32 )
#   define OGRE_PLATFORM OGRE_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
    // Device                                                     Simulator
    // Both requiring OS version 4.0 or greater
#   if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 40000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 40000
#       define OGRE_PLATFORM OGRE_PLATFORM_APPLE_IOS
#   else
#       define OGRE_PLATFORM OGRE_PLATFORM_APPLE
#   endif
#elif defined(linux) && defined(__arm__)
// TODO: This is NOT the correct way to detect the Tegra 2 platform but it works for now.
// It doesn't appear that GCC defines any platform specific macros.
#   define OGRE_PLATFORM OGRE_PLATFORM_TEGRA2
#elif defined(__ANDROID__)
#	define OGRE_PLATFORM OGRE_PLATFORM_ANDROID
#elif defined( __native_client__ ) 
#   define OGRE_PLATFORM OGRE_PLATFORM_NACL
#   ifndef OGRE_STATIC_LIB
#       error OGRE must be built as static for NaCl (OGRE_STATIC=true in cmake)
#   endif
#   ifdef OGRE_BUILD_RENDERSYSTEM_D3D9
#       error d3d9 is nor supported on NaCl (OOGRE_BUILD_RENDERSYSTEM_D3D9 false in cmake)
#   endif
#   ifdef OGRE_BUILD_RENDERSYSTEM_GL
#       error gl is nor supported on NaCl (OOGRE_BUILD_RENDERSYSTEM_GL=false in cmake)
#   endif
#   ifndef OGRE_BUILD_RENDERSYSTEM_GLES2
#       error GLES2 render system is needed for NaCl (OOGRE_BUILD_RENDERSYSTEM_GLES2=false in cmake)
#   endif
#else
#   define OGRE_PLATFORM OGRE_PLATFORM_LINUX
#endif

    /* Find the arch type */
#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#   define OGRE_ARCH_TYPE OGRE_ARCHITECTURE_64
#else
#   define OGRE_ARCH_TYPE OGRE_ARCHITECTURE_32
#endif

// For generating compiler warnings - should work on any compiler
// As a side note, if you start your message with 'Warning: ', the MSVC
// IDE actually does catch a warning :)
#define OGRE_QUOTE_INPLACE(x) # x
#define OGRE_QUOTE(x) OGRE_QUOTE_INPLACE(x)
#define OGRE_WARN( x )  message( __FILE__ "(" QUOTE( __LINE__ ) ") : " x "\n" )
 
 
 //------------export----------------
#define _OgreExport

//#define OGRE_FREE free

#ifdef _MSC_VER
#define FORCEINLINE __forceinline
#elif defined(__MINGW32__)
#   if !defined(FORCEINLINE)
#       define FORCEINLINE __inline
#   endif
#else
#   define FORCEINLINE __inline
#endif

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef int int32;
typedef short int16;
typedef char int8;
#ifdef _MSC_VER
typedef unsigned __int64 uint64;
typedef __int64 int64;
#else
typedef unsigned long long uint64;
typedef long long int64;
#endif

    typedef unsigned char uchar;
    typedef unsigned short ushort;
    typedef unsigned int uint;
	typedef unsigned long ulong;
	
/////////////////////////////////////////////////////////
#  if defined( __MINGW32__ )
#    include <unistd.h>
#  endif

#ifdef __GNUC__
#   if GCC_VERSION >= 430
#       include <tr1/unordered_map>
#       include <tr1/unordered_set> 
#   else
#       include <ext/hash_map>
#       include <ext/hash_set>
#   endif
#else 
#	ifdef _MSC_VER
#		if _MSC_VER >= 1600
#   		include <hash_set>
#   		include <hash_map>
#		else
#   		include <hash_set>
#   		include <hash_map>
#		endif
#	endif
#endif 


#ifdef __GNUC__
#   if GCC_VERSION >= 430
#       define HashMap ::std::tr1::unordered_map
#		define HashSet ::std::tr1::unordered_set
#    else
#       define HashMap ::__gnu_cxx::hash_map
#       define HashSet ::__gnu_cxx::hash_set
#    endif
#else
#   ifdef _MSC_VER
#       if _MSC_VER >= 1600 // VC++ 10.0
#			define HashMap ::std::tr1::unordered_map
#           define HashSet ::std::tr1::unordered_set
#		elif _MSC_VER > 1300 && !defined(_STLP_MSVC)
#           define HashMap ::stdext::hash_map
#           define HashSet ::stdext::hash_set
#       else
#           define HashMap ::std::hash_map
#           define HashSet ::std::hash_set
#       endif
#   else
#       define HashMap ::std::hash_map
#       define HashSet ::std::hash_set
#   endif
#endif