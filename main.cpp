#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QImage>
#include "image_model.hpp"

class ImageApp : public QMainWindow {
    Q_OBJECT

public:
    ImageApp() {
        auto *button = new QPushButton("Load Image");
        auto *toggleButton = new QPushButton("Toggle Grayscale");
        imageLabel = new QLabel();

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(button);
        layout->addWidget(toggleButton);
        layout->addWidget(imageLabel);

        QWidget *widget = new QWidget();
        widget->setLayout(layout);
        setCentralWidget(widget);

        connect(button, &QPushButton::clicked, this, &ImageApp::loadImage);
        connect(toggleButton, &QPushButton::clicked, this, &ImageApp::toggleGrayscale);
    }

private slots:
    void loadImage() {
        QString filename = QFileDialog::getOpenFileName(this, "Open Image", "", "Images (*.png *.xpm *.jpg *.jpeg *.bmp)");
        if (!filename.isEmpty()) {
            imageModel = new ImageModel(filename.toStdString());
            imageModel->loadImage();
            displayImage(false);
        }
    }

    void toggleGrayscale() {
        showInGrayscale = !showInGrayscale;
        displayImage(showInGrayscale);
    }

    void displayImage(bool grayscale) {
        cv::Mat displayImage = grayscale ? imageModel->getGrayImage() : imageModel->getImage();
        cv::cvtColor(displayImage, displayImage, cv::COLOR_GRAY2RGB);
        QImage qimg = QImage(displayImage.data, displayImage.cols, displayImage.rows, displayImage.step[0], QImage::Format_RGB888);
        imageLabel->setPixmap(QPixmap::fromImage(qimg));
    }

private:
    ImageModel *imageModel;
    QLabel *imageLabel;
    bool showInGrayscale = false;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    ImageApp window;
    window.show();
    return app.exec();
}

#include "main.moc"
