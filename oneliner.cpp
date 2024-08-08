#include <iostream>
#include <string>
#include <fstream>


int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }

    if (argc < 2) {
        std::cout << "Specify file to one-line" << std::endl;
        return 1;
    }

    std::string word;
    std::ifstream file(argv[1]);
    std::ofstream temp("temp.txt");

    std::string prev = "";
    while (file >> word) {
        temp << word;
        if (file >> std::ws) {
            if (prev[0] == '#') {
                temp << '\n';
            } else {
                temp << " ";
            }
        }
        prev = word;
    }

    
    
    file.close();
    temp.close();

    std::remove(argv[1]);
    std::rename("temp.txt", argv[1]);
    std::cout << "File one-lined" << std::endl;
    return 0;
}
