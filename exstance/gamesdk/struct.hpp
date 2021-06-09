
class i_system_global
{
public:
	static i_system_global* singleton()
	{
		return *(i_system_global**)game_data::m_system_global;
	}

	i_entity_system* get_entity_system()
	{
		return (i_entity_system*)*(__int64*)((__int64)this + game_data::m_entity_system);
	}
	i_system* get_system()
	{
		return (i_system*)*(__int64*)((__int64)this + game_data::m_system);
	}
};
class i_cvar
{
public:
	template <class T>
	inline VOID set_value(DWORD64 offset, T value)
	{
		*(T*)((DWORD64)this + offset) = value;
	}
	template <class T>
	inline T get_value(DWORD64 offset)
	{
		return *(T*)((DWORD64)this + offset);
	}

	static i_cvar* singleton()
	{
		return *(i_cvar**)game_data::m_cvar;
	}

};

class i_entity_system
{
public:
	i_entity_map_it* get_entity_iterator()
	{
		return virtual_indx<i_entity_map_it* (__thiscall*)(PVOID)>(this, virtual_data::m_get_entity_iterator)(this);
	}
};

class i_entity_map_it
{
public:
	virtual ~i_entity_map_it() = 0;
	virtual void add_ref() = 0;
	virtual void release() = 0;
	virtual void move_first() = 0;
	virtual bool is_end() = 0;
	virtual i_entity* his() = 0;
	virtual i_entity* next() = 0;


};

class i_actor_system
{
public:
	i_actor* get_actor(__int32 entity_id)
	{
		return virtual_indx<i_actor* (__thiscall*)(PVOID, __int32)>(this, virtual_data::m_get_actor)(this, entity_id);
	}
};

class i_entity
{
public:
	__int32 get_entity_id()
	{
		return *(__int32*)((__int64)this + 0x18);
	}

	i_entity_proxy* get_proxy(e_entity_proxy proxy)
	{
		return virtual_indx<i_entity_proxy* (__thiscall*)(PVOID, e_entity_proxy)>(this, virtual_data::m_get_proxy)(this, proxy);
	}
};

class i_entity_proxy
{
public:
	void set_render_flags(__int32 flag)
	{
		*(__int32*)((__int64)this + entity_data::m_set_render_flags) = flag;
	}

	void set_hudsilhouettes_params(float r, float g, float b, float a)
	{
		return virtual_indx<void(__thiscall*)(PVOID, float, float, float, float)>(this, virtual_data::m_set_hudsilhouettes_params)(this, r, g, b, a);
	}
};

class i_actor
{
public:
	entity_id get_trigger_id()
	{
		DWORD64 offset_0 = *(DWORD64*)(DWORD64(this + 0x18));
		if (!offset_0)
			return 0;
		DWORD64 offset_1 = *(DWORD64*)(DWORD64(offset_0 + 0x60));
		if (!offset_1)
			return 0;
		DWORD64 offset_2 = *(DWORD64*)(DWORD64(offset_1 + 0x20));
		if (!offset_2)
			return 0;

		return *(entity_id*)(DWORD64(offset_2 + 0x170));
	}
	int32 get_health()
	{
		return virtual_indx<int32(__fastcall*)(PVOID)>(this, 0xD8)(this);
	}

	bool is_alive()
	{
		return get_health() > 0;

	}
	i_entity* get_entity()
	{
		return *(i_entity**)((__int64)this + actor_data::m_get_entity);
	}
	int32 get_team_id()
	{
		return *(int32*)((int64)this + 0x3E0);
	}
	__int32 get_actor_id()
	{
		return *(__int32*)((__int64)this + actor_data::m_get_actor_id);
	}
};

class i_game_frame_work
{
public:
	static i_game_frame_work* singleton()
	{
		return *(i_game_frame_work**)game_data::m_gameframework;
	}
	
	i_actor_system* get_actor_system()
	{
		return *(i_actor_system**)((__int64)this + game_frame_work_data::m_get_actor_system);
	}
	i_game_rules* get_game_rules()
	{
		return virtual_indx<i_game_rules* (__fastcall*)(PVOID)>(this, (0x448))(this);
	}
	bool get_client_actor(i_actor** p_actor)
	{
		return virtual_indx<bool(__thiscall*)(PVOID, i_actor**)>(this, virtual_data::m_get_client_actor)(this, p_actor);
	}
};

class i_game_rules
{
public:
	int64 get_team(uint64 entityId) {
		return virtual_indx<__int64(__fastcall*)(PVOID, uint64)>(this, (0x368))(this, entityId);
	}
};