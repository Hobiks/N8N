#include "image_model.hpp"

ImageModel::ImageModel(const std::string &path) : imagePath(path) {}

void ImageModel::loadImage() {
    image = cv::imread(imagePath);
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
}

const cv::Mat& ImageModel::getImage() const {
    return image;
}

const cv::Mat& ImageModel::getGrayImage() const {
    return grayImage;
}
