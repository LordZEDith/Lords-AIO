#include "PluginSDK.h"
#include "TextHeader.h"
#include "Color.h"
#include "Lords Ahri.h"
#include "Lords Malphite.h"
#include "Lords Xerath.h"
#include "Lords Rengar.h"
#include "Lords Sona.h"
#include "Lords Diana.h"
#include "Lords Warwick.h"

#pragma region Events
PLUGIN_EVENT(void) OnOrbwalkBeforeAttack(IUnit* Target)
{

}

PLUGIN_EVENT(void) OnOrbwalkAttack(IUnit* Source, IUnit* Target)
{

}
#pragma endregion

PluginSetup("Lords AIO");
class IChampion
{
public:
	virtual void OnGameUpdate() = 0;
	virtual void AfterAttack(IUnit * Source, IUnit * Target) = 0;
	virtual void OnGapCloser(GapCloserSpell const& Args) = 0;
	virtual void OnRender() = 0;
	virtual void OnLoad() = 0;
	//virtual void unLoad() = 0;
};

class Ahr : public IChampion
{
public:
	virtual void OnLoad() override
	{
		MidLaneSeries();
		PrintAhriLoadMessage();
		Ahri().Menu();
		Ahri().LoadSpells();
	}
	virtual void OnRender() override
	{
		Ahri().Drawing();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Ahri().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			Ahri().Farm();
		}
	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	/*virtual void unLoad() override
	{
		Ahri().Menu();
		Ahri().LoadSpells();
	}*/
private:
	void PrintAhriLoadMessage()
	{
		GGame->PrintChat("Ahri detected...Loading script");
	}

};

class Malph : public IChampion
{
public:
	virtual void OnLoad() override
	{
		TopLaneSeries();
		MalphLoadMessage();
		Malphite().Menu();
		Malphite().LoadSpells();
	}
	virtual void OnRender() override
	{
		Malphite().Drawingss();
	}

	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Malphite().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			Malphite().Farm();
		}
		Malphite().Auto();

	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		Malphite().GapCloser(Args);
	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	/*virtual void unLoad() override
	{
		Malphite().Menu();
		Malphite().LoadSpells();
	}*/
private:
	void MalphLoadMessage()
	{
		GGame->PrintChat("Malphite detected...Loading script");
	}
};

class Xerat : public IChampion
{
public:
	virtual void OnLoad() override
	{
		MidLaneSeries();
		PrintXerathLoadMessage();
		Xerath().Menu();
		Xerath().LoadSpells();
	}
	virtual void OnRender() override
	{
		Xerath().Drawings();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Xerath().Combo();
		}
		Xerath().RunAlways();
		 
	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	/*virtual void unLoad() override
	{
		
		Xerath().Menu();
		Xerath().LoadSpells();
	}*/
private:
	void PrintXerathLoadMessage()
	{
		GGame->PrintChat("Xerath detected...Loading script");
	}

};

class Reng: public IChampion
{
public:
	virtual void OnLoad() override
	{
		JungleLaneSeries();
		MalphLoadMessage();
		Rengar().Menu();
		Rengar().LoadSpells();
	}
	virtual void OnRender() override
	{
		Rengar().Drawing();
	}

	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Rengar().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			Rengar().Farm();
		}
		 

	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{
		if (ComboAA->Enabled() && !(ComboA->Enabled()))
		{
			if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
			{
				Rengar().Combo();
			}
		}
	}
	/*virtual void unLoad() override
	{
		Rengar().Menu();
		Rengar().LoadSpells();
	}*/
private:
	void MalphLoadMessage()
	{
		GGame->PrintChat("Rengar detected...Loading script");
	}
};

class Son : public IChampion
{
public:
	virtual void OnLoad() override
	{
		SuppLaneSeries();
		SonaLoadMessage();
		Sona().Menu();
		Sona().LoadSpells();
	}
	virtual void OnRender() override
	{
		Sona().Drawing();
	}

	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Sona().Combo();
		}
		Sona().AutoW();


	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{
		 
	}
	/*virtual void unLoad() override
	{
		Rengar().Menu();
		Rengar().LoadSpells();
	}*/
