#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class ImageViewer {
public:
    ImageViewer() : isGrayScale(false) {
        // Création de la fenêtre
        window.create(sf::VideoMode(800, 600), "Image Viewer");
        loadImage("path_to_your_image.png"); // Chargez votre image ici
    }

    void loadImage(const std::string& path) {
        if (!texture.loadFromFile(path)) {
            std::cerr << "Erreur lors du chargement de l'image." << std::endl;
        }
        sprite.setTexture(texture);
    }

    void toggleGrayScale() {
        isGrayScale = !isGrayScale;
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Ici, vous pouvez ajouter d'autres événements, comme un bouton poussoir
            }

            if (isGrayScale) {
                applyGrayScale();
            }

            window.clear();
            window.draw(sprite);
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    sf::Texture texture;
    sf::Sprite sprite;
    bool isGrayScale;

    void applyGrayScale() {
        sf::Image img = texture.copyToImage();
        for (unsigned int y = 0; y < img.getSize().y; ++y) {
            for (unsigned int x = 0; x < img.getSize().x; ++x) {
                sf::Color pixelColor = img.getPixel(x, y);
                int grayValue = static_cast<int>(0.299 * pixelColor.r + 0.587 * pixelColor.g + 0.114 * pixelColor.b);
                img.setPixel(x, y, sf::Color(grayValue, grayValue, grayValue));
            }
        }
        texture.loadFromImage(img);
    }
};

int main() {
    ImageViewer viewer;
    viewer.run();
    return 0;
}