#include "action.hh"

MyActionInitialization::MyActionInitialization()
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);

    MyRunAction *runAction = new MyRunAction();
    SetUserAction(runAction);

    EventAction *eventAction = new EventAction();
    SetUserAction(eventAction);
    //simulation::EventAction *eventAction = new simulation::EventAction();
    //SetUserAction(eventAction);
}
