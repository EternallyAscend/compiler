#include "promote.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string.h>

int main (int argc, char* argv[]) {
    if (argc < 2){
        std::cout << "please input the name of code.txt" << std::endl;
        exit(1);
    }
    std::ifstream inputfile(argv[1]);
    std::ofstream outputfile("promote.txt");
    if (!inputfile) {
        std::cout << "can't open input file: " << argv[1] << std::endl;
    }
    if (!outputfile) {
        std::cout << "can't write output file: promote.txt" << std::endl;
    }
    std::vector<code> codes;
    code line;
    std::string index;
    while(skipSpace(inputfile)
          && getline(inputfile, line.str[0], ' ') 
          && getline(inputfile, line.str[1], ' ')
          && getline(inputfile, line.str[2], ' ') 
          && getline(inputfile, line.str[3], '\n')) {
        codes.push_back(line);
        std::cout << line.str[0] << ' ';
        std::cout << line.str[1] << ' ';
        std::cout << line.str[2] << ' ';
        std::cout << line.str[3] << std::endl;
    }
    for (auto line = codes.rbegin(); line != codes.rend();){
        std::cout << line->str[0] << ' ';
        std::cout << line->str[1] << ' ';
        std::cout << line->str[2] << ' ';
        std::cout << line->str[3] << std::endl;
        std::string args;
        std::string command;
        bool used;
        used = false;
        command = std::string(line->str[1]);
        std::cout << "command: " << command << std::endl;
        if (command == "j" || command == "in" || command == "out"){
            line++;
            std::cout << command << ": " << "do not delete" << std::endl;
            continue;
        }
        else if (command == "n") {
            args = '@' + line->str[0];
        }
        else {
            args = '#' + line->str[0];
        }
        std::cout << args << ": " << "argument operation, check" << std::endl;
        for (auto user = codes.rbegin(); user != codes.rend(); user++) {
            if (user->str[0] != line->str[0] && user->str[2] == args || user->str[3] == args) {
                used = true;
                std::cout << args << " used" << std::endl;
                break;
            }
        }
        if (!used) {
            std::cout << args << ": unused" << std::endl;
            line = std::vector<code>::reverse_iterator(codes.erase((++line).base()));
        }
        else {
            line++;
        }
    }
    for (auto line = codes.begin(); line != codes.end(); line++) {
        std::string* jump;
        if (line->str[1] == "j") {
            jump = &line->str[3];
            if (*jump == "-1") {
                continue;
            }
            for (auto next = line + 1; next != codes.end(); next++) {
                if (*jump == next->str[0]) {
                    break;
                }
                else if (*jump < next->str[0]) {
                    *jump = next->str[0];
                    break;
                }
            }
        }
    }
    for (auto &line : codes) {
        outputfile << line.str[0] << ' ';
        outputfile << line.str[1] << ' ';
        outputfile << line.str[2] << ' ';
        outputfile << line.str[3] << std::endl;
    }
    inputfile.close();
    outputfile.close();
    return 0;
}

bool skipSpace(std::istream &is) {
    while(is.peek() == ' ') {
        is.ignore(1);
    }
    return true;
}