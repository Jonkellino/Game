#include "SDL/SDL_main.h"
#include "SDL/SDL.h"
#include "SDL\SDL_thread.h"
#include "EngineMessage.h"
#include "Engine.h"
#include "App.h"

volatile bool quit = false;
volatile bool logicDone = false;
volatile bool renderDone = false;

static void SynchronizeLogic() {
	while(!renderDone) {
		SDL_Delay(1);
	}
	Engine::GetInstance()->EndFrame();
	renderDone = false;
}
static void SynchronizeRender() {
	while(!logicDone) {
		SDL_Delay(1);
	}
	logicDone = false;
}

int logicThreadFunc(void* unused) {
	App* app = new App();
	while(true) {
		quit = app->Logic();
		logicDone = true;
		SynchronizeLogic();
	}
	delete app;
	quit = true;
	return 0;
}

int main( int argc, char* argv[]) { 
	Engine::Create();
	SDL_Thread* logicThread = SDL_CreateThread(logicThreadFunc, "logic", NULL);
	SDL_Event sdlEvent;
	while(!quit) {
		Engine::GetInstance()->Render();
		renderDone = true;
		SynchronizeRender();
		while(SDL_PollEvent(&sdlEvent)) {
			switch(sdlEvent.type) {
			case SDL_WINDOWEVENT:
				switch(sdlEvent.window.type) {
				case SDL_WINDOWEVENT_SIZE_CHANGED: {
					EngineMessage message = {EngineMessageType::WINDOW_SIZE_CHANGE};//, {event.window.data1, event.window.data2} };
					message.windowSizeChange.myWindowSize[0] = sdlEvent.window.data1;
					message.windowSizeChange.myWindowSize[1] = sdlEvent.window.data2;
					Engine::GetInstance()->NotifyMessage(message);
					break;
				}

				case SDL_WINDOWEVENT_CLOSE:  {
					sdlEvent.type = SDL_QUIT;
					SDL_PushEvent(&sdlEvent);
					break;
				}
				}
				break;
			case SDL_QUIT:
				quit = true;
				break;
			}
		}
	}
	return 0;
}