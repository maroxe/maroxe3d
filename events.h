#ifndef DEF_EVENT_MANAGER
#define DEF_EVENT_MANAGER

#include <list>
#include <boost/function.hpp>
#include <irrlicht/irrlicht.h> 

struct Action {
     irr::EKEY_CODE key;
     boost::function< void () > callback;
};

typedef std::list<Action> ActionList;
typedef ActionList::iterator ActionIter;

class EventManager : irr::IEventReceiver {
public:
     //EventManager();
     virtual bool OnEvent(const irr::SEvent& event);
     void bind_action_to_key(Action& action);
     
protected:
     ActionList m_actions;
};

#endif

