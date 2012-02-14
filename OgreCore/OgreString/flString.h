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
#ifndef _String_H__
#define _String_H__
#define OGRE_AUTO_MUTEX
#define OGRE_LOCK_AUTO_MUTEX
#define OGRE_MUTEX(name)
#define OGRE_STATIC_MUTEX(name)
#define OGRE_STATIC_MUTEX_INSTANCE(name)
#define OGRE_LOCK_MUTEX(name)
#define OGRE_LOCK_MUTEX_NAMED(mutexName, lockName)
#define OGRE_AUTO_SHARED_MUTEX
#define OGRE_LOCK_AUTO_SHARED_MUTEX
#define OGRE_NEW_AUTO_SHARED_MUTEX
#define OGRE_DELETE_AUTO_SHARED_MUTEX
#define OGRE_COPY_AUTO_SHARED_MUTEX(from)
#define OGRE_SET_AUTO_SHARED_MUTEX_NULL
#define OGRE_MUTEX_CONDITIONAL(name) if(true)
#define OGRE_RW_MUTEX(name)
#define OGRE_LOCK_RW_MUTEX_READ(name)
#define OGRE_LOCK_RW_MUTEX_WRITE(name)
#define OGRE_THREAD_SYNCHRONISER(sync) 
#define OGRE_THREAD_WAIT(sync, lock) 
#define OGRE_THREAD_NOTIFY_ONE(sync) 
#define OGRE_THREAD_NOTIFY_ALL(sync) 
#define OGRE_THREAD_POINTER(T, var) T* var
#define OGRE_THREAD_POINTER_INIT(var) var(0)
#define OGRE_THREAD_POINTER_VAR(T, var) T* var = 0
#define OGRE_THREAD_POINTER_SET(var, expr) var = expr
#define OGRE_THREAD_POINTER_GET(var) var
#define OGRE_THREAD_POINTER_DELETE(var) { OGRE_DELETE var; var = 0; }
#define OGRE_THREAD_SLEEP(ms)
#define OGRE_THREAD_WORKER_INHERIT

#include "../DLLib.h"

//#include "OgrePrerequisites.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <map>
// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>
using namespace std;

//#include "OgrePrerequisites.h
#if WCHAR_T_STRINGS
typedef std::wstring _StringBase;
#else
typedef std::string _StringBase;
#endif


#if WCHAR_T_STRINGS
typedef std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > _StringStreamBase;
#else
typedef std::basic_stringstream<char,std::char_traits<char>,std::allocator<char> > _StringStreamBase;
#endif
typedef _StringStreamBase StringStream;

typedef _StringBase String;
typedef _StringStreamBase StringStream;
typedef StringStream stringstream;

//typedef vector<String>::type StringVector;
typedef vector<String>  StringVector;



/** \addtogroup Core
*  @{
*/
/** \addtogroup General
*  @{
*/
/** Utility class for manipulating Strings.  */
class StringUtil
{
public:
	typedef StringStream StrStreamType;

	/** Removes any whitespace characters, be it standard space or
	TABs and so on.
	@remarks
	The user may specify wether they want to trim only the
	beginning or the end of the String ( the default action is
	to trim both).
	*/
	static void trim( String& str, bool left = true, bool right = true );

	/** Returns a StringVector that contains all the substrings delimited
	by the characters in the passed <code>delims</code> argument.
	@param
	delims A list of delimiter characters to split by
	@param
	maxSplits The maximum number of splits to perform (0 for unlimited splits). If this
	parameters is > 0, the splitting process will stop after this many splits, left to right.
	@param
	preserveDelims Flag to determine if delimiters should be saved as substrings
	*/
	static vector<String>  split( const String& str, const String& delims = "\t\n ", unsigned int maxSplits = 0, bool preserveDelims = false);

	/** Returns a StringVector that contains all the substrings delimited
	by the characters in the passed <code>delims</code> argument, 
	or in the <code>doubleDelims</code> argument, which is used to include (normal) 
	delimeters in the tokenised string. For example, "strings like this".
	@param
	delims A list of delimiter characters to split by
	@param
	delims A list of double delimeters characters to tokenise by
	@param
	maxSplits The maximum number of splits to perform (0 for unlimited splits). If this
	parameters is > 0, the splitting process will stop after this many splits, left to right.
	*/
	static vector<String> tokenise( const String& str, const String& delims = "\t\n ", const String& doubleDelims = "\"", unsigned int maxSplits = 0);

	/** Lower-cases all the characters in the string.
	*/
	static void toLowerCase( String& str );

	/** Upper-cases all the characters in the string.
	*/
	static void toUpperCase( String& str );


	/** Returns whether the string begins with the pattern passed in.
	@param pattern The pattern to compare with.
	@param lowerCase If true, the start of the string will be lower cased before
	comparison, pattern should also be in lower case.
	*/
	static bool startsWith(const String& str, const String& pattern, bool lowerCase = true);

	/** Returns whether the string ends with the pattern passed in.
	@param pattern The pattern to compare with.
	@param lowerCase If true, the end of the string will be lower cased before
	comparison, pattern should also be in lower case.
	*/
	static bool endsWith(const String& str, const String& pattern, bool lowerCase = true);

	/** Method for standardising paths - use forward slashes only, end with slash.
	*/
	static String standardisePath( const String &init);
	/** Returns a normalized version of a file path
	This method can be used to make file path strings which point to the same directory  
	but have different texts to be normalized to the same text. The function:
	- Transforms all backward slashes to forward slashes.
	- Removes repeating slashes.
	- Removes initial slashes from the beginning of the path.
	- Removes ".\" and "..\" meta directories.
	- Sets all characters to lowercase (if requested)
	@param init The file path to normalize.
	@param makeLowerCase If true, transforms all characters in the string to lowercase.
	*/
	static String normalizeFilePath(const String& init, bool makeLowerCase = true);


	/** Method for splitting a fully qualified filename into the base name
	and path.
	@remarks
	Path is standardised as in standardisePath
	*/
	static void splitFilename(const String& qualifiedName,
		String& outBasename, String& outPath);

	/** Method for splitting a fully qualified filename into the base name,
	extension and path.
	@remarks
	Path is standardised as in standardisePath
	*/
	static void splitFullFilename(const String& qualifiedName, 
		String& outBasename, String& outExtention, 
		String& outPath);

	/** Method for splitting a filename into the base name
	and extension.
	*/
	static void splitBaseFilename(const String& fullName, 
		String& outBasename, String& outExtention);


	/** Simple pattern-matching routine allowing a wildcard pattern.
	@param str String to test
	@param pattern Pattern to match against; can include simple '*' wildcards
	@param caseSensitive Whether the match is case sensitive or not
	*/
	static bool match(const String& str, const String& pattern, bool caseSensitive = true);


	/** replace all instances of a sub-string with a another sub-string.
	@param source Source string
	@param replaceWhat Sub-string to find and replace
	@param replaceWithWhat Sub-string to replace with (the new sub-string)
	@returns An updated string with the sub-string replaced
	*/
	static const String replaceAll(const String& source, const String& replaceWhat, const String& replaceWithWhat);

	/// Constant blank string, useful for returning by ref where local does not exist
	static const String BLANK;
};

#if 0
#ifdef __GNUC__ 
#   if GCC_VERSION < 430
typedef ::__gnu_cxx::hash< _StringBase > _StringHash;
#   else
typedef ::std::tr1::hash< _StringBase > _StringHash;
#   endif
#elif OGRE_COMPILER == OGRE_COMPILER_MSVC && OGRE_COMP_VER >= 1600 && !defined(STLPORT) // VC++ 10.0
typedef ::std::tr1::hash< _StringBase > _StringHash;
#elif !defined( _STLP_HASH_FUN_H )
typedef stdext::hash_compare< _StringBase, std::less< _StringBase > > _StringHash;
#else
typedef std::hash< _StringBase > _StringHash;
#endif 
#endif
#endif // _String_H__
