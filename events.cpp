#include "events.h"

using namespace irr;

bool EventManager::OnEvent(const SEvent& event) {
     switch(event.EventType) {
     case EET_KEY_INPUT_EVENT :
	       for(ActionIter i = m_actions.begin();
		   i != m_actions.end();
		   i ++) {
		    if(i->key == event.KeyInput.Key)
			 (i->callback)();
	       }    
	       break;
     default:
	  break;
     }
     return false;
}

void EventManager::bind_action_to_key(Action& action) {
     m_actions.push_back( action );
}


