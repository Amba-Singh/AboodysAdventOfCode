#include <iostream>
#include <fstream>
#include <vector>

int countInstances(std::string s, char x) {int count = 0;for (int i = 0; i < s.length(); i++) {if (s[i] == x) {count++;}}return count;}

std::vector <std::string> splitstrings;
void ABDOSsplit(std::string x, char delim) { std::vector<int> delimPlaces; for (int i = 0; i < x.length(); i++) { if (x[i] == delim) { delimPlaces.push_back(i); } }for (int n = 0; n < delimPlaces.size(); n++) { splitstrings.push_back(x.substr(delimPlaces[n] + 1, (delimPlaces[n + 1]) - delimPlaces[n])); } }

std::vector<int> listIndexesToBeChecked(std::vector<int> indexesOfNumbers){
    std::vector<int> indexesToBeChecked;
    for(int i = 0 ; i < indexesOfNumbers.size() ; i++){
        indexesToBeChecked.push_back((indexesOfNumbers[i]+141));
        indexesToBeChecked.push_back((indexesOfNumbers[i]-141));
        indexesToBeChecked.push_back(indexesOfNumbers.front()-1);
        indexesToBeChecked.push_back((indexesOfNumbers.back()+1));

        indexesToBeChecked.push_back((indexesOfNumbers[i]+142));
        indexesToBeChecked.push_back((indexesOfNumbers[i]+140));
        indexesToBeChecked.push_back((indexesOfNumbers[i]-142));
        indexesToBeChecked.push_back((indexesOfNumbers[i]-140));
    }

    return indexesToBeChecked;
}

int main() {

    //getting the text input
	std::fstream myFile;
	myFile.open("day3.txt",std::fstream::in);
	std::string oneLine;
    std::vector<std::vector<char>> theList;
	//iterate through every line
	while(!myFile.eof()){
        getline(myFile,oneLine);

        //iterate through every character and add it to a temporary vector
        std::vector<char> temporaryVector;
        for(int i=0;i<oneLine.length();i++){temporaryVector.push_back(oneLine[i]);}
        theList.push_back(temporaryVector);
	}

	//iterate through every character
    for(int a=0;a<theList.size();a++){
        for(int b=0;b<theList[a].size();b++){std::cout << theList[a][b];
        //std::cout << std::endl;
        int charAsInt = theList[a][b] - '0';
        int charAfterAsInt = theList[a][b+1] - '0';
        int charAfterAfterAsInt = theList[a][b+2] - '0';
        int number;
        if(isdigit(charAsInt)){
            if(isdigit(charAfterAsInt)){
                if(isdigit(charAfterAfterAsInt)){
                    number = charAsInt*100 + charAfterAsInt*10 + charAfterAfterAsInt;}
                else{number = charAsInt*10 + charAfterAsInt;}
            }else{number = charAsInt;}
            }
        }
    }

	return 0;
}
