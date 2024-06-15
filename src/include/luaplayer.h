#ifndef __LUAPLAYER_H
#define __LUAPLAYER_H

#include <debug.h>
#if !(__STDC__)
#define bool unsigned char
#define true 1
#define false 0
#elif (__STDC_VERSION__ >= 199901L) || !(__STDC_VERSION__ >= 202311L )
#include <stdbool.h>
#endif

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

extern char boot_path[255];

#ifdef DEBUG
#define dbgprintf(args...) scr_printf(args)
#else
#define dbgprintf(args...) ;
#endif

int getBootDevice(void);

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define CLAMP(val, min, max) ((val)>(max)?(max):((val)<(min)?(min):(val)))

#define ASYNC_TASKS_MAX 1

extern size_t GetFreeSize(void);

extern const char * runScript(const char* script, bool isStringBuffer);
extern void luaC_collectgarbage (struct lua_State *L);

extern void luaControls_init(struct lua_State *L);
extern void luaGraphics_init(struct lua_State *L);
extern void luaScreen_init(struct lua_State *L);
extern void luaTimer_init(struct lua_State *L);
extern void luaSystem_init(struct lua_State *L);
extern void luaSound_init(struct lua_State *L);
extern void luaRender_init(struct lua_State *L);
#ifdef PS2KBD
extern void luaKeyboardInit(struct lua_State *L);
#endif
extern void stackDump (struct lua_State *L);

#endif

