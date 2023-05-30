#include "Menu.h"
#include <cstdlib>

bool stayInMenu;

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

    Graph *graph = loadSampleGraph("../dataset/Toy-Graphs/shipping.csv");
    std::vector<int> path = {0};
    std::vector<int> bestPath;
    std::vector<bool> visited(graph->getNumVertex(), false);
    double minCost = std::numeric_limits<double>::max();
    graph->resetVisited();
    Vertex *source = graph->findVertex(0);
    source->setVisited(true);
    graph->tsp_backtracking(path, bestPath, minCost, 0.0);
    std::cout << "Minimum cost: " << minCost << std::endl;
    for (auto v: bestPath) {
        std::cout << v << " ";
    }
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