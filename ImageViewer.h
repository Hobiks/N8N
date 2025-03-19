#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <SFML/Graphics.hpp>
#include "ImageModel.h"

class ImageViewer {
public:
    ImageViewer();
    void run();

private:
    sf::RenderWindow window;
    ImageModel model;

    void processEvents();
    void update();
    void render();
    std::string openFileDialog();
};

#endif // IMAGEVIEWER_H
