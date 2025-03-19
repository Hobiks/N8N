#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

class ImageViewer {
public:
    ImageViewer(const std::string& imagePath) : imagePath(imagePath), isGrayScale(false) {
        // Charger l'image
        image = cv::imread(imagePath);
        if (image.empty()) {
            std::cerr << "Error loading image" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        // Créer une fenêtre pour afficher l'image
        cv::namedWindow("Image Viewer", cv::WINDOW_AUTOSIZE);
        cv::imshow("Image Viewer", image);
        
        // Créer un bouton pour passer en gris
        cv::createButton("Toggle Grayscale", onButtonClick, this, cv::QT_PUSH_BUTTON, 0);
        
        // Attendre la fermeture de la fenêtre
        cv::waitKey(0);
    }

    static void onButtonClick(int state, void* userData) {
        ImageViewer* viewer = static_cast<ImageViewer*>(userData);
        viewer->toggleGrayScale();
    }

    void toggleGrayScale() {
        isGrayScale = !isGrayScale;
        if (isGrayScale) {
            cv::Mat grayImage;
            cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
            cv::imshow("Image Viewer", grayImage);
        } else {
            cv::imshow("Image Viewer", image);
        }
    }

private:
    cv::Mat image;
    std::string imagePath;
    bool isGrayScale;
};

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <image-path>" << std::endl;
        return EXIT_FAILURE;
    }

    ImageViewer viewer(argv[1]);
    return 0;
}