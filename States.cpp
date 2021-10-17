//
// Created by chuning liu on 4/2/21.
//

#include "States.h"

bool States::checkEnable(ObjectState state)//Check if a particular state is enabled
{
    if (states.count(state) > 0) {
        return !states[DISABLED];
    }

    return false;
}

void States::EnableState(ObjectState state) //change state to enable
{
    states[state] = true;
}

void States::DisableState(ObjectState state) //change state to disable
{
    states[state] = false;
}

std::map<ObjectState, bool> States::getStates() {
    return states;
}

void States::setStates(ObjectState objectState, bool change) {
    states[objectState] = change;
}

std::map<ObjectState, bool> States::getStates() const {
    return states;
}
