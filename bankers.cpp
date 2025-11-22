#include <iostream>
#include <fstream>
#include <vector>

int main() {

    std::ifstream info("info.txt");
    std::string input;
    std::vector<int> avaliable;
    std::vector<std::vector<int>> allocation;
    std::vector<std::vector<int>> max;


    //File Parsing


    if (info.is_open()) {
        } 
    else {
            std::cerr << "Error opening info.txt" << std::endl;
    }

    std::vector<int> temp;
    int i = 1;
    int active = 0;
    int collect = 0;

    while (getline (info, input)) {
        if (input == "allocation") {   
            active = 0;
        }
        if (input == "max") {   
            active = 1;
        }
        if (input == "avaliable") {   
            active = 2;
        }
        if (input[0] == '{') {
            i = 1;
            while (i < input.size() && input[i] != '}') {
                if (input[i] != ' ' && input[i] !=',') {
                    while (i < input.size() && input[i] != ' ' && input[i] != ',') {
                        collect = (collect * 10);
                        collect += (input[i] - '0');
                        i++;
                    }
                    temp.push_back(collect);
                    collect = 0;
                }
                i++;
            }
            if (active == 0) {
                    allocation.push_back(temp);
                }
            else if (active == 1) {
                max.push_back(temp);
            }
            else if (active == 2) {
                avaliable = temp;
            }
            temp.clear();
        }
    }

    info.close();
    //Banker's Algorithm Implementation

    std::vector<std::vector<int>> need = max;
    std::vector<bool> complete;
    std::vector<int> sequence;
    bool change = true;
    bool safe = true;
    //Initializing need and complete
    for (int i = 0; i < need.size(); i++) {
        for (int j = 0; j < need[i].size(); j++) {
            need[i][j] = need[i][j] - allocation[i][j];
        }
        complete.push_back(false);
    }

    while (change) {
        change = false;
        for (int i = 0; i < need.size(); i++) {
            if (!(complete[i])) {
                safe = true;
                for (int j = 0; j < need[i].size(); j++) {
                    if (need[i][j] > avaliable[j]) {
                        safe = false;
                        break;
                    }
                }
                if (safe) {
                    for (int j = 0; j < need[i].size(); j++) {
                        avaliable[j] = avaliable[j] + allocation[i][j];
                    }
                    complete[i] = true;
                    sequence.push_back(i);
                    change = true;
                }
            }
        }
    }
    safe = true;
    for (int j = 0; j < complete.size(); j++) {
        if (!(complete[j])) {
            safe = false;
            break;
        }
    }

    if (safe == false) {
        std::cout << "The system is not in a safe state." << std::endl;
    }

    if (safe == true) {
        std::cout << "The system is in a safe state! The safe sequence is: ";
        for (int i = 0; i < sequence.size(); i++) {
            std::cout << "P" << sequence[i] << " ";
        }
    }


    return 0;
}