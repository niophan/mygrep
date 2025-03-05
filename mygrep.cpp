// Nhan Phan - 24TIETOB

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

enum Case {
  RIVINUMERO,
  RIVILUKUMAARA,
  RIVIMOLEMMAT,
};

// Funktion prototype
void string_haku(string isoString, string pieniString, int& num);
void readFile(string tekstiString, string linkkiString, string riviNum, int argc, Case& output, vector<float>& koko);

int main (int argc, char *argv[]) {
  int num;
  string isoString, pieniString, tekstiString, linkkiString, riviNum;
  Case output;
  vector<float>koko;

 
  cout << "1.Inkrementti: " << endl;

  cout << "Give a string from which to search for: ";
  getline(cin, isoString);
  cout << endl;

  cout << "Give search string: ";
  getline(cin, pieniString);
  cout << endl;
 
  string_haku(isoString, pieniString, num);

  if (argc == 3) {
    tekstiString = argv[1];
    linkkiString = argv[2];
    readFile(tekstiString, linkkiString, riviNum, argc, output, koko);
  } else if(argc == 4) {
    riviNum = argv[1];
    tekstiString = argv[2];
    linkkiString = argv[3];
    readFile(tekstiString, linkkiString, riviNum, argc, output, koko);

  } 
  // else {
  //   cout << "Run the program again with a search string in the CMD" << endl;
  //   return 1;
  // }

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


void readFile(string tekstiString, string linkkiString, string riviNum, int argc, Case& output, vector<float>& koko) {
  const string txtFile = "/Users/nerdylab/oep/mygrep/" + linkkiString;
  string line;
  int lineNumero = 0, totalLineNumero = 0;
  bool found = false;
  ifstream readFile(txtFile);
  if(readFile.is_open()) {
    // 2. Inkrementti
    if(argc == 3) {
      cout << "2.Inkrementti: " << endl;
      while(getline(readFile, line)) {
        if(line.find(tekstiString) != string::npos) {
          cout << line << endl;
          found = true;
        } 
      }
    };

    // 3. Inkrementti
    if (argc == 4) {
      cout << "3.Inkrementti: " << endl;
      if(riviNum == "-ol") {
        output = RIVINUMERO;
      }
      if(riviNum == "-oo") {
        output = RIVILUKUMAARA;
      }
      if(riviNum == "-olo") {
        output = RIVIMOLEMMAT;
      }
    }
    
    switch (output)
     {
      case RIVINUMERO: while(getline(readFile, line)) {
        lineNumero++;
        if(line.find(tekstiString) != string::npos) {
          cout << lineNumero << ": " << line << endl;
          found = true;
        } 
      }
      break;
      case RIVILUKUMAARA: while(getline(readFile, line)) {
        lineNumero++;
        if(line.find(tekstiString) != string::npos) {
          koko.push_back(lineNumero);
          found = true;
        } 
      }
      cout << "Occurrences of lines containing '" << tekstiString << "': " << koko.size() << endl;
      break;
      case RIVIMOLEMMAT: while(getline(readFile, line)) {
        lineNumero++;
        if(line.find(tekstiString) != string::npos) {
          cout << lineNumero << ": " << line << endl;
          koko.push_back(lineNumero);
          found = true;
        } 
      }
      cout << "Occurrences of lines containing '" << tekstiString << "': " << koko.size() << endl;
      break;
     }

    if(!found) {
      cout << "'" << tekstiString << "' string NOT found in man_grep_plain_ASCII.txt or command line arguments were missing" << endl;
    } 
    readFile.close();
  } else {
    cout << "Virhe: Tiedostoa ei voitu avata." << endl;
  }
};