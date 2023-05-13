#pragma once
#include "HowTo.h"

class HowToReadText :
    public HowTo
{
public:
    HowToReadText();
    ~HowToReadText();

	void Run() override;

	bool Calculate() override;
};

