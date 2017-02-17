#pragma once
#include "PluginSDK.h"

bool VersionChecker()
{
	std::string szData;
	if (GPluginSDK->ReadFileFromURL("https://raw.githubusercontent.com/LordZEDith/Lords-AIO/master/Version%20Checker/Lords%20AIO.txt", szData))
	{
		auto n = szData.find("LocalVersion = ");

		if (n != szData.npos)
		{
			n += 15;
			szData = szData.substr(n, szData.size() - n);

		}

		auto k = szData.find(";");

		if (k != szData.npos)
			szData = szData.substr(0, k);

		auto dwGitVersion = atoi(szData.c_str());

		return (dwGitVersion <= 1); // Make sure the version on Git is either less to or equal to our version
	}

	return true; // Failed to read web page, just return true...
}

void RunVersionChecker()
{
	if (VersionChecker() == true)
	{
		GRender->NotificationEx(Color::LightBlue().Get(), 2, true, true, "You have latest Version");
	}
	else
	{
		GRender->NotificationEx(Color::LightBlue().Get(), 2, true, true, "You have an Old Version Go Download Latest Plugin");
	}
}

