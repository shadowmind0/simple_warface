#pragma once
class c_exst
{
public:
	c_exst()
	{
		j_memset(this, 0, sizeof(c_exst));
	}
	c_exst(PDWORD64* p_base)
	{
		invoke(p_base);
	}
	~c_exst()
	{
		unhook();
	}
	bool invoke(PDWORD64* p_base)
	{
		p_table = p_base;
		o_fun = *p_base;
		c_table = get_count(*p_base);
		n_fun = new DWORD64[c_table];
		j_memcpy(n_fun, o_fun, sizeof(DWORD64) * c_table);
		*p_base = n_fun;
		return true;
	}
	bool invoke(PDWORD64** p_base)
	{
		return invoke(*p_base);
	}
	void unhook()
	{
		if (p_table)
		{
			*p_table = o_fun;
		}
	}
	void rehook()
	{
		if (p_table)
		{
			*p_table = n_fun;
		}
	}
	DWORD64 setup(DWORD64 new_function, unsigned int i)
	{
		if (n_fun && o_fun && i <= c_table && i >= 0)
		{
			n_fun[i] = new_function;
			return o_fun[i];
		}
		return 0;
	}
private:
	DWORD get_count(PDWORD64 p_vmt)
	{
		DWORD i = 0;
		for (i = 0; p_vmt[i]; i++)
		{
			if (m_is_bad_code_ptr((FARPROC)p_vmt[i]))
				break;
		}
		return i;
	}
	DWORD	  c_table;
	PDWORD64* p_table;
	PDWORD64  n_fun;
	PDWORD64  o_fun;
};
