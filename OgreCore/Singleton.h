/*
		Ogre3D (http://www.ogre3d.org) and 
		Game.Programming.Gems-1 and 
		Thinking in C++ II (v2)

			lyricc
		
*/

#ifndef _SINGLE_TON_H_
#define _SINGLE_TON_H_
#include <assert.h>
template <typename T> class Singleton
    {
	private:
		/** \brief Explicit private copy constructor. This is a forbidden operation.*/
		Singleton(const Singleton<T> &);

		/** \brief Private operator= . This is a forbidden operation. */
		Singleton& operator=(const Singleton<T> &);
    
	protected:

        static T* msSingleton;

    public:
        Singleton( void )
        {
            assert( !msSingleton );
#if defined( _MSC_VER ) && _MSC_VER < 1200	 
            int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
            msSingleton = (T*)((int)this + offset);
#else
	    msSingleton = static_cast< T* >( this );
#endif
        }
        ~Singleton( void )
            {  assert( msSingleton );  msSingleton = 0;  }
        static T& getSingleton( void )
		{	assert( msSingleton );  return ( *msSingleton ); }
        static T* getSingletonPtr( void )
		{ return msSingleton; }
    };

// ??
//template<typename T> T*Singleton<typename T> ::msSingleton = 0;

//
// another version from Thinking in c++
//

template<class T>
class SingleTon
{
private:
	SingleTon(const SingleTon&);
	SingleTon& operator=(const SingleTon&);
protected:
	SingleTon(){};
	virtual ~SingleTon(){}
public:
	static T& getSingleton()
	{
		static T singleton;
		return singleton;
	}
};

#endif