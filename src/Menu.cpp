#include "Menu.h"
#include <cstdlib>
#include <iostream>
#include <filesystem>
bool stayInMenu;
//std::string folderPath = "../dataset";
//int fileCount = 0;
//std::vector<std::string> fileList;
Graph * graph = loadSampleGraph("../dataset/Toy-Graphs/tourism.csv", true);

int Menu::auxMenu(int maxOption, int minOption) {
    int op;
    while (true) {
        std::cin >> op;
        if (std::cin.fail() || (op > maxOption || op < minOption)) {
            std::cout << "Please enter a valid integer: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else {
            break;
        }
    }
    return op;
}

void Menu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
}

int Menu::mainMenu() {
    std::cout << "\nMAIN MENU\n\n";
    std::cout << "\t1. Backtracking Algorithm" << std::endl
              << "\t2. Triangular Approximation Heuristic" << std::endl
              << "\t3. Other Heuristics" << std::endl
              << "\t4. Change Dataset" << std::endl
              << "\t5. About Us" << std::endl << std::endl
              << "\t0. Quit" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "Choose an option: ";
    /*
    getGraphsInDataset(folderPath, fileList);
    for (const auto& file : fileList) {
        std::cout << fileCount << ". " << file << std::endl;
        fileCount++;
    }
    */
    return auxMenu(5, 0);
}

int Menu::aboutUsMenu() {
    //clearScreen();
    std::cout
            << "\nHelp platform for the management of shipping and deliveries created in favor of the Design of Algorithms course\n"
            << std::endl;
    std::cout << "Meet the team: \n\n";
    std::cout << std::left << std::setw(30) << "STUDENT NAME" << std::right << std::setw(18) << "STUDENT NUMBER"
              << std::setw(9) << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "Hélder Costa" << std::setfill(' ') << std::right << std::setw(18)
              << " 202108719" << std::endl;
    std::cout << std::left << std::setw(30) << "Luís Duarte" << std::setfill(' ') << std::right << std::setw(18)
              << " 202108734" << std::endl;
    std::cout << std::left << std::setw(30) << "Luís Jesus" << std::setfill(' ') << std::right << std::setw(18)
              << " 202108683" << std::endl;
    std::cout << std::endl << "0. Return to main menu \n" << std::endl;
    std::cout << "Choose an option: ";
    return auxMenu(0, 0);
}

void Menu::getGraphsInDataset(const std::string& folderPath, std::vector<std::string>& fileList) {
    std::filesystem::path path(folderPath);

    if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path)) {
        std::cout << "Invalid folder path: " << folderPath << std::endl;
        return;
    }

    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(entry.path())) {
            std::string folderName = entry.path().filename().string();
            if (folderName.find("graph") == 0) {
                fileList.push_back(folderName);
            } else {
                getGraphsInDataset(entry.path().string(), fileList);
            }
        } else {
            std::string extension = entry.path().extension().string();
            if (extension == ".csv") {
                std::string fileName = entry.path().filename().string();
                fileList.push_back(fileName);
            }
        }
    }
}

void Menu::menuController() {
    int op;
    //load dataset
    clearScreen();
    std::cout << std::endl << "Welcome to the support platform for the management of ocean shipping and urban deliveries!" << std::endl
              << std::endl;
    std::cout << "--------------------SHIPPING AND DELIVERIES ANALYSIS SYSTEM--------------------" << std::endl;
    do {
        int temp;
        op = mainMenu();
        do {
            switch (op) {

                case 1:{
                    temp = 0;
                    graph->resetVisited();

                    std::vector<int> path, bestPath;
                    double minCost;
                    double cumulatedCost = 0.0;
                    path.push_back(0);
                    path.push_back(graph->getNumVertex()-2);

                    auto start = std::chrono::high_resolution_clock::now();
                    graph->tsp_backtracking(path, bestPath, minCost, cumulatedCost);
                    auto end = std::chrono::high_resolution_clock::now();
                    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
                    std::cout << "Run time: " << std::fixed << (double) duration.count() / 1000 << "\n";

                    if (bestPath.empty()){
                        std::cout << ("empty");
                    }

                    for (size_t i = 0; i < bestPath.size(); i++) {
                        std::cout << bestPath[i];
                        if (i != bestPath.size() - 1) {
                            std::cout << " -> ";
                        }
                    }
                    break;
                }

                case 2:{

                }

                case 5: {
                    temp = aboutUsMenu();
                    break;
                }
                default:
                    break;
            }
        }while (temp != 0);
    }while (op != 0);
    std::cout << "\n";
    std::cout << "Thank you for using our platform!" << std::endl;
}