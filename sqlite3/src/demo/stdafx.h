#ifndef __stdafx_h__
#define __stdafx_h__

// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifdef WIN32
#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <atlbase.h>
#include <atlstr.h>
#endif // WIN32

#include <sstream>
#include <assert.h>


#define INNOAUS_USE_DATABASE_SQLITE
#include <libinnoaus/innoaus-includes.h>

#endif /* __stdafx_h__ */
