#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

// Function to replace the first and last occurrence of a word in a line
string replaceFirstAndLastOccurrence(string line, const string &word1, const string &word2)
{
    int wordLength = word1.length();
    bool foundFirst = false;
    int firstPos = -1;
    int lastPos = -1;

    // Find the first and last occurrences
    for (int i = 0; i <= line.length() - wordLength; ++i)
    {
        if (line.substr(i, wordLength) == word1)
        {
            if (!foundFirst)
            {
                // This is the first occurrence
                firstPos = i;
                foundFirst = true;
            }
            // Update lastPos on every match
            lastPos = i;
        }
    }

    // Replace the first occurrence
    if (firstPos != -1)
    {
        line.replace(firstPos, wordLength, word2);
    }

    // Replace the last occurrence if it's not the same as the first
    if (lastPos != -1 && lastPos != firstPos)
    {
        line.replace(lastPos, wordLength, word2);
    }

    return line;
}

int main()
{
    ifstream inFile("C:/Users/Simran/Desktop/CCoding/HW1in.txt");
    ofstream outFile("C:/Users/Simran/Desktop/CCoding/HW1out.txt");

    if (!inFile.is_open() || !outFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Enter the second word: ";
    cin >> word2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    string line;

    // Write original text to the output file
    outFile << "Original text:\n";

    // Read and write each line from the input file to the output file
    while (getline(inFile, line))
    {
        outFile << line << '\n'; // Write original line
    }

    // Go back to the start of the file for processing
    inFile.clear();
    inFile.seekg(0);

    // Write translated text to the output file
    outFile << "\nTranslated text:\n";

    // Process each line for replacements
    while (getline(inFile, line))
    {
        string translatedLine = replaceFirstAndLastOccurrence(line, word1, word2);
        outFile << translatedLine << '\n'; // Write translated line
    }

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}
