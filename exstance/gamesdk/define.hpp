
template <typename t>
t virtual_indx(PVOID f_base, __int64 f_index)
{
	return (*(t**)f_base)[f_index / 8];
}

template <typename t>
static bool null_ptr(t* ptr)
{
	return (ptr) ? true : false;
}

#pragma region define
class i_renderer;
class i_system;

class i_actor;
class i_actor_system;
class i_actor_iterator;

class i_entity_system;
class i_entity_map_it;
class i_entity;
class i_entity_proxy;
class i_entity_render_proxy;


class i_game_frame_work;
class i_game_rules;
class i_game_frame_work_listener;


#pragma endregion

enum e_entity_proxy
{
	entity_proxy_render,
	entity_proxy_physics,
	entity_proxy_script,
	entity_proxy_sound,
	entity_proxy_ai,
	entity_proxy_area,
	entity_proxy_boids,
	entity_proxy_boid_object,
	entity_proxy_camera,
	entity_proxy_flow_graph,
	entity_proxy_substitution,
	entity_proxy_trigger,
	entity_proxy_rope,
	entity_proxy_entity_node,
	entity_proxy_user,
	entity_proxy_last
};



#pragma region typedef
typedef unsigned int entity_id;
typedef signed char      int8;
typedef signed short     int16;
typedef signed int		 int32;
typedef signed __int64	 int64;
typedef unsigned char	 uint8;
typedef unsigned short	 uint16;
typedef unsigned int	 uint32;
typedef unsigned __int64 uint64;
typedef unsigned char _byte;
typedef float f32;
typedef double f64;
#pragma endregion