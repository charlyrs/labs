#include <iostream>
#include <fstream>


int main() {
    std::ifstream fin("sample.txt");
    char str[300];
    int dates = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    if (fin.is_open()) {
        while (fin >> str) {
            if (std::strlen(str) == 10 && str[2] == '/' && str[5] == '/') {
                if (str[0] <= '9' && str[0] >= '0' && str[1] <= '9' && str[1] >= '0'
                    && str[3] <= '9' && str[3] >= '0' && str[4] <= '9' && str[4] >= '0'
                    && str[6] <= '9' && str[6] >= '0' && str[7] <= '9' && str[7] >= '0'
                    && str[8] <= '9' && str[8] >= '0' && str[9] <= '9' && str[9] >= '0') {

                    day = (str[0] - '0') * 10 + (str[1] - '0');
                    month = (str[3] - '0') * 10 + (str[4] - '0');
                    year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');

                    if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
                        dates++;
                    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
                        month == 8 || month == 10 || month == 12) && day <= 31)
                        dates++;
                    if ((month == 2 && day <= 28) || (month == 2 && year % 4 == 0 && day <= 29))
                        dates++;
                }
            }

        }
    }
    else std::cout << "File is not opened\n";
    fin.close();
    std::cout << "Found " << dates << " correct dates";

    return 0;
}