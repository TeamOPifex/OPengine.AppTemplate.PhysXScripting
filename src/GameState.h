#pragma once

#include "./OPengine.h"
#include "Player.h"

class GameState : public OPgameState {
	OPjavaScriptV8Compiled SCRIPT;
	OPscene scene;
	OPrendererForward rendererForward;

	Player* player;

    void Init(OPgameState* last);
    OPint Update(OPtimer* time);
    void Render(OPfloat delta);
    OPint Exit(OPgameState* next);
public:
	void Wrap(Handle<Object> exports);
	static void Wrapper(Handle<Object> exports);
};

extern GameState GS_EXAMPLE;
