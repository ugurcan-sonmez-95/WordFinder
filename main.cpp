// Word Finder

#include <iostream>
#include <fstream>
#include <string>

bool find_word(const std::string &word, const std::string &source) {
    size_t found = source.find(word);
    if (found == std::string::npos)
        return false;
    else
        return true;
}

int main() {
    std::ifstream in_file;
    std::string word;
    std::string source;
    int word_count {};
    int match_count {};

    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        std::cout << std::endl;
        std::cerr << "Error opening file." << std::endl;
        return 1;
    } else {
        std::cout << std::endl;
        std::cout << "Enter a word to find: ";
        std::cin >> word;
        std::cout << "\n";
        while (in_file >> source) {
            word_count++;
            if (find_word(word, source)) {
                match_count++;
                std::cout << source << " ";
            }
        }
        std::cout << "\n" << std::endl;
        std::cout << word_count << " words were searched." << std::endl;
        std::cout << std::endl;
        std::cout << word << " was found " << match_count << " times." << std::endl;

        in_file.close();

        std::cout << std::endl;
        return 0; 
    }
}