#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <filesystem>

void openImage(const std::string& imagePath, cv::Mat& image) {
    image = cv::imread(imagePath);
    if(image.empty()) {
        std::cerr << "Error: could not open or find the image!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void resizeImage(const cv::Mat& image, cv::Mat& resizedImage, int width, int height) {
    cv::resize(image, resizedImage, cv::Size(width, height));
}

void saveImage(const std::string& outputPath, const cv::Mat& image) {
    if(!cv::imwrite(outputPath, image)) {
        std::cerr << "Error: could not save the image!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

std::string showFileDialog() {
    // Code placeholder pour l'explorateur de fichiers.
    // En fonction de l'OS, utiliser des bibliothèques comme QFileDialog pour Qt
    // ou autres options pour avoir l'interaction utilisateur.
    return "chemin/vers/limage.jpg"; // Remplacez par le chemin sélectionné.
}

int main() {
    std::string imagePath = showFileDialog();
    cv::Mat image, resizedImage;

    openImage(imagePath, image);
    
    // Taille cible pour la redimension
    int newWidth = 800; // par exemple
    int newHeight = 600; // par exemple
    resizeImage(image, resizedImage, newWidth, newHeight);

    std::string outputPath = "chemin/vers/limage_redimensionnee.jpg";
    saveImage(outputPath, resizedImage);

    std::cout << "Image redimensionnée et sauvegardée avec succès!" << std::endl;

    return 0;
}