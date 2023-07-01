#include <iostream>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
#define LUA_EXPORT __declspec(dllexport)

	constexpr auto MODO_DEBUG = false;

	static int square_c(lua_State* L) {
		if (MODO_DEBUG)
			std::cout << "--- Funcao square_c ---" << std::endl;

		auto num = lua_tonumber(L, -1);
		lua_pushnumber(L, num * num);
		return 1;
	}

	static int soma_sub_c(lua_State* L) {
		if (MODO_DEBUG)
			std::cout << "--- Funcao soma_sub_c ---" << std::endl;

		auto a = lua_tonumber(L, -2);
		auto b = lua_tonumber(L, -1);
		lua_pushnumber(L, a+b);
		lua_pushnumber(L, a-b);

		return 2;
	}

	static int fibonacci_c(lua_State* L) {
		if (MODO_DEBUG)
			std::cout << "--- Funcao fibonacci_c ---" << std::endl;

		auto n = lua_tonumber(L, -1);
		if (n == NULL || n < 0)
			lua_pushnumber(L, NULL);
		else {
			double prod = 1;
			for (int i = 2; i <= n; i++)
				prod *= i;
			lua_pushnumber(L, prod);
		}

		return 1;
	}

	/*
	* Este é o "main" da DLL, seu posfixo deve ser o nome do arquivo.dll
	*/
	LUA_EXPORT int luaopen_funcoesLib(lua_State* L) {
		lua_register(L, "square", square_c);
		lua_register(L, "soma_sub", soma_sub_c);
		lua_register(L, "fibonacci", fibonacci_c);

		return 1;
	}
}