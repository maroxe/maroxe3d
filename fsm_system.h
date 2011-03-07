#ifndef DEF_FSM_SYSTEM
#define DEF_FSM_SYSTEM

#include <list>

class State {
public:
     
     virtual void start() = 0;
     virtual bool update() = 0;
     virtual void pause() = 0;
     virtual void unpause() = 0;
     virtual void stop() = 0;
     virtual ~State() = 0;
};

typedef std::list<State*> StateList;
typedef StateList::iterator StateIter;

class StateManager {
public:
     StateManager();

     void loop();
     bool update();
     
     void pop_state();
     void push_state(State* state);
     bool empty();     

     ~StateManager();
     
protected:
     StateList m_states;
};

#endif


