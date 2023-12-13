#include <iostream>
#include <fstream>
#include <vector>

int countInstances(std::string s, char x) {int count = 0;for (int i = 0; i < s.length(); i++) {if (s[i] == x) {count++;}}return count;}


//void ABDOSsplit(std::string x, char delim) { std::vector<int> delimPlaces; for (int i = 0; i < x.length(); i++) { if (x[i] == delim) { delimPlaces.push_back(i); } }for (int n = 0; n < delimPlaces.size(); n++) { splitstrings.push_back(x.substr(delimPlaces[n] + 1, (delimPlaces[n + 1]) - delimPlaces[n])); } }

int main() {

	// getting the input from the text file into a string
	std::string primaryString;
	std::fstream myFile;
	myFile.open("day2.txt", std::fstream::in);

	//iterating thru every line of the input
	int impossibleSum;
	for (int i = 0; !myFile.eof(); i++) {

		//altering the line
		getline(myFile, primaryString);
		primaryString.erase(0, 5);
		int locationOfColon = primaryString.find(':');
		primaryString.replace(locationOfColon,1,",");
		while (primaryString.find(";") != std::string::npos) {primaryString.replace(primaryString.find(';'),1, ",");}

		//splitting the line into a vector
        std::string x = primaryString;
        char delim = ',';
		std::vector<std::string> splitstrings;
        std::vector<int> delimPlaces;
        splitstrings.push_back(primaryString.substr(0,locationOfColon));
        for (int i = 0; i < x.length(); i++) {
                if (x[i] == delim) {
                    delimPlaces.push_back(i); } }
        for (int n = 0; n < delimPlaces.size(); n++) {
                splitstrings.push_back(x.substr(delimPlaces[n] + 1, (delimPlaces[n + 1]) - delimPlaces[n])); }

        //iterating through every item in the vector to check if possible
        bool cond = false;
		for (int i = 0; i < splitstrings.size(); i++) {

			std::string item = splitstrings[i];
			std::string numRed ;
			std::string numBlue ;
			std::string numGreen ;

			if (item.find("d") != std::string::npos){
                for(int l = 0;l < item.length();l++){if(isdigit(item[l])){numRed += item[l];}}

                if(stoi(numRed) > 12){ impossibleSum += stoi(splitstrings[0]);cond = true;}
                }
            if(cond == true){break;}

            if (item.find("b") != std::string::npos){
                for(int l = 0;l < item.length();l++){if(isdigit(item[l])){numBlue += item[l];}}
                if(stoi(numBlue) > 14){impossibleSum += stoi(splitstrings[0]);cond = true;}
                }

            if(cond == true){break;}

            if (item.find("g") != std::string::npos){
                for(int l = 0;l < item.length();l++){if(isdigit(item[l])){numGreen += item[l];}}
                if(stoi(numGreen) > 13){impossibleSum += stoi(splitstrings[0]);cond = true;}
                }
            if(cond == true){break;}
		}



	}
std::cout << "possiblesum is " << 5050-impossibleSum;
	return 0;
}
