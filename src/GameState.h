#pragma once

#include "./OPengine.h"

class ExampleState : public OPgameState {

	OPjavaScriptV8Compiled SCRIPT;

    void Init(OPgameState* last);
    OPint Update(OPtimer* time);
    void Render(OPfloat delta);
    OPint Exit(OPgameState* next);
public:
	void Wrap(Handle<Object> exports);
	static void Wrapper(Handle<Object> exports);
};

extern ExampleState GS_EXAMPLE;
