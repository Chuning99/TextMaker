//
// Created by 刘储宁 on 5/22/21.
//
#include <cmath>
#include "HSVPicker.h"
HSVPicker::HSVPicker() {
    colors = sf::VertexArray(sf::Points, 256 * 256);
    this->colorPicked = false;
}

void HSVPicker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(colors,states);
}

void HSVPicker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
//                cout << "HSVPicker :: mouse clicked " << event.mouseButton.x << ", " << event.mouseButton.y << endl;
            bool inColorBox = MouseEvents<HSVPicker>::mouseClicked(*this,window, event);
            if(inColorBox){
                this->setPickedColor(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                this->colorPicked = true;
                this->setHidden(!this->getHiddenState());
            }
        }
    }
}

void HSVPicker::update() {

}

void HSVPicker::setColorPoint() {

    for (unsigned int y = 0; y <= 255; ++y) {
        for (unsigned int x = 0; x <= 255; ++x) {

            if(stable){
                sf::Color c = this->HSVtoColor(this->hueValue, this->sValue / 255.0, this->vValue/255.0);
                colors[y * 256 + x].color = c;
            }
            else{
                const double s = x / 255.0;
                const double v = y / 255.0;

                sf::Color c = this->HSVtoColor(this->hueValue, s, v);
                colors[y * 256 + x].color = c;
            }
        }
    }
}

Snapshot &HSVPicker::getSnapshot() {

}

void HSVPicker::applySnapshot(const Snapshot &snapshot) {

}

sf::FloatRect HSVPicker::getobjectGlobalBounds() {
    sf::FloatRect floatRect = sf::FloatRect (this->getPosition().x, this->getPosition().y,
                                             colors.getBounds().width, colors.getBounds().height);
    return floatRect;
}

void HSVPicker::setPosition(sf::Vector2f position) {
    this->position = position;
    for (unsigned int y = 0; y <= 255; y += 1) {
        for (unsigned int x = 0; x <= 255; x += 1) {
            sf::Vertex &vertex(colors[y * 256 + x]);
            sf::Vertex &vertex2(colors[y * 256 + x]);

            vertex.position.x = x + this->position.x;
            vertex.position.y = y + this->position.y;

            vertex2.position.x = x + this->position.x + 0.5;
            vertex2.position.y = y + this->position.y + 0.5;
        }
    }
}

void HSVPicker::setColor(sf::Color color) {
//    colors = sf::VertexArray(sf::Points, 256 * 256);
    auto hsv = this->RGBtoHSV(color);
    this->hueValue = get<0>(hsv) / 360.f;
    this->sValue = get<1>(hsv) * 255.f;
    this->vValue = get<2>(hsv) * 255.f;

    if(color == sf::Color::Black || color == sf::Color::White){
        stable = true;
    }
    else{
        stable = false;
    }
    setColorPoint();
}

std::tuple<float, float, float> HSVPicker::RGBtoHSV(const sf::Color &color) {
    {
        float R = color.r / 255.f;
        float G = color.g / 255.f;
        float B = color.b / 255.f;

        float M = std::max({ R, G, B });
        float m = std::min({ R, G, B });
        float C = M - m; // Chroma

        float H = 0.f; // Hue
        float S = 0.f; // Saturation
        float V = 0.f; // Value

        if (C != 0.f)
        {
            if (M == R)
                H = fmod(((G - B) / C), 6.f);
            else if (M == G)
                H = ((B - R) / C) + 2;
            else if (M == B)
                H = ((R - G) / C) + 4;

            H *= 60;
        }

        if (H < 0.f)
            H += 360;

        V = M;

        if (V != 0.f)
            S = C / V;
        cout<<"RGB to HSV H is "<<H<<endl;
        cout<<"RGB to HSV S is "<<S<<endl;
        cout<<"RGB to HSV V is "<<V<<endl;
        return { H, S, V };
    }
}

sf::Vector2f HSVPicker::getPosition() {
    return this->position;
}

const sf::Color &HSVPicker::getPickedColor() const {
    return pickedColor;
}

void HSVPicker::setPickedColor(sf::Vector2f pickedPosition) {
    int x = pickedPosition.x - this->position.x;
     int y = pickedPosition.y - this->position.y;
    cout << "pickedPosition: " << "(" << x << ", " << y << ")" << endl;
//    const double s = x / 255.0; // x is our saturation
//    const double v = y / 255.0; // y is our value
//
//    this->pickedColor = this->HSVtoColor(this->hueValue, s, v);
    this->pickedColor = this->colors[y * 256 + x].color;
}

sf::Color HSVPicker::HSVtoColor(double h, double s, double v) {
     int cs = h * 6;
     double f = h * 6 - cs;
     double p = v * (1 - s);
     double q = v * (1 - s * f);
     double t = v * (1 - s * (1 - f));

    sf::Color color;
    switch (cs) {
        case 0:
        case 6:
            color = sf::Color(v * 255, t * 255, p * 255);
            break;
        case 1:
            color = sf::Color(q * 255, v * 255, p * 255);
            break;
        case 2:
            color = sf::Color(p * 255, v * 255, t * 255);
            break;
        case 3:
            color = sf::Color(p * 255, q * 255, v * 255);
            break;
        case 4:
            color = sf::Color(t * 255, p * 255, v * 255);
            break;
        case 5:
            color = sf::Color(v * 255, p * 255, q * 255);
            break;
    }
    return color;
}

bool HSVPicker::isColorPicked() const {
    return colorPicked;
}

void HSVPicker::setColorPicked(bool colorPicked) {
    HSVPicker::colorPicked = colorPicked;
}
