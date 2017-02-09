#include "./GameState.h"


void ExampleState::Init(OPgameState* last) {
	SCOPE_AND_ISOLATE;


	SCRIPT = OPjavaScriptV8Compiled("main.js");

	Handle<Context> localContext = Local<Context>::New(isolate, V8CONTEXT);
	v8::Context::Scope context_scope(localContext);

	Handle<Object> gameLevelObject = JS_NEW_OBJECT();
	Wrap(gameLevelObject);
	Handle<Value> gameLevelValue = gameLevelObject;
	SCRIPT.Function("GameInit", 1, &gameLevelValue);
}


OPint ExampleState::Update(OPtimer* time) {
	return false;
}

void ExampleState::Render(OPfloat delta) {
	OPrenderClear(0, 0, 0, 1);
	OPrenderPresent();
}

OPint ExampleState::Exit(OPgameState* next) {
	return 0;
}


JS_RETURN_VAL _ExampleStateCreate(const JS_ARGS& args) {
	SCOPE_AND_ISOLATE;

	ExampleState* state = OPNEW(ExampleState());
	Handle<Object> obj = JS_NEW_OBJECT();
	state->Wrap(obj);

	JS_RETURN(obj);
}

JS_HELPER_SELF_WRAPPER(_ExampleStateInit) {
	SCOPE_AND_ISOLATE;

	ExampleState* ptr = JS_NEXT_ARG_AS(ExampleState);

	//ptr->Init();

	JS_RETURN_NULL;
}

void ExampleState::Wrap(Handle<Object> result) {
	JS_SET_PTR(result, this);
	JS_SET_METHOD(result, "Init", _ExampleStateInitSelf);
}

void ExampleState::Wrapper(Handle<Object> exports) {
	SCOPE_AND_ISOLATE;

	Local<FunctionTemplate> tpl = JS_NEW_FUNCTION_TEMPLATE(_ExampleStateCreate);
	Handle<Object> result = tpl->GetFunction();

	JS_SET_NUMBER(result, "size", sizeof(ExampleState));
	JS_SET_OBJECT(exports, "ExampleState", result);
}


ExampleState GS_EXAMPLE;
