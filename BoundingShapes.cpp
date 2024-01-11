#include "BouncingShapes.h";

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
    if (words.at(1).at(0) == 'C' || words.at(1).at(0) == 'R') {
        sf::Color c(std::stof(words.at(6)), stof(words.at(7)), stof(words.at(8)));
        return c;
    }

    if (words.at(0) == "Font") {
        sf::Color c(std::stof(words.at(words.size()-3)), std::stof(words.at(words.size() - 2 )), std::stof(words.at(words.size() - 1)));
        return c;
    }
}

int main()
{
    std::vector <RECT> rects;
    std::vector <CIRCLE> cirs;
    std::vector <std::string> words;
    std::vector <sf::Text> texts;
    sf::Text text;
    std::string line;
    float xVelocity = 0.0, yVelocity = 0.0, xPos = 0.0, yPos = 0.0, diameter = 0.0;
    sf::RenderWindow window;
    // open file
    std::ifstream configFile("C:\\Users\\Felicity\\source\\repos\\BoundingShapes\\configs\\config.txt");
    if (!configFile.is_open()) {
        std::cerr << "Error loading the config file\n";
        return -1;
    }

    while(std::getline(configFile, line)) {
        words = splitWords(line, " ");

        std::cout << std::endl;
        if (words.at(0) == "Circle") {
           // sf::Color color, float radius, sf::Vector2f pos, float x_vel, float y_vel
            cirs.push_back((CIRCLE(getColor(words), std::stof(words.at(9)),
                (sf::Vector2f(std::stof(words.at(2)), 
                    std::stof(words.at(3)))), std::stof(words.at(4)), std::stof(words.at(5)))));
        }
        else if (words.at(0) == "Rectangle") {
            // sf::Color color, sf::Vector2f size, sf::Vector2f pos, float x_vel, float y_vel
            rects.push_back(RECT(getColor(words), 
                sf::Vector2f(std::stof(words.at(9)), std::stof(words.at(10))), 
                sf::Vector2f(std::stof(words.at(2)), std::stof(words.at(3))), 
                std::stof(words.at(4)), std::stof(words.at(5))));
        }
        // set up window
        else if (words.at(0) == "Window") {
            window.create(sf::VideoMode(std::stoi(words.at(1)), std::stoi(words.at(2))), "Bounding Shapes");
            
        }
        // set up fonts
        else if (words.at(0) == "Font") {
            sf::Font techFont;
            if (!techFont.loadFromFile("C:\\Users\\Felicity\\source\\repos\\AimTrainer\\8-bit-operator\\8bitOperatorPlus8-Regular.ttf")) {
                std::cerr << ("Error: Cannot load the font");
                return -1;
            }
            text.setFont(techFont);
            text.setCharacterSize(std::stoi(words.at(2)));
            text.setFillColor(getColor(words));
            
        }
    }


    while (window.isOpen()) {
        // render
        window.clear(sf::Color::Black);
       
         for (auto& r : rects) {
            
            xPos = r.getXPos();
            yPos = r.getYPos();
            xVelocity = r.getXVelocity();
            yVelocity = r.getYVelocity();

            if (xPos >= (window.getSize().x - r.rect.getSize().x) || xPos <= 0) {
                r.setXVelocity(-xVelocity);
            }
            if (yPos >= (window.getSize().y - r.rect.getSize().y) || yPos <= 0) {
                r.setYVelocity(-yVelocity);
            }
            xPos += r.getXVelocity();
            yPos += r.getYVelocity();


            r.rect.setPosition(sf::Vector2f(xPos, yPos));
            window.draw(r.rect);
            
         }
         
         for (auto& c : cirs) {
             xPos = c.getXPos();
             yPos = c.getYPos();
             xVelocity = c.getXVelocity();
             yVelocity = c.getYVelocity();
             diameter = c.cir.getRadius() * 2;

             if ((xPos + diameter) >= (window.getSize().x) || xPos <= 0) {
                 c.setXVelocity(-xVelocity);
             }
             if ((yPos + diameter) >= (window.getSize().y ) || yPos <= 0) {
                 c.setYVelocity(-yVelocity);
             }
             
             xPos += c.getXVelocity();
             yPos += c.getYVelocity();

             c.setPos(xPos, yPos);
             window.draw(c.cir);

         }
         
        

        
        window.display();
    }
    
    // TEST
    std::cout << "The size of the circle vector is " << cirs.size() << std::endl;
    std::cout << "The size of the rectangle vector is " << rects.size() << std::endl;
    

    configFile.close();
    return 0;
}

