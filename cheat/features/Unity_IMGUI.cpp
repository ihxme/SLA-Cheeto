#include "Unity_IMGUI.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"

namespace Cheat::Features
{

	Unity_IMGUI::Unity_IMGUI()
	{
		HookManager::install(app::NeoLODDynamic_OnEnable, NeoLODDynamic_OnEnable_Hook);
	}

	void Unity_IMGUI::NeoLODDynamic_OnEnable_Hook(void* __this, MethodInfo* method)
	{
		SAFE_BEGIN();
		OnGui();
		SAFE_EEND();
		CALL_ORIGIN(NeoLODDynamic_OnEnable_Hook, __this, method);
	}

	void Unity_IMGUI::OnGui()
	{
		auto windowRect = app::Rect(100, 100, 200, 150);

		void* methodPtr = reinterpret_cast<void*>(&Draw);
		auto windowFunc = new app::GUI_WindowFunction();
		// app::GUI_WindowFunction__ctor(windowFunc, reinterpret_cast<app::Object*>())
		// app::GUI_Window(74164, windowRect, Draw, string_to_il2cppi("Solo Leveling:ARISE Cheat"), nullptr);

	}

	void Unity_IMGUI::Draw()
	{

	}
}
