#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iomanip>
#include <iostream>
#include "DatasetLoader.h"
#include <vector>
#include "graph/Graph.h"
#include <limits>

class Menu {
public:

    int auxMenu(int maxOption, int minOption);

    void clearScreen();

    int mainMenu();

    int aboutUsMenu();

    void getGraphsInDataset(const std::string& folderPath, std::vector<std::string>& fileList);

    void menuController();
};

#endif //UNTITLED_MENU_H