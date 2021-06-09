#pragma region j call
#define j_malloc   ((void*(*)(size_t))0x1417ACBCE) 
#define j_Sleep ((void*(*)(__int64))0x1400A2A80) //import: "Sleep" ->j_Sleep

#define j_free                  ((void*(*)(void*))0x1417ACBC8) 

#define j_memcpy                ((void*(*)(void*, void const*, size_t))0x1417ACA7E) 

#define j_memset                ((void*(*)(void*, int, size_t))0x1417ACA8A) 

#define zero_memory(dst, size)  j_memset(dst, 0, size) 

#define j_get_async_key_state   ((int(*)(int))0x1400A2B60) // j_GetAsyncKeyState
#pragma endregion


#pragma region offsets

enum game_data : __int64
{
	m_system_global = 0x141E62C98, //->
	m_gameframework = 0x14217C278, //->
	m_cvar = 0x14217B5C8, //->
	m_entity_system = 0xE0, //->
	m_system = 0xF0, //->
	m_i3d_engine = 0x100 //->
};

enum virtual_data : __int32
{
	m_get_entity_iterator = 0xA8,
	m_get_actor = 0x78,
	m_set_hudsilhouettes_params = 0x160,
	m_get_proxy = 0x1D8,
	m_get_client_actor = 0x470
};

enum entity_data : __int32
{
	m_set_render_flags = 0x24
};

enum actor_data : __int32
{
	m_get_entity = 0x10,
	m_get_actor_id = 0x20
};

enum game_frame_work_data
{
	m_get_actor_system = 0x04E0
};

enum cvar_data
{
	m_i_rotation_yaw = 0x110,
	m_i_rotation_pitch = 0x114,
	m_i_rotation_roll = 0x118,
	m_ñl_fov = 0x4,
	m_i_pelletsDisp = 0x130,
	m_g_parametric_recoil_random_enabled = 0x250,
	m_g_parametric_spread_attack_enabled = 0x254
};

#pragma endregion
