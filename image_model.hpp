#ifndef IMAGE_MODEL_HPP
#define IMAGE_MODEL_HPP

#include <opencv2/opencv.hpp>
#include <string>

class ImageModel {
public:
    ImageModel(const std::string &path);
    void loadImage();
    const cv::Mat& getImage() const;
    const cv::Mat& getGrayImage() const;

private:
    std::string imagePath;
    cv::Mat image;
    cv::Mat grayImage;
};

#endif // IMAGE_MODEL_HPP
