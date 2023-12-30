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
    std::string x = "onetwo";
    std::string y = "onetwo";
    
    
    std::fstream myFile;
    myFile.open("input.txt", std::fstream::in);
    std::string oneLine;

    int totalPoints = 0;
    std::vector<std::string> allCards;


    for (int a = 0; !myFile.eof(); a++) {
        getline(myFile, oneLine);
        allCards.push_back(oneLine);
    }
    std::vector <std::vector<std::string>> yeee;

    
    for (int oneLine = 0; oneLine < allCards.size(); oneLine++) {
        //std::cout << allCards[oneLine] << "\n";
        std::string cardnumber = allCards[oneLine].substr(0, allCards[oneLine].find(':'));
        std::string winningNumbersString = allCards[oneLine].substr(allCards[oneLine].find(':')+2,allCards[oneLine].find('|') - allCards[oneLine].find(':') - 3);
        while (winningNumbersString.find("  ") != std::string::npos) { winningNumbersString.replace(winningNumbersString.find("  "), 2, " 0");}
        if (winningNumbersString[0] == ' ') {
            winningNumbersString[0] = '0';
        }
        std::string numbersYouHaveString = allCards[oneLine].substr(allCards[oneLine].find('|') + 2);
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

        int  cardWins = 0;
        double cardScore = 0.5;
        for (int a = 0; a < splitWinningNumbersAsIntegers.size() ; a++) {
            for (int b = 0; b < splitNumbersYouHaveAsIntegers.size(); b++) {
                if (splitWinningNumbersAsIntegers[a] == splitNumbersYouHaveAsIntegers[b]) {
                    cardScore = cardScore * 2;
                    cardWins++;
                }
            }
        }


        if (cardScore > 0.5) {
            totalPoints += cardScore;
        }
        std::vector<std::string> tempVector = { cardnumber, winningNumbersString, numbersYouHaveString };
        yeee.push_back(tempVector);

        for (int x = 0; x < yeee.size(); x++) {
            if (yeee[x][0] == cardnumber) {

                for (int win = 1; win < cardWins + 1; win++) {
                    std::vector<std::string> tempVector2 = { allCards[oneLine + win].substr(0, allCards[oneLine + win].find(':')) , "hi" };
                    yeee.push_back(tempVector2);

                }
            }
        }

        std::cout <<"for loop iteration : " << oneLine << "   card wins are : " << cardWins<< "\n";
    }



    std::cout << "Total is: " << totalPoints;
    std::cout << "Number of cards is : " << yeee.size(); 
}
