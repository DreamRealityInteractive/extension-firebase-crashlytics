#define LIB_NAME "FirebaseCrashlytics"
#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/dlib/log.h>
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_ANDROID) || defined(DM_PLATFORM_IOS)


static int FirebaseCrashlytics_Crash(lua_State* L) {
	DM_LUA_STACK_CHECK(L, 0);

	int *ptr = NULL;
    *ptr = 0;

	return 0;
}

static void LuaInit(lua_State* L) {
	DM_LUA_STACK_CHECK(L, 0);

	lua_pushstring(L, "crashlytics");
	lua_newtable(L);
	lua_pushtablestringfunction(L, "crash", FirebaseCrashlytics_Crash);

	lua_settable(L, -3);

	lua_pop(L, 1); // pop "firebase" global table
}

#endif


dmExtension::Result InitializeFirebaseCrashlyticsExtension(dmExtension::Params* params) {
	#if !defined(DM_PLATFORM_ANDROID) && !defined(DM_PLATFORM_IOS)
	dmLogInfo("Extension %s is not supported", LIB_NAME);
	#else
	LuaInit(params->m_L);
	#endif
	return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(FirebaseCrashlytics, LIB_NAME, 0, 0, InitializeFirebaseCrashlyticsExtension, 0, 0, 0)
