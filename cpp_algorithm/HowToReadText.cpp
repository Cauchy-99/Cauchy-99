#include "HowToReadText.h"
#include "ZWReadTreeDataCls.h"

HowToReadText::HowToReadText()
{

}

HowToReadText::~HowToReadText()
{

}

void HowToReadText::Run()
{
	ZWReadTreeDataCls* pClass = new ZWReadTreeDataCls();
	pClass->ReadData();
}

bool HowToReadText::Calculate()
{
	return true;
}
