//------------------------------------------- PART 1 ---------------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



std::vector<std::string> abdoSplit(std::string x, char delim, std::vector<std::string> y) {
    std::vector<int> delimPlaces;
    std::vector<std::string> theVector = y;

    for (int a = 0; a < x.length(); a++) {
        if (x[a] == delim) {
            delimPlaces.push_back(a);
        }
    }
    theVector.push_back(x.substr(0, delimPlaces[0]));

    for (int b = 0; b < delimPlaces.size() - 1; b++) {
        theVector.push_back(x.substr(delimPlaces[b] + 1, delimPlaces[b + 1] - delimPlaces[b]));
    }
    theVector.push_back(x.substr(delimPlaces.back() + 1));
    
    return theVector;
}

int main()
{
    std::fstream myFile;
    myFile.open("input.txt", std::fstream::in);
    std::string oneLine;

    int totalPoints = 0;

    for (int a = 0; !myFile.eof(); a++) {
        getline(myFile, oneLine);
        std::string cardnumber = oneLine.substr(0, oneLine.find(':'));
        std::string winningNumbersString = oneLine.substr(oneLine.find(':')+2,oneLine.find('|') - oneLine.find(':') - 3);
        while (winningNumbersString.find("  ") != std::string::npos) { winningNumbersString.replace(winningNumbersString.find("  "), 2, " 0");}
        if (winningNumbersString[0] == ' ') {
            winningNumbersString[0] = '0';
        }
        std::string numbersYouHaveString = oneLine.substr(oneLine.find('|') + 2);
        while (numbersYouHaveString.find("  ") != std::string::npos) { numbersYouHaveString.replace(numbersYouHaveString.find("  "), 2, " 0"); }
        if (numbersYouHaveString[0] == ' ') {
            numbersYouHaveString[0] = '0';
        }

        std::vector<std::string> splitWinningNumbers = abdoSplit(winningNumbersString, ' ', splitWinningNumbers);
        std::vector<std::string> splitNumbersYouHave = abdoSplit(numbersYouHaveString, ' ', splitNumbersYouHave);

        std::vector<int> splitWinningNumbersAsIntegers;
        std::vector<int> splitNumbersYouHaveAsIntegers;

        for (int winningNumber = 0; winningNumber < splitWinningNumbers.size(); winningNumber++) {
            splitWinningNumbersAsIntegers.push_back(stoi(splitWinningNumbers[winningNumber]));
        }
        for (int numberYouHave = 0; numberYouHave < splitNumbersYouHave.size(); numberYouHave++) {
            splitNumbersYouHaveAsIntegers.push_back(stoi(splitNumbersYouHave[numberYouHave]));
        }

        

        double cardScore = 0.5;
        for (int a = 0; a < splitWinningNumbersAsIntegers.size(); a++) {
            for (int b = 0; b < splitNumbersYouHaveAsIntegers.size(); b++) {
                if (splitWinningNumbersAsIntegers[a] == splitNumbersYouHaveAsIntegers[b]) {
                    cardScore = cardScore * 2;
                }
            }
        }
        if (cardScore > 0.5) {
            totalPoints += cardScore;
        }
    }
    
    std::cout << "Total is: " << totalPoints;
}
