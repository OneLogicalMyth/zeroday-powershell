// Triggers the XPS printer by creating a print job - @OneLogicalMyth
// Compile with /MT
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <xpsobjectmodel.h>
#include <xpsprint.h>
using namespace std;

#pragma comment(lib, "xpsprint.lib") 
#pragma warning( disable : 4995 )
int main()
{
	CoInitialize(nullptr);
	IXpsOMObjectFactory *xpsFactory = NULL;
	CoCreateInstance(__uuidof(XpsOMObjectFactory), NULL, CLSCTX_INPROC_SERVER, __uuidof(IXpsOMObjectFactory), reinterpret_cast<LPVOID*>(&xpsFactory));
	HANDLE completionEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	IXpsPrintJob *job = NULL;
	IXpsPrintJobStream *jobStream = NULL;
	StartXpsPrintJob(L"Microsoft XPS Document Writer", L"Print Job 1", NULL, NULL, completionEvent, NULL, 0, &job, &jobStream, NULL);
	jobStream->Close();
	CoUninitialize();
}
