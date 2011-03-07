#include <list>
#include "fsm_system.h"


StateManager::StateManager() {
}

void StateManager::loop() {
     while(this->update());
}

bool StateManager::update() {
     bool last_state_quit = false;
     for(StateIter i = m_states.begin();
	 i != m_states.end();
	 ++i ) {
	  last_state_quit = ! (*i)->update();
     }
     if( last_state_quit ) this->pop_state();

     return !this->empty();
}

void StateManager::push_state(State* state) {
     if( ! this->empty() )
	  m_states.back()->pause();

     m_states.push_back(state);
     state->start();
}

void StateManager::pop_state() {
     if( ! this->empty() ) {
	  m_states.back()->stop();
	  m_states.pop_back();
     }
     if( ! this->empty() ) 
	  m_states.back()->unpause();

}

bool StateManager::empty() {
     return m_states.empty();
}

StateManager::~StateManager() {
     while ( ! this->empty() ) this->pop_state();
}

State::~State() {}
