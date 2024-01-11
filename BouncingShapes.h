#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

class CIRCLE {
public:
    sf::CircleShape cir;
    CIRCLE(sf::Color color, float radius, sf::Vector2f pos, float x_vel, float y_vel) {
        cir.setFillColor(color);
        cir.setRadius(radius);
        cir.setPosition(pos);
        xVelocity = x_vel;
        yVelocity = y_vel;
    }
    float getXVelocity() {
        return xVelocity;
    }
    float getYVelocity() {
        return yVelocity;
    }
private:
    float xVelocity;
    float yVelocity;
};