#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
std::string ConsoleReader (std::string msg){
    std::cout << msg << '\n';
    std::string str;
    std::cin >> str;
    return str;
}
bool IsNotDecreasingOrder (std::string a){
    bool answer;
    int count1=0;
    int count2=0;
    if (a.length()<3) return true;
    else {
        for (int i = 0; i < a.length() - 2; i += 2) {
            count1++;

            if (a[i] <= a[i + 2]) {
                count2++;
            }
        }
        if (count1 == count2 && count1 != 0 && count2 != 0) answer = true;
        else answer = false;
        return answer;
    }
}
std::vector<std::string> FileReader (std::string input_file){
    std::vector<std::string> filecons;

    std::ifstream fileInput (input_file);

    std::string temp;
    while (getline(fileInput, temp)){

        filecons.push_back(temp);
        temp.clear();

    }
    fileInput.close();
    return filecons;
}
std::vector<std::string> WordParser (std::vector <std::string> lines){
    std::vector<std::string> words;
    for (int i=0; i < lines.size(); ++i){

        std::stringstream ss(lines[i]);
        std::string word;
        while (ss >> word) {
            words.push_back(word);
            word.clear();
        }

    }

    return words;
}
std::vector <std::string> FindItems(std::vector<std::string> Items){
    std::vector <std::string> FoundItems;
    Items=WordParser(Items);
    for (int i=0; i<Items.size(); ++i){
        if (IsNotDecreasingOrder(Items[i]))
            FoundItems.push_back(Items[i]);
    }
    return FoundItems;
}
int WordWeight(std::string a){
    int sum=0;
    for (int i=0; i<a.size(); ++i){

       if ( ((a[i] & (1<<2)) != 0) && ((a[i] & (1<<2)) != 0) ) sum+=a[i];
    }
    return sum;
}
int WordWeight (std::vector<std::string> a){
    a=WordParser(a);
    int sum=0;
    for (int i=0; i<a.size(); ++i){
        sum += WordWeight(a[i]);
    }
    return sum;
}
std::map<std::string, int> MapWeight (std::vector<std::string> b){
    b=FindItems(b);
    std::map <std::string, int> mapw;
    for (int i=0; i<b.size(); ++i){

        mapw[b[i]]=WordWeight(b[i]);

    }
    return mapw;
}
void FileWriter (std::map<std::string, int> b){
    std::ofstream fout ("output.txt");
    std::map <std::string , int> :: iterator it = b.begin();
    for (; it != b.end(); it++){
        fout.width(28);
        fout << it->first << " ";
        fout << it -> second << '\n';
    }
    fout.close();
}
std::vector<std::string> SortColl(std::vector<std::string>& a){
    a=WordParser(a);
    for (int i = 0; i < a.size() - 1; i++) {
        for (int j = 0; j < a.size() - 1; j++) {
            if (WordWeight(a[j]) > WordWeight(a[j + 1])) {
                std::swap(a[j], a[j+1]);
            }
        }
    }
    return a;
}
void Encryption (std::string file_path, unsigned char key){
    std::ofstream fout(file_path+"_encr.txt");
    std::vector<std::string> sss=FileReader("output.txt");
    sss=WordParser(sss);
    std::string temp;
    for (int k=0; k<sss.size(); ++k) {
        std::string temp=sss[k];
        for (int i = 0; i < temp.size(); ++i) {
            char n = (temp[i] ^ key);
            fout << n;
        }
        std::cout << '\n';
    }
    fout.close();
}
int main() {
    std::vector<std::string> v=FileReader("input.txt");
   std::vector<std::string> d=WordParser(v);
   std::vector<std::string> m=FindItems(v);
   std::cout << v[0] << '\n';
   std::cout << d[0] << '\n';
   std::cout << m[0] << '\n';

   std::cout << WordWeight(v);

   SortColl(v);
   FileWriter(MapWeight(v));
   



    return 0;
}
