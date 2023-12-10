#include <iostream>
#include <typeinfo>
#include <cctype>
#include <sstream>
#include <fstream>
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



/*
---------------------------------------------------------------------------------------------------------------------------
*/
                              // PART 2

#include <iostream>
#include <typeinfo>
#include <cctype>
#include <sstream>
#include <fstream>
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




    std::string  zero = "zero";
    std::string  one  = "one";
    std::string  two  = "two";
    std::string  three= "three";
    std::string  four = "four";
    std::string  five = "five";
    std::string  six  = "six";
    std::string  seven= "seven";
    std::string  eight= "eight";
    std::string  nine = "nine";

    if(MainString.find(zero) !=std::string::npos){int zerosplace = MainString.find(zero); MainString.replace(zerosplace,zero.length(),"z0o");};
    if(MainString.find(one)  !=std::string::npos){int onesplace = MainString.find(one)  ; MainString.replace(onesplace,one.length(),"o1e")  ;};
    if(MainString.find(two) !=std::string::npos){ int twosplace = MainString.find(two);MainString.replace(twosplace,two.length(),"t2o");};
    if(MainString.find(three) !=std::string::npos){int threesplace = MainString.find(three);MainString.replace(threesplace,three.length(),"t3e");};
    if(MainString.find(four) !=std::string::npos){int foursplace = MainString.find(four);MainString.replace(foursplace,four.length(),"f4r");};
    if(MainString.find(five) !=std::string::npos){int fivesplace = MainString.find(five);MainString.replace(fivesplace,five.length(),"f5e");};
    if(MainString.find(six) !=std::string::npos){int sixsplace = MainString.find(six);MainString.replace(sixsplace,six.length(),"s6x");};
    if(MainString.find(seven) !=std::string::npos){int sevensplace = MainString.find(seven);MainString.replace(sevensplace,seven.length(),"s7n");};
    if(MainString.find(eight) !=std::string::npos){int eightsplace = MainString.find(eight);MainString.replace(eightsplace,eight.length(),"e8t");};
    if(MainString.find(nine) !=std::string::npos){int ninesplace = MainString.find(nine);MainString.replace(ninesplace,nine.length(),"n9e");};

    if(MainString.find(zero) !=std::string::npos){int zerosplace = MainString.find(zero); MainString.replace(zerosplace,zero.length(),"z0o");};
    if(MainString.find(one)  !=std::string::npos){int onesplace = MainString.find(one)  ; MainString.replace(onesplace,one.length(),"o1e")  ;};
    if(MainString.find(two) !=std::string::npos){ int twosplace = MainString.find(two);MainString.replace(twosplace,two.length(),"t2o");};
    if(MainString.find(three) !=std::string::npos){int threesplace = MainString.find(three);MainString.replace(threesplace,three.length(),"t3e");};
    if(MainString.find(four) !=std::string::npos){int foursplace = MainString.find(four);MainString.replace(foursplace,four.length(),"f4r");};
    if(MainString.find(five) !=std::string::npos){int fivesplace = MainString.find(five);MainString.replace(fivesplace,five.length(),"f5e");};
    if(MainString.find(six) !=std::string::npos){int sixsplace = MainString.find(six);MainString.replace(sixsplace,six.length(),"s6x");};
    if(MainString.find(seven) !=std::string::npos){int sevensplace = MainString.find(seven);MainString.replace(sevensplace,seven.length(),"s7n");};
    if(MainString.find(eight) !=std::string::npos){int eightsplace = MainString.find(eight);MainString.replace(eightsplace,eight.length(),"e8t");};
    if(MainString.find(nine) !=std::string::npos){int ninesplace = MainString.find(nine);MainString.replace(ninesplace,nine.length(),"n9e");};

    if(MainString.find(zero) !=std::string::npos){int zerosplace = MainString.find(zero); MainString.replace(zerosplace,zero.length(),"z0o");};
    if(MainString.find(one)  !=std::string::npos){int onesplace = MainString.find(one)  ; MainString.replace(onesplace,one.length(),"o1e")  ;};
    if(MainString.find(two) !=std::string::npos){ int twosplace = MainString.find(two);MainString.replace(twosplace,two.length(),"t2o");};
    if(MainString.find(three) !=std::string::npos){int threesplace = MainString.find(three);MainString.replace(threesplace,three.length(),"t3e");};
    if(MainString.find(four) !=std::string::npos){int foursplace = MainString.find(four);MainString.replace(foursplace,four.length(),"f4r");};
    if(MainString.find(five) !=std::string::npos){int fivesplace = MainString.find(five);MainString.replace(fivesplace,five.length(),"f5e");};
    if(MainString.find(six) !=std::string::npos){int sixsplace = MainString.find(six);MainString.replace(sixsplace,six.length(),"s6x");};
    if(MainString.find(seven) !=std::string::npos){int sevensplace = MainString.find(seven);MainString.replace(sevensplace,seven.length(),"s7n");};
    if(MainString.find(eight) !=std::string::npos){int eightsplace = MainString.find(eight);MainString.replace(eightsplace,eight.length(),"e8t");};
    if(MainString.find(nine) !=std::string::npos){int ninesplace = MainString.find(nine);MainString.replace(ninesplace,nine.length(),"n9e");};

    std::cout << MainString << std::endl ;
    for (int i = 0; i < MainString.length();i++){

        if(isdigit(MainString[i])){
            myList.push_back((MainString[i]));
        }

    }


            std::cout << std::endl;
            int firstNumber = (*myList.begin() - '0')* 10;

            int secondNumber = (*(myList.end()-1)  - '0');
            int doubledigitnumber = firstNumber + secondNumber;
            Sum += doubledigitnumber;
            std::cout << doubledigitnumber << std::endl;


}

std::cout << Sum;

return 0;
}

