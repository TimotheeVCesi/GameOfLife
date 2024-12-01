#include <iostream>
#include <string>

string fileInput, fileOutput, textIn, line, textTemp, textOut;

cout << "Entrez le nom de fichier à décoder/encoder (fichier.txt)" << endl;
cin >> fileInput;

ifstream fileIn(fileInput, ios::in);

if (fileIn) {
    while (getline(fileIn, line)) {
        textIn += line + "\n";
    }

    fileIn.close();
} else {
    cerr << "Erreur à l'ouverture du fichier pour la lecture" << endl;
    return 1;
}

cout << "Entrez le nom de fichier à remplir (fichier.txt)" << endl;
cin >> fileOutput;

ofstream fileOut(fileOutput, ios::out | ios::trunc);

if (fileOut) {
    fileOut << textOut;

    fileOut.close();
} else {
    cerr << "Erreur à l'ouverture du fichier pour l'écriture" << endl;
    return 1;
}