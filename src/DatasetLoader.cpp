#include "DatasetLoader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Graph *loadDataset(std::string networkPath, std::string stationsPath) {
    std::ifstream networkFile(networkPath);
    std::ifstream stationFile(stationsPath);

    if (!networkFile.good()) {
        std::cout << "Couldn't load network file " << networkPath << "\n";
        return nullptr;
    }

    if (!stationFile.good()) {
        std::cout << "Couldn't load stations file " << stationsPath << "\n";
        return nullptr;
    }

    Graph *graph = new Graph();

    std::string stationLine;
    std::getline(stationFile, stationLine);

    while (std::getline(stationFile, stationLine).good()) {
        std::istringstream stationLineStream(stationLine);
        std::string name;
        std::getline(stationLineStream, name, ',');
        std::string district;
        std::getline(stationLineStream, district, ',');
        std::string municipality;
        std::getline(stationLineStream, municipality, ',');
        std::string township;
        std::getline(stationLineStream, township, ',');
        std::string line;
        std::getline(stationLineStream, line, '\r');


    }

    std::string networkLine;
    std::getline(networkFile, networkLine);

    while (std::getline(networkFile, networkLine).good()) {
        std::istringstream networkLineStream(networkLine);
        std::string stationA;
        std::getline(networkLineStream, stationA, ',');
        std::string stationB;
        std::getline(networkLineStream, stationB, ',');
        std::string capacityStr;
        std::getline(networkLineStream, capacityStr, ',');
        int capacity = std::atoi(capacityStr.c_str());
        std::string service;
        std::getline(networkLineStream, service, '\r');

    }
    return graph;
}
