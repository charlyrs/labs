#include <iostream>
#include <string>
#include <fstream>
void output (std::string myFile){
    std::ifstream fileIn (myFile);
    std::string lines;
    while (getline(fileIn, lines)){
        std::cout << lines << '\n';
    }
    fileIn.close();


}


int main (){
    std::ifstream fileInput("input.txt");
    std::cout << "Do you want to open the file and get a file report? (Yes/No)\n";
    std::string answerToOpening;
    std::cin >> answerToOpening;
    std::ofstream fileOutput("output.txt");
    if (answerToOpening == "Yes") {
        std::cout << "Do you want to see the input file? (Yes/No)\n";
        std::string answerInputFile;
        std::cin >> answerInputFile;

        if (answerInputFile == "Yes") {
            output("input.txt");

        }
        else if (answerInputFile == "No") std::cout << "Ok\n";
        else std::cout << "You were supposed to write Yes or No\n";



        std::string previousLine, currentLine;
        int linesPassed = 0;
        int groupStartCounter = 0;
        int repeatCounter = 1;


        getline(fileInput, previousLine);

        while (getline(fileInput, currentLine)) {
            linesPassed++;
            if (previousLine == currentLine) {
                if (repeatCounter == 1) {
                    groupStartCounter = linesPassed;
                }
                repeatCounter++;
            } else {
                if (repeatCounter > 1) {

                    fileOutput << "\"" << previousLine << "\" starts to repeat from the line number "
                               << groupStartCounter
                               << " and repeats " << repeatCounter << " times\n";
                    repeatCounter = 1;
                    
                }
        

            }
            previousLine = currentLine;

        }
        if (repeatCounter > 1)  //for the last group
            fileOutput << "\"" << previousLine << "\" starts to repeat from the line number "
                       << groupStartCounter
                       << " and repeats " << repeatCounter << " times\n";

        fileOutput.close();
        std::cout << "Do you want to see the output file? Yes/No\n";
        std::string answerOutputFile;
        std::cin >> answerOutputFile;
        if (answerOutputFile=="Yes"){
            output("output.txt");
        }
        else if (answerOutputFile == "No") std::cout << "Ok\n";
        else std::cout << "You were supposed to write Yes or No\n";
        fileInput.close();

    }
    else if (answerToOpening == "No") {
        std::cout << "Ok, bye\n";
    }
    else std::cout << "You were supposed to write Yes or No\n";



    return 0;
}