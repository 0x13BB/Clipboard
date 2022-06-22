#include "pch.h"
#include "Clipboard.h"

std::string Clipboard::GetData()
{
	OpenClipboard(nullptr);
	HANDLE data = GetClipboardData(CF_TEXT);
	char* buffer = static_cast<char*>(GlobalLock(data));
	std::string ss(buffer);
	GlobalUnlock(data);
	CloseClipboard();
	if (data != nullptr)
	{
		return ss;
	}
	else
	{
		return "NULL";
	}
}

void Clipboard::SetData(const std::string& textData)
{
	OpenClipboard(nullptr);
	EmptyClipboard();
	HANDLE data = GlobalAlloc(GMEM_MOVEABLE, textData.size() + 1);
	memcpy(GlobalLock(data), textData.c_str(), textData.size() + 1);
	GlobalUnlock(data);
	SetClipboardData(CF_TEXT, data);
	CloseClipboard();
}
