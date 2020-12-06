
#ifndef KR2_GR1_KHOMYAKOVA_LILIYA__FILE_READER_H_
#define KR2_GR1_KHOMYAKOVA_LILIYA__FILE_READER_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
class FileReader {
 public:
  vector<string> ReadLines(const string &file_path); // чтение строк из файла
  vector<string> ReadWords(const string &file_path); // вызов функции чтения строк из файла, и парсинг строк на слова
};

vector<string> FileReader::ReadWords(const string &file_path) {
  vector<string> res;
  string temp;
  std::ifstream fin(file_path);
  if (fin.is_open()) {
    while (fin >> temp) {
      res.push_back(temp);
    }
  }
  fin.close();
  return res;
}
vector<string> FileReader::ReadLines(const string &file_path) {
  vector<string> res;
  std::ifstream fin(file_path);
  string temp;
  if (fin.is_open()) {
    while (getline(fin, temp)) {
      res.push_back(temp);
    }
  }
  fin.close();
  return res;
}

#endif //KR2_GR1_KHOMYAKOVA_LILIYA__FILE_READER_H_
