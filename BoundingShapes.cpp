#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

std::vector <std::string> splitWords(std::string line, std::string delimiter){
    std::vector<std::string> words;
    
    int del = line.find(delimiter);
    while (del != -1) {
        words.push_back(line.substr(0, del));
        line.erase(line.begin(), line.begin() + del + 1);
        del = line.find(delimiter);
    }
    words.push_back(line.substr(0, line.size()));
    return words;
}

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
        words = splitWords(line, " ");

        if (words.at(0) == "Circle") {
            sf::CircleShape cir;
            cir.setFillColor(getColor(words));
            cir.setRadius(std::stoi(words.at(words.size() - 1)));
            cir.setPosition(sf::Vector2f(std::stoi(words.at(2)), std::stoi(words.at(3))));
            cir.move(sf::Vector2f(std::stoi(words.at(4)), std::stoi(words.at(5))));
            cirs.push_back(cir);
        }
        else if (words.at(0) == "Rectangle") {
            sf::RectangleShape rect;
            rect.setFillColor(getColor(words));
            rect.setSize(sf::Vector2f(std::stoi(words.at(words.size() - 2)), std::stoi(words.at(words.size() - 1))));
            rect.setPosition(sf::Vector2f(std::stoi(words.at(2)), std::stoi(words.at(3))));
            rect.move(sf::Vector2f(std::stoi(words.at(4)), std::stoi(words.at(5))));
            rects.push_back(rect);
        }

    }

    configFile.close();
    return 0;
}

