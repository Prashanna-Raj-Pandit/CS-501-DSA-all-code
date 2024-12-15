#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

ofstream outFile("output.txt");
ifstream inFile("input.txt");

void displayInputFile(){ // displaying the sentences from input file
    string str;
    outFile<<"Original Sentence:\n";
    while(getline(inFile,str)){
        cout<<"\n"<<str<<endl;
        outFile<<str<<endl;    //copying the original sentence from input file to output file.
    }
    inFile.close();
}

int main(){

string sentence, word, replacable_word,newWord;

vector<string> words;

displayInputFile();

ifstream inFile("input.txt");

cout<<"\nEnter the word you wanna replace. (eg. 'you'->'me'):"; // getting new word from user to replace existing word
cin>>replacable_word;
cout<<"\nEnter the word you wanna replace with:";
cin>>newWord;
outFile<<"\n'"<<replacable_word<<"' is replaced by '"<<newWord<<"'"<<endl;
outFile<<"\nTranslated Sentence:\n";
if(inFile.is_open()){
while(getline(inFile,sentence)){ 
        words.clear();
        istringstream iss(sentence);
        int count=0;
while (iss >> word) {       //extract each word from iss and store in to word.
        // cout << word << endl; // Output each word on a new line
        if(word==replacable_word){
            count++;
        }
        words.push_back(word);
    }

int counter=0;

for(int i=0;i<words.size();i++){
    if(words[i]==replacable_word){
        counter++;
        if(counter==1||counter==count){
                words[i]=newWord;
        }
        
    }
}

ostringstream oss;
for(int i=0;i<words.size();i++){
    if(i>0){
        oss<<" ";
    }
    oss<<words[i];
}
string newsentence=oss.str();
cout<<newsentence<<endl;

if(outFile.is_open()){
    outFile<<newsentence<<endl; // writing the translated sentences to output file.
}else{
    cout<<"cannot open file.";
}

}
inFile.close();
outFile.close();
}else{
    cout<<"unable to read file";
}


return 0;
}

