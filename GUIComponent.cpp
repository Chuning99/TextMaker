//
// Created by chuning liu on 4/2/21.
//
#include "GUIComponent.h"

GUIComponent::GUIComponent() {

}

//from the sf::Drawable class
void GUIComponent::draw(sf::RenderTarget &window, sf::RenderStates states) const {

}

// from EventHandler
void GUIComponent::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void GUIComponent::update() {

}

//from SnapshotInterface
Snapshot &GUIComponent::getSnapshot() {

}

void GUIComponent::applySnapshot(const Snapshot &snapshot) {
    cout << "In GuiComponent: applySnapshot" << endl;
}