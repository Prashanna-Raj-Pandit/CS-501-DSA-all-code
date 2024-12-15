#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Helper function to check if the given position is a word boundary
bool isWordBoundary(const string &line, int pos, int wordLength) {
    // Check if the character before `pos` is a non-alphanumeric character or if it's the start of the line
    if (pos != 0 && isalnum(line[pos - 1])) {
        return false;
    }
    // Check if the character after `pos + wordLength - 1` is a non-alphanumeric character or if it's the end of the line
    if (pos + wordLength < line.length() && isalnum(line[pos + wordLength])) {
        return false;
    }
    return true;
}

// Function to replace the first and last occurrence of a word in a line
string replaceFirstAndLastOccurrence(string line, const string &word1, const string &word2) {
    int wordLength = word1.length();
    int firstPos = -1;
    int lastPos = -1;

    // Find the first and last occurrences with word boundaries
    for (int i = 0; i <= line.length() - wordLength; ++i) {
        if (line.substr(i, wordLength) == word1 && isWordBoundary(line, i, wordLength)) {
            if (firstPos == -1) {
                // This is the first occurrence
                firstPos = i;
            }
            // Update lastPos on every match
            lastPos = i;
        }
    }

    // Replace the first occurrence
    if (firstPos != -1) {
        line.replace(firstPos, wordLength, word2);
        // Adjust lastPos if necessary (if word2 has a different length than word1)
        if (word2.length() != word1.length()) {
            lastPos += word2.length() - word1.length();
        }
    }

    // Replace the last occurrence if it's not the same as the first
    if (lastPos != -1 && lastPos != firstPos) {
        line.replace(lastPos, wordLength, word2);
    }

    return line;
}

int main() {
    ifstream inFile("HW1in.txt");
    ofstream outFile("HW1out.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string word1, word2;
    cout << "Enter the first word: ";
    cin >> word1;
    
    cout << "Enter the second word: ";
    cin >> word2;

    string line;

    // Write original text to the output file
    outFile << "Original text:\n";

    // Read and write each line from the input file to the output file
    while (getline(inFile, line)) {
        outFile << line << '\n'; // Write original line
    }

    // Go back to the start of the file for processing
    inFile.clear();
    inFile.seekg(0);

    // Write translated text to the output file
    outFile << "\nTranslated text:\n";

    // Process each line for replacements
    while (getline(inFile, line)) {
        string translatedLine = replaceFirstAndLastOccurrence(line, word1, word2);
        outFile << translatedLine << '\n'; // Write translated line
    }

    // Close files
    inFile.close();
    outFile.close();

    return 0;
}
