//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_HISTORY_H
#define PROJECT1SFMLTYPE_HISTORY_H

#include <SFML/Graphics.hpp>
#include "Snapshot.h"
#include <iostream>
#include <stack>
#include "GUIComponent.h"

class History {
protected:
    static std::stack<Snapshot> stack;
    static std::map<std::string, GUIComponent *> components;
    static int globalComponentID;
public:
    struct Response {
        bool found;
        GUIComponent *component;

        //response constructor
        Response(bool _found = false, GUIComponent *_component = nullptr) {
            found = _found;
            component = _component;
        }
    };

    //get history size
    static int getHistorySize() {
        return stack.size();
    }

    //check history is empty or not
    static bool emptyHistory() {
        cout << "Stack size:" << stack.size() << endl;
        return stack.empty();
    }

    //put snapshot to history
    static void pushHistory(const Snapshot &snapshot) {
        stack.push(snapshot);
    }

    //the top of history
    static Snapshot &topHistory() {
        if (!stack.empty()) {
            return stack.top();
        }

    }

    //pop history
    static void popHistory() {
        stack.pop();
    }

    // addEventHandler function
    static void addEventHandler(sf::RenderWindow &window, sf::Event event) {

    }

    //get component
    static Response &getComponent(std::string componentID) {
        map<std::string, GUIComponent *>::iterator it = components.find(componentID);

        Response response;
        if (it == components.end()) {
            return response;
        }
        response.component = components[componentID];
        response.found = true;
        return response;
    }

    //add component function
    static string addComponent(GUIComponent *component) {
        string componentId = generateComponentID();
        components[componentId] = component;
        return componentId;
    }

    //
    static string generateComponentID() {
        return to_string(globalComponentID++);
    }
};



#endif //PROJECT1SFMLTYPE_HISTORY_H
