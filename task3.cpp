#include <iostream>
#include <cstring>

bool isConsonant(char c) {
    c = tolower(c);
    return std::string("bcdfghjklmnpqrstvwxyz").find(c) != std::string::npos;
}

int countConsonants(const char* word) {
    int count = 0;
    for (int i = 0; word[i] != '\0'; ++i) {
        if (isConsonant(word[i])) {
            ++count;
        }
    }
    return count;
}

int main() {
    char text[] = "������������� �� �++ ������ � �������!";
    char* token = strtok(text, " ,.!?;:\t\n");
    char* wordWithMaxConsonants = nullptr;
    int maxConsonants = 0;

    while (token != nullptr) {
        int consonants = countConsonants(token);
        if (consonants > maxConsonants) {
            maxConsonants = consonants;
            wordWithMaxConsonants = token;
        }
        token = strtok(nullptr, " ,.!?;:\t\n");
    }

    if (wordWithMaxConsonants != nullptr) {
        std::cout << "����� � ��������� ������� �����������: " << wordWithMaxConsonants << std::endl;
    }
    else {
        std::cout << "����� �� ��������." << std::endl;
    }

    return 0;
}
