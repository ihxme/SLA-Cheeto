#pragma once
#include "ModuleManager.h"
#include "global.h"

namespace Cheat::Features
{
	class Unity_IMGUI : public Module
	{
	public:
		Unity_IMGUI();

		void Load() override {}
		void Update() override {}

	private:
		static void OnGui();
		static void Draw();

		static void NeoLODDynamic_OnEnable_Hook(void* __this, MethodInfo* method);
	};
}