private:
	void SonaLoadMessage()
	{
		GGame->PrintChat("Sona detected...Loading script");
	}
};

class Dian : public IChampion
{
public:
	virtual void OnLoad() override
	{
		JungleLaneSeries();
		MidLaneSeries();
		DianaLoadMessage();
		Diana().Menu();
		Diana().LoadSpells();
	}
	virtual void OnRender() override
	{
		Diana().Drawing();
	}

	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Diana().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			Diana().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			Diana().Farm();
		}
		if (R->IsReady())
		{
			Diana().ComboRKill1();
		}
		if (QEnemies1->Enabled())
		{
			Diana().AutoQ();
		}
		Diana().StealR();

	}
	
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		//Diana().GapCloser(Args);
	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	/*virtual void unLoad() override
	{
		 
		Diana().Menu();
		Diana().LoadSpells();
	}*/
private:
	void DianaLoadMessage()
	{
		GGame->PrintChat("Diana detected...Loading script");
	}
};

class War : public IChampion
{
public:
	virtual void OnLoad() override
	{
		JungleLaneSeries();
		WarwickLoadMessage();
		Warwick().Menu();
		Warwick().LoadSpells();
	}
	virtual void OnRender() override
	{
		Warwick().Drawing();
	}

	virtual void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Warwick().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			Warwick().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			Warwick().JungleClear();
		}

		//Warwick().AutoW();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
private:
	void WarwickLoadMessage()
	{
		GGame->PrintChat("Warwick detected...Loading script");
	}
};

 
IChampion* pChampion = nullptr;

PLUGIN_EVENT(void) OnRender()
{
	pChampion->OnRender();
}

PLUGIN_EVENT(void) OnGameUpdate()
{
	pChampion->OnGameUpdate();
}
PLUGIN_EVENT(void) OnGapCloser(GapCloserSpell const& Args)
{
	pChampion->OnGapCloser(Args);
}
PLUGIN_EVENT(void) AfterAttack(IUnit* Source, IUnit* Target)
{
	pChampion->AfterAttack(Source, Target);
}
void LoadChampion()
{
	std::string szChampion = GEntityList->Player()->ChampionName();

	if (szChampion == "Ahri")
		pChampion = new Ahr;
	else if (szChampion == "Malphite")
		pChampion = new Malph;
	else if (szChampion == "Xerath")
		pChampion = new Xerat;
	else if (szChampion == "Rengar")
		pChampion = new Reng;
	else if (szChampion == "Diana")
		pChampion = new Dian;
	else if (szChampion == "Warwick")
		pChampion = new War;
	else
	{
		GGame->PrintChat("Champion not supported!");
	}	
	if (pChampion != nullptr)
	{
		GEventManager->AddEventHandler(kEventOnRender, OnRender);
		GEventManager->AddEventHandler(kEventOnGapCloser, OnGapCloser);
		GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, AfterAttack);
		GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	}
}

// Called when plugin is first loaded
PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	// Initializes global interfaces for core access
	PluginSDKSetup(PluginSDK);

	LoadChampion();
	pChampion->OnLoad();
	GRender->NotificationEx(Color::LightBlue().Get(), 2, true, true, "Welcome to Lord's AIO");

	
}

// Called when plugin is unloaded
PLUGIN_API void OnUnload()
{
	 
		//pChampion->unLoad();
		MainMenu->Remove();
	//	GEventManager->RemoveEventHandler(kEventOnRender, OnLoad);
		GEventManager->RemoveEventHandler(kEventOnRender, OnRender);
		GEventManager->RemoveEventHandler(kEventOnGapCloser, OnGapCloser);
		GEventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, AfterAttack);
		GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
		
	
	
}

