//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_STATES_H
#define PROJECT1SFMLTYPE_STATES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

using namespace std;
enum ObjectState {
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    BLINKING,
    ///This should always be the last state
    LASTSTATE,
};

class States {
public:
    States() {
        for (int i = 0; i < LASTSTATE; i++) {
            states[static_cast<ObjectState>(i)] = false;
        }
    }

    bool checkEnable(ObjectState state);//Check if a particular state is enabled
    void EnableState(ObjectState state); //change state to enable
    void DisableState(ObjectState state); //change state to disable
    std::map<ObjectState, bool> getStates();  //get states
    std::map<ObjectState, bool> getStates()const;
    void setStates(ObjectState objectState, bool change);

    bool getHiddenState() {    //get Hidden
        return states[HIDDEN];
    }
//    bool getHiddenState() const {    //get Hidden
//        return states[HIDDEN];
//    }

    void setHidden(bool hidden) {     //set Hidden
        states[HIDDEN] = hidden;
    }

private:
    std::map<ObjectState, bool> states;
};


#endif //PROJECT1SFMLTYPE_STATES_H
