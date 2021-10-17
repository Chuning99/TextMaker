//
// Created by chuning liu on 4/2/21.
//

#include "Snapshot.h"

Snapshot::Snapshot() {
    componentID = "0";
    data = "";
}

Snapshot::Snapshot(string componentID) {
    this->componentID = componentID;
}

Snapshot::Snapshot(const Snapshot &snapshot) {
    this->componentID = snapshot.componentID;
    this->data = snapshot.data;
}

const string &Snapshot::getData() const {
    return data;
}

void Snapshot::setData(const string &data) {
    this->data = data;
}

const string Snapshot::getComponetId() {
    return this->componentID;
}

void Snapshot::setComponentId(string _componentId) {
    componentID = _componentId;
}

ostream &operator<<(ostream &output, const Snapshot &snapshot) {
    output << "componentID :" << snapshot.componentID << " Data :" << snapshot.getData();
    return output;
}