#ifndef _NCX_LOCK_H_
#define _NCX_LOCK_H_

//#define __LOCK
#define __NONE_LOCK

#ifdef __LOCK

#ifdef _WIN32

#include <windows.h>

#define ncx_shmtx_init(x) { x.spin = CreateMutex(NULL, FALSE, NULL); }
#define ncx_shmtx_lock(x) { WaitForSingleObject(x.spin, INFINITE); }
#define ncx_shmtx_unlock(x) { ReleaseMutex(x.spin, INFINITE); }

typedef struct {

	HANDLE spin;

} ncx_shmtx_t;

#else

//TODO

#endif

#endif

#ifdef __NONE_LOCK

#define ncx_shmtx_init(x) { /*void*/ }
#define ncx_shmtx_lock(x) { /*void*/ }
#define ncx_shmtx_unlock(x) { /*void*/ }

typedef struct {

	ncx_uint_t spin;

} ncx_shmtx_t;

#endif

#endif //_NCX_LOCK_H_
