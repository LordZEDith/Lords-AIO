#pragma once
#include "PluginSDK.h"
#include "Color.h"

void MidLaneSeries()
{
	GRender->NotificationEx(Color::LightRed().Get(), 2, true, true, ("Midlane Series Loaded"));
}
void TopLaneSeries()
{
	GRender->NotificationEx(Color::LightRed().Get(), 2, true, true, ("TopLane Series Loaded"));
}
void JungleLaneSeries()
{
	GRender->NotificationEx(Color::LightRed().Get(), 2, true, true, ("Jungle Series Loaded"));
}
void SuppLaneSeries()
{
	GRender->NotificationEx(Color::LightRed().Get(), 2, true, true, ("Support Series Loaded"));
}
void ADCLaneSeries()
{
	GRender->NotificationEx(Color::LightRed().Get(), 2, true, true, ("ADC Series Loaded"));
}