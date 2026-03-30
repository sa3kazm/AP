#include <cctype>
#include <iostream>
#include <map>
#include <string>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::map<char, int> counts;

    for (char ch : text) {
        unsigned char u = static_cast<unsigned char>(ch);
        if (std::isalpha(u)) {
            ch = static_cast<char>(std::tolower(u));
            counts[ch]++;
        }
    }

    if (counts.empty()) {
        std::cout << "У тексті немає букв\n";
        return 0;
    }

    std::cout << "Таблиця повторів букв:\n";
    for (auto item : counts) {
        std::cout << item.first << " " << item.second << "\n";
    }

    char max_letter = 0;
    int max_count = 0;

    for (auto item : counts) {
        if (item.second > max_count) {
            max_count = item.second;
            max_letter = item.first;
        }
    }

    std::cout << "Найчастіше повторюється: " << max_letter << "\n";
    std::cout << "Кількість: " << max_count << "\n";

    return 0;
}
