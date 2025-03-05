// Nhan Phan - 24TIETOB

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;


// Funktion prototype
void string_haku(string isoString, string pieniString, int& num);
void readFile(string tekstiString, string linkkiString, string riviNum, int argc);

int main (int argc, char *argv[]) {
  int num;
  string isoString, pieniString, tekstiString, linkkiString, riviNum;

 
  cout << "1.Inkrementti: " << endl;

  cout << "Give a string from which to search for: ";
  getline(cin, isoString);
  cout << endl;

  cout << "Give search string: ";
  getline(cin, pieniString);
  cout << endl;
 
  string_haku(isoString, pieniString, num);

  cout << "2.Inkrementti: " << endl;

  if (argc == 3) {
    tekstiString = argv[1];
    linkkiString = argv[2];
  } 
  // else {
  //   cout << "Run the program again with a search string in the CMD" << endl;
  //   return 1;
  // }

  readFile(tekstiString, linkkiString, riviNum, argc);
  
}

// 1. Inkrementti
void string_haku(string isoString, string pieniString, int& num) {
  num = isoString.find(pieniString);
  if(num != string::npos) {
    cout << "'" << pieniString << "' found in '" << isoString << "' in position " << num << endl;
  } else {
   cout << "'" << pieniString << "' NOT found in '" << isoString << "'" << endl;
  }
};

// 2. Inkrementti
void readFile(string tekstiString, string linkkiString, string riviNum, int argc) {
  const string txtFile = "/Users/nerdylab/oep/mygrep/" + linkkiString;
  string line;
  int lineNumero = 0, totalLineNumero = 0;
  bool found = false;
  ifstream readFile(txtFile);
  if(readFile.is_open()) {
    // Tähän laitetaan if -olo, 4 tapauksia
    if(argc == 3) {
      while(getline(readFile, line)) {
        if(line.find(tekstiString) != string::npos) {
          cout << line << endl;
          found = true;
        } 
      }
      if(!found) {
        cout << "'" << tekstiString << "' NOT found in man_grep_plain_ASCII.txt" << endl;
      }
    } 
    
    readFile.close();
  } else {
    cout << "Virhe: Tiedostoa ei voitu avata." << endl;
  }
};