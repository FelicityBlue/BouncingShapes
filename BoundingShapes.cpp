#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

int main()
{
    std::vector <sf::RectangleShape> rects;
    std::vector <sf::CircleShape> cirs;

    std::string line;
    // open file
    std::ifstream configFile("C:\\Users\\Felicity\\source\\repos\\BoundingShapes\\configs\\config.txt");

    while(std::getline(configFile, line)) {
        std::cout << line << std::endl;
    }

    configFile.close();
    return 0;
}

