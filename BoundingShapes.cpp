#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>


sf::Color getColor(std::vector <std::string> words) {
    // 6 7 8
    if (words.at(1).at(0) == 'C') {
        sf::Color c(std::stoi(words.at(6)), stoi(words.at(7)), stoi(words.at(8)));
        return c;
    }

    // 7 8 9
    if (words.at(1).at(0) == 'R') {
        sf::Color c(std::stoi(words.at(7)), stoi(words.at(8)), stoi(words.at(9)));
        return c;
    }
}
int main()
{
    std::vector <sf::RectangleShape> rects;
    std::vector <sf::CircleShape> cirs;
    std::vector <std::string> words;
    std::string line;

    // open file
    std::ifstream configFile("C:\\Users\\Felicity\\source\\repos\\BoundingShapes\\configs\\config.txt");
    if (!configFile.is_open()) {
        std::cerr << "Error loading the config file\n";
        return -1;
    }

    while(std::getline(configFile, line)) {
        
    }

    configFile.close();
    return 0;
}

