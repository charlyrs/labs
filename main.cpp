#include <iostream>
#include <fstream>

//this version counts correct dates for each string

// I have another which counts correct dates from the whole file in the commit "bissextile year"
int mystrlen(const char* str)  //in case if strlen is forbidden
{
    int count = 0;
    while (*str++) ++count;
    return count;
}
int main() {
    std::ifstream fin("sample.txt");
    char str[300];
    int dates = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    int count = 1;
    if (fin.is_open()) {
        while (fin.getline(str, 300)) {  //reads each string
            dates = 0;
            char word[300];
            int length = mystrlen(str);
            int index = 0;
            for (int i = 0; i <= length; ++i) {
                if (std::strlen(word) == 10 && word[2] == '/' && word[5] == '/') {
                    if (word[0] <= '9' && word[0] >= '0' && word[1] <= '9' && word[1] >= '0'
                        && word[3] <= '9' && word[3] >= '0' && word[4] <= '9' && word[4] >= '0'
                        && word[6] <= '9' && word[6] >= '0' && word[7] <= '9' && word[7] >= '0'
                        && word[8] <= '9' && word[8] >= '0' && word[9] <= '9' && word[9] >= '0') {

                        day = (word[0] - '0') * 10 + (word[1] - '0');
                        month = (word[3] - '0') * 10 + (word[4] - '0');
                        year = (word[6] - '0') * 1000 + (word[7] - '0') * 100 + (word[8] - '0') * 10 + (word[9] - '0');
                        //checks if the date is correct
                        if ((month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
                            dates++;
                        if ((month == 1 || month == 3 || month == 5 || month == 7 ||
                            month == 8 || month == 10 || month == 12) && day <= 31)
                            dates++;
                        if ((month == 2 && day <= 28) || (month == 2 && year % 4 == 0 && day <= 29))
                            dates++;
                        for (int k = 0; k < 300; ++k) {
                            word[k] = '\0';
                        }
                    }
                }
                if (str[i] == ' ') {
                    word[index] = '\0';
                    if (index > 0) {
                        index = 0;
                    }
                    continue;
                }

                word[index] = str[i]; //rewriting words to an array
                index++;


            }


            std::cout << "Found " << dates << " correct dates in string number " << count << std::endl;
            count++;
        }
    }
    else std::cout << "File is not opened\n";
    fin.close();


    return 0;
}