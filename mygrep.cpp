// Nhan Phan - 24TIETOB

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <stdexcept>


using namespace std;

enum Case {
  RIVINUMERO,
  RIVILUKUMAARA,
  RIVIMOLEMMAT,
  REVERSEHAKU,
  SAMANARVOISET,
  KAIKKIOPTIOT
};

// Funktion prototype
void stringHaku(string isoString, string pieniString, int& num);
void readFile(string tekstiString, string linkkiString, string riviNum, int argc, Case& output, vector<float>& koko);
string lowerCase(string str);

int main (int argc, char *argv[]) {
  int num;
  string isoString, pieniString, tekstiString, linkkiString, riviNum;
  Case output;
  vector<float>koko;
  
  if (argc == 3) {
    tekstiString = argv[1];
    linkkiString = argv[2];
    readFile(tekstiString, linkkiString, riviNum, argc, output, koko);
  } else if(argc == 4) {
    riviNum = argv[1];
    tekstiString = argv[2];
    linkkiString = argv[3];
    readFile(tekstiString, linkkiString, riviNum, argc, output, koko);
  } else {
    cout << "1.Inkrementti: " << endl;
    
    cout << "Give a string from which to search for: ";
    getline(cin, isoString);
    cout << endl;

    cout << "Give search string: ";
    getline(cin, pieniString);
    cout << endl;

    stringHaku(isoString, pieniString, num);
    
  };

  return 0;
}



string lowerCase(string str) {
  for (char& t : str)
    t = tolower(t);
  return str;
}

// 1. Inkrementti
void stringHaku(string isoString, string pieniString, int& num) {
  num = isoString.find(pieniString);
  if(num != string::npos) {
   cout << "'" << pieniString << "' found in '" << isoString << "' in position " << num << endl;
  } else {
   cout << "'" << pieniString << "' NOT found in '" << isoString << "'" << endl;
  }
};


void readFile(string tekstiString, string linkkiString, string riviNum, int argc, Case& output, vector<float>& koko) {
  try {
    const string txtFile = "/Users/nerdylab/oep/mygrep/" + linkkiString;
    string line;
    int lineNumero = 0;
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

      // 3 & 4. Inkrementti
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
        cout << "4.Inkrementti: " << endl;
        if(riviNum == "-or") {
          output = REVERSEHAKU;
        }
        if(riviNum == "-oi") {
          output = SAMANARVOISET;
        }
        if(riviNum == "-olori") {
          output = KAIKKIOPTIOT;
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
        case REVERSEHAKU: while(getline(readFile, line)) {
          if(line.find(tekstiString) == string::npos) {
            cout << line << endl;
            found = true;
          } 
        }
        break;
        case SAMANARVOISET: 
        while(getline(readFile, line)) {
          if(lowerCase(line).find(lowerCase(tekstiString)) != string::npos) {
            cout << line << endl;
            found = true;
          } 
        }
        break;
        case KAIKKIOPTIOT: 
        while(getline(readFile, line)) {
          lineNumero++;
          if(lowerCase(line).find(lowerCase(tekstiString)) == string::npos) {
            cout << lineNumero << ": " << line << endl;
            koko.push_back(lineNumero);
            found = true;
          } 
        }
        cout << "Occurrences of lines NOT containing '" << tekstiString << "': " << koko.size() << endl;
        break;
      }

      if(!found) {
        cout << "'" << tekstiString << "' string NOT found in man_grep_plain_ASCII.txt or command line arguments were missing" << endl;
      }
      readFile.close();
    } else {
      cout << "Error: File could not be opened." << endl;
      readFile.seekg(0, ios::end);
      streamsize size = readFile.tellg();
      if (size == -1) {
        throw runtime_error("Could not find out the size of file \"" + linkkiString + "\"");
      }
    }
  }  
  catch (const runtime_error& err) { 
    cerr << "An exception occurred. Exception Nr. -1 \n" << err.what() << endl;
  }
};