#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <SFML/Graphics.hpp>
#include "ImageModel.h"
#include <string>

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
    std::string openFileDialog(); // Ouvrir l'explorateur de fichiers
};

#endif // IMAGEVIEWER_H
