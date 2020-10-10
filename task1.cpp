#include <iostream>
#include <fstream>
char *analogstrchr(const char *str, char symbol) {
    while (*str != symbol) {
        if (!*str++) return nullptr;
    }
    return (char *)str;
}
int main() {
    std::ifstream fin ("function.txt");
    char str[300];
    fin >> str;
    char symbol;
    std::cout<<"Enter symbol\n";
    std :: cin >> symbol;
    std::cout << analogstrchr(str, symbol);
    fin.close();

    return 0;
}
