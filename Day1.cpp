#include <iostream>
#include <typeinfo>
#include <cctype>
#include <sstream>
#include <vector>

int main(){
std::fstream myFile;
myFile.open("inputday1.txt", std::fstream::in);
if (myFile.fail()){
    std::cout << "Failed to open file "<< std::endl;
}
double Sum;
std::string MainString;
while(!myFile.eof()){
    std::vector<char> myList;
    getline(myFile, MainString);
    for (int i = 0; i < MainString.length();i++){
        if(isdigit(MainString[i])){
            myList.push_back((MainString[i]));
        }
    }
            for(char num:myList){
            std::cout << num ;}

            std::cout << std::endl;
            int firstNumber = (*myList.begin() - '0')* 10;
            int secondNumber = (*(myList.end()-1)  - '0');
            int doubledigitnumber = firstNumber + secondNumber;
            std::cout << firstNumber << "    " << secondNumber << std::endl;
            Sum += doubledigitnumber;
}
std::cout << Sum;
}
