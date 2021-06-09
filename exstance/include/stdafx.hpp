
#pragma once
#define WIN32_LEAN_AND_MEAN  // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows

#include <windows.h>
#include <thread>


#include "../alternativecrt/mincrt.h"

#pragma region gamesdk
#include "../gamesdk/offsets.hpp"

#include "../gamesdk/define.hpp"

#include "../gamesdk/struct.hpp"

#include "../gamesdk/glow.hpp"

#pragma endregion

#include "../hook/cvmthook.hpp"

#include "../nimport/limporter.hpp"


void* __cdecl operator new(size_t size)
{
	return static_cast<void*>(j_malloc(size));
}
void operator delete(void* p)
{
	if (p != NULL)
		j_free(p);
}
void* __cdecl operator new[](size_t n)
{
	return operator new(n);
}
void  __cdecl operator delete[](void* p)
{
	operator delete(p);
}
void  __cdecl operator delete[](void* p, size_t)
{
	operator delete[](p);
}
