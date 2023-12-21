//function that splits a string into strings based on a given delimeter and appends the strings to a given vector 
//no need for delimeter before or after string (havent tested what it does if so)
//declare a vector and assign its value using the function, the declared vector name is used as a paramter

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
//EXAMPLE :
    std::string x = "one two three four five";
    std::vector<std::string> splitx = abdoSplit(x, ' ', splitx);
    for (int a = 0; a < splitx.size(); a++) {
        std::cout << splitx[a] << "\n";
    }
//OUTPUT : "ONE\nTWO\nTHREE\nFOUR\nFIVE"
//-------------------------------------------------------------------------------------------------------------------------------------------------------//
