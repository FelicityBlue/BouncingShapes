#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class CIRCLE {
public:
    sf::CircleShape cir;
    CIRCLE(sf::Color color, float radius, sf::Vector2f pos, float xVel, float yVel) : xVelocity(xVel), yVelocity(yVel) {
        cir.setFillColor(color);
        cir.setRadius(radius);
        cir.setPosition(pos);
        xVelocity = xVel;
        yVelocity = yVel;
    }
    // setters
    void setXVelocity(float newXVel) {
        xVelocity = newXVel;
    }
    void setYVelocity(float newYVel) {
        yVelocity = newYVel;
    }
    void setPos(float x, float y) {
        cir.setPosition(sf::Vector2f(x, y));
    }
    // getters
    float getXVelocity() {
        return xVelocity;
    }
    float getYVelocity() {
        return yVelocity;
    }
    float getXPos() {
        return cir.getPosition().x;
    }
    float getYPos() {
        return cir.getPosition().y;
    }
private:
    float xVelocity;
    float yVelocity;
};

class RECT {
public:
    sf::RectangleShape rect;
    RECT(sf::Color color, sf::Vector2f size, sf::Vector2f pos, float xVel, float yVel): xVelocity(xVel), yVelocity(yVel) {

        rect.setFillColor(color);
        rect.setSize(size);
        rect.setPosition(pos);
    }
    // setters
    void setXVelocity(float newXVel) {
        xVelocity = newXVel;
    }
    void setYVelocity(float newYVel) {
        yVelocity = newYVel;
    }
    // getters
    float getXVelocity() {
        return xVelocity;
    }
    float getYVelocity() {
        return yVelocity;
    }
    float getXPos() {
        return rect.getPosition().x;
    }
    float getYPos() {
        return rect.getPosition().y;
    }
private:
    float xVelocity;
    float yVelocity;
};
