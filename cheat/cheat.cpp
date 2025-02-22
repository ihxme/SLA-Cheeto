#include "cheat.h"
#include "ModuleManager.h"
#include "global.h"

#include "features/PlayerSpeed.h"
#include "features/NoCooldown.h"
#include "features/DamageHack.h"
#include "features/DumbEnemies.h"
#include "features/InfiniteMissionTime.h"
#include "features/TimeScale.h"

using namespace Cheat::Features;

void init_cheat()
{
	auto& manager = ModuleManager::GetInstance();

#define REGISTER(Class) ModuleManager::GetInstance().RegisterModule(std::make_unique<Class>());
	REGISTER(PlayerSpeed);
	REGISTER(NoCooldown);
	REGISTER(DamageHack);
	REGISTER(DumbEnemies);
	REGISTER(InfiniteMissionTime);
	REGISTER(TimeScale);
#undef REGISTER

	manager.LoadAllModules();
}

void run_cheat()
{
	SAFE_BEGIN();
	ModuleManager::GetInstance().UpdateAllModules();
	SAFE_EEND();
}
