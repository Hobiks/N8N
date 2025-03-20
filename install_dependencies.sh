#!/bin/bash

# Met à jour les dépôts
sudo apt update

# Installe les dépendances pour OpenCV et Qt5
sudo apt install build-essential -y
sudo apt install libopencv-dev -y
sudo apt install qt5-default -y
sudo apt install qt5-qmake -y
