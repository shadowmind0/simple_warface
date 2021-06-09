bool is_valid_team(i_actor* m_actor, i_actor* p_actor)
{
	return ((m_actor->get_team_id() != p_actor->get_team_id() || p_actor->get_team_id() == 0) && (p_actor != m_actor));
}
void __fastcall glow_update()
{
	i_system_global* p_global = i_system_global::singleton();
	if (!null_ptr(p_global))
		return;

	i_game_frame_work* p_game_framework = i_game_frame_work::singleton();
	if (!null_ptr(p_game_framework))
		return;

	i_entity_system* p_entity_system = p_global->get_entity_system();
	if (!null_ptr(p_entity_system))
		return;

	i_actor_system* p_actor_system = p_game_framework->get_actor_system();
	if (!null_ptr(p_actor_system))
		return;

	i_actor* p_lc_actor;
	if (p_game_framework->get_client_actor(&p_lc_actor))
	{
		i_entity_map_it* p_entity_iteartor = p_entity_system->get_entity_iterator();
		while (i_entity* p_entity = p_entity_iteartor->next()){

			if (i_actor* p_enemy_actor = p_actor_system->get_actor(p_entity->get_entity_id())){
				
				if (auto proxy_render = p_enemy_actor->get_entity()->get_proxy(e_entity_proxy::entity_proxy_render))
				{
					if (GetKeyState(VK_F2)) 	{
						proxy_render->set_render_flags(0x80018);
						proxy_render->set_hudsilhouettes_params(0.f, 1.f, 0.f, 0.f);
					}
				}
			}
		}
	}
}