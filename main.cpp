#include "states.h"

int main() {
     StateManager smgr;
     smgr.push_state(new GameState);
     smgr.loop();
     return 0;
}
	
