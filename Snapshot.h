//
// Created by chuning liu on 4/2/21.
//

#ifndef PROJECT1SFMLTYPE_SNAPSHOT_H
#define PROJECT1SFMLTYPE_SNAPSHOT_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Snapshot {
protected:
    string componentID;
    string data;
public:
    //Snapshot(string input);
    Snapshot();

    explicit Snapshot(string componentID); //constructor
    Snapshot(const Snapshot &snapshot); //copy constructor
    const string &getData() const;   //get data
    void setData(const string &data); //set data
    const string getComponetId();   //get componetId
    void setComponentId(string componentId); //set componentID
    //virtual void applySnapshot(const Snapshot& snapshot);
    friend ostream &operator<<(ostream &output, const Snapshot &snapshot);


};


#endif //PROJECT1SFMLTYPE_SNAPSHOT_H
