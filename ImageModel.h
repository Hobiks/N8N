#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class ImageModel {
public:
    ImageModel();
    bool loadImage(const std::string& path);
    void applyGrayScale();
    const sf::Texture& getTexture() const { return texture; }

private:
    sf::Texture texture;
    bool isGrayScale;
};

#endif // IMAGEMODEL_H
