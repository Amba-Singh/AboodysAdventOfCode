				//          	PART 1
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::vector<char>>  theList;
std::vector<int> indexesToBeChecked;

std::vector<int> returnindexesToBeChecked(std::vector<int> x) {
    std::vector<int> tempindexes;
    if (!(x.front() == 0)) { tempindexes.push_back(x.front() - 1); tempindexes.push_back(x.front());}else{ tempindexes.push_back(x.front()); }
    if (!(x.back() == 139)) { tempindexes.push_back(x.back() + 1); tempindexes.push_back(x.back());}else{ tempindexes.push_back(x.back()); }
    if (x.size() == 3) {tempindexes.push_back(x[1]);}
    return tempindexes;
}


int main()
{
    std::fstream ff;
    ff.open("day3.txt", std::fstream::in);

    std::string oneLine;
    for (int a = 0;!ff.eof(); a++) {
        getline(ff, oneLine);
        std::vector<char> tempvector;
        for (int b = 0; b < oneLine.length(); b++) {
            tempvector.push_back(oneLine[b]);
        }
        theList.push_back(tempvector);
    }
    int total = 0;

    for (int a = 0; a < theList.size(); a++) {
        for (int b = 0; b < theList[a].size(); b++) {
            bool cond = false;
            int threeDigitNumber;
            std::vector<int> indexes;
            //std::cout << theList[a][b];
            if (isdigit(theList[a][b]) && cond == false && b != 139 && b != 138) {
                if (isdigit(theList[a][b+1]) && cond == false && b != 139) {
                    if (isdigit(theList[a][b + 2]) && cond == false) {
                        threeDigitNumber = (theList[a][b] - '0') * 100 + (theList[a][b+1] - '0') * 10 + (theList[a][b+2] - '0');
                        std::cout << threeDigitNumber << std::endl;
                        theList[a][b] = '.';
                        theList[a][b + 1] = '.';
                        theList[a][b + 2] = '.';
                        indexes.push_back(b);
                        indexes.push_back(b+1);
                        indexes.push_back(b+2);
                        std::vector<int> indexesToBeChecked = returnindexesToBeChecked(indexes);
                        for (int index = 0; index < indexesToBeChecked.size(); index++) {
                            if (a != 0 && a < (theList.size()-1)) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.' || theList[a-1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else if (a == 0) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a - 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        threeDigitNumber = (theList[a][b] - '0') * 10 + (theList[a][b + 1] - '0');
                        std::cout << threeDigitNumber << std::endl;
                        theList[a][b] = '.';
                        theList[a][b + 1] = '.';
                        indexes.push_back(b);
                        indexes.push_back(b+1);
                        std::vector<int> indexesToBeChecked = returnindexesToBeChecked(indexes);
                        for (int index = 0; index < indexesToBeChecked.size(); index++) {
                            if (a != 0 && a < (theList.size() - 1)) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.' || theList[a - 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else if (a == 0) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a - 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                        }
                    }
                }
                else {
                    threeDigitNumber = theList[a][b] - '0';
                    std::cout << threeDigitNumber << std::endl;
                    theList[a][b] = '.';
                    indexes.push_back(b);
                    std::vector<int> indexesToBeChecked = returnindexesToBeChecked(indexes);
                                            for (int index = 0; index < indexesToBeChecked.size(); index++) {
                            if (a != 0 && a < (theList.size()-1)) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.' || theList[a-1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else if (a == 0) {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a + 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                            else {
                                if (theList[a][indexesToBeChecked[index]] != '.' || theList[a - 1][indexesToBeChecked[index]] != '.') {
                                    std::cout << "Hello\n";
                                    total += threeDigitNumber;
                                    break;
                                }
                            }
                        }
                }
            }
        }
        std::cout << "\n";
    }
    std::cout << "total is " << total;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------

