#pragma once
#include "PluginSDK.h"
#include "BaseMenu.h"
 


	// Lord's Xerath.cpp : Defines the exported functions for the DLL application.


class Xerath
{
public:
	 
	void  Menu()
	{
		
		MainMenu = GPluginSDK->AddMenu("Lords Xerath");
		QMenu = MainMenu->AddMenu("Q Settings");
		WMenu = MainMenu->AddMenu("W Settings");
		EMenu = MainMenu->AddMenu("E Settings");
		RMenu = MainMenu->AddMenu("R Settings");
		Drawingss = MainMenu->AddMenu("Drawings");

		ComboQ = QMenu->CheckBox("Use Q", true);
		//FarmQ = QMenu->CheckBox("Use Q Farm", true);

		ComboW = WMenu->CheckBox("Use W", true);
		//FarmW = WMenu->CheckBox("Use W Farm", true);

		ComboE = EMenu->CheckBox("Use E", true);
		ComboEA = EMenu->CheckBox("Auto E when Enemy in Selected Range", true);
		HarassManaE = EMenu->AddFloat("Auto E Range ", 0, 525, 515);


		ComboR = RMenu->CheckBox("Use R(When u select it)", true);
		//ComboR2 = RMenu->CheckBox("Auto R when Enemy Killable", true);
		//HealthPercent = RMenu->AddInteger("Enemies Health %", 0, 100, 40);
		DrawReady = Drawingss->CheckBox("Draw Only Ready Spells", true);

		DrawQ = Drawingss->CheckBox("Draw Q", true);
		DrawW = Drawingss->CheckBox("Draw W", true);
		DrawE = Drawingss->CheckBox("Draw E", true);
		DrawEA = Drawingss->CheckBox("Draw Auto E Range", true);
	}
	void LoadSpells()
	{
		Q = GPluginSDK->CreateSpell2(kSlotQ, kLineCast, false, false, kCollidesWithNothing);
		Q->SetCharged(750.f, 1550.f, 1.5f); // Min range: 750 | Max range: 1550 | Total charge time: 3.0 seconds
		W = GPluginSDK->CreateSpell2(kSlotW, kCircleCast, false, true, static_cast<eCollisionFlags>(kCollidesWithNothing));
		E = GPluginSDK->CreateSpell2(kSlotE, kLineCast, true, false, static_cast<eCollisionFlags>(kCollidesWithMinions | kCollidesWithYasuoWall));
		R = GPluginSDK->CreateSpell2(kSlotR, kCircleCast, false, false, static_cast<eCollisionFlags>(kCollidesWithNothing));
		Q->SetOverrideRange(1550);
		W->SetOverrideRange(1100);
		E->SetOverrideRange(1050);
		//R->SetOverrideRange(675);
		Q->SetOverrideDelay(0.6f);
		W->SetOverrideDelay(0.7f);
		E->SetOverrideDelay(0.25f);
		//R->SetOverrideDelay(0.7f);
		Q->SetOverrideRadius(95);
		W->SetOverrideRadius(125);
		E->SetOverrideRadius(60);
		//R->SetOverrideRadius(130);
		E->SetOverrideSpeed(1400);
	}
	int GetEnemiesInRange(float range)
	{
		auto enemies = GEntityList->GetAllHeros(false, true);
		auto enemiesInRange = 0;

		for (auto enemy : enemies)
		{
			if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam())
			{
				auto flDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length();
				if (flDistance < range)
				{
					enemiesInRange++;
				}
			}
		}
		return enemiesInRange;
	}
	void Combo()
	{
		if (ComboQ->Enabled())
		{
			if (Q->IsReady())
			{
				auto target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());


				if (target != nullptr && !target->IsDead() && !target->IsInvulnerable()  && GetEnemiesInRange(1550) >= 1 && GEntityList->Player()->IsValidTarget(target, Q->Range()) )
				{
					Q->StartCharging();
				}

				if (Q->IsCharging())
				{
					target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
					//if (target != nullptr)

					Q->FindTarget(SpellDamage);
					Q->CastOnTarget(target, 5);
				}
			}
		}
		if (ComboW->Enabled())
		{
			if ( W->IsReady())
			{
				auto target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, W->Range());
				//	if (target != nullptr)

				W->CastOnTarget(target, 6);

			}
		}
		if (ComboE->Enabled())
		{
			if ( E->IsReady())
			{
				auto target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, E->Range());
				//	if (target != nullptr)

				E->CastOnTarget(target, 6);

			}
		}
	
	}

	void AutoE()
	{
		if (ComboEA->Enabled() && E->IsReady())
		{

			auto target = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, HarassManaE->GetFloat());
			//	if (target != nullptr)

			E->CastOnTarget(target,6);

		}
	}

	bool CastingR()
	{
		if (GEntityList->Player()->HasBuff("XerathLocusOfPower2") || GEntityList->Player()->HasBuff("XerathLocusPulse"))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void RunAlways()
	{
		if (R->IsReady() && ComboR->Enabled())
		{
			auto target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, R->Range());
			if (CastingR() == true)
			{
				R->CastOnTarget(target, 5);

			}
		}
	}

	void Drawings()
	{
		if (DrawReady->Enabled())
		{
			if (Q->IsReady() && DrawQ->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), Q->Range()); }

			if (E->IsReady() && DrawE->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), E->Range()); }

			if (E->IsReady() && DrawEA->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), HarassManaE->GetFloat()); }

			if (W->IsReady() && DrawW->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), W->Range()); }

		}
		else
		{
			if (DrawQ->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), Q->Range()); }

			if (DrawE->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), E->Range()); }

			if (DrawEA->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), HarassManaE->GetFloat()); }

			if (DrawW->Enabled()) { GRender->DrawOutlinedCircle(GEntityList->Player()->GetPosition(), Vec4(255, 255, 0, 255), W->Range()); }
			 
		}
	}
};