// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "..\include\stdafx.hpp"


typedef HRESULT(WINAPI* c_update)(i_system*, int, int);
c_update c_exst_upd;
c_exst* c_exst_hk = nullptr;


BOOL WINAPI  _update(i_system* upd_system, int flags, int pause_mode)
{
	glow_update();
	return c_exst_upd(upd_system, flags, pause_mode);
}
VOID  APIENTRY  _call() {
	j_Sleep((10000));
	LI_FN(Beep)(800, 800);
	c_exst_hk = new c_exst((PDWORD64*)i_system_global::singleton()->get_system());
	c_exst_upd = (c_update)c_exst_hk->setup((DWORD64)_update, 0x4);
}
BOOL APIENTRY entrypoint( HMODULE h_module,  DWORD  ul_reason_call,  LPVOID l_reserved       )
{

	UNREFERENCED_PARAMETER(h_module);
	UNREFERENCED_PARAMETER(l_reserved);
	if (ul_reason_call == DLL_PROCESS_ATTACH){
		Beep(123, 564);
		LI_FN(_beginthreadex)(nullptr, 0, (_beginthreadex_proc_type)_call, h_module, 0, nullptr);

	}
	else if (ul_reason_call == DLL_PROCESS_DETACH)	{
		c_exst_hk->unhook();
	}
    return TRUE;
}

