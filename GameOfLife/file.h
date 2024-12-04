#ifndef IFILEHANDLER_H
#define IFILEHANDLER_H

class IFileHandler {
public:
    virtual ~IFileHandler() = default;
    virtual Grid load(const std::string filePath) const = 0;
    virtual void save(const Grid grid, const std::string filePath) const = 0;
};

class FileHandler : public IFileHandler {
public:
    Grid load(const std::string filePath) const override {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Erreur: impossible d'ouvrir le fichier pour charger");
        }

        int rows, columns;
        file >> rows, columns;

        Grid grid(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                bool state;
                file >> state;
                grid.setCellState(i, j, state);
            }
        }

        file.close();
        return grid;
    }

    void save(const Grid grid, const std::string filePath) const override {
        // trouver la position du dernier '/'
        std::size_t pos = filePath.find_last_of('/');

        // extraire le chemin du dossier et le nom du fichier
        std::string folderPath = filePath.substr(0, pos); // avant le dernier '/'
        std::string fileName = filePath.substr(pos + 1);  // après le dernier '/'
        std::string folderName = fileName + "_out";

        mkdir(folderName.c_str(), 0755);
        std::string OutFilePath = folderPath + "/" + folderName + "/" + "iteration_" + count.to_string(); // A CORRIGER => generation

        std::ofstream file(OutFilePath);
        if (!file.is_open()) {
            throw std::runtime_error("Erreur: impossible d'ouvrir le fichier pour sauvegarder");
        }

        file << grid.getRows() << " " << grid.getColumns() << "\n";
        for (int i = 0; i < grid.getRows(); ++i) {
            for (int j = 0; j < grid.getColumns(); ++j) {
                file << grid.getCellState(i, j) << " ";
            }
            file << "\n";
        }
    }
};

#endif


// class File { // classe abstraite
// protected:
//     std::string fileName;

// public:
//     virtual std::string actionFile() const = 0;
// };

// class GetDataFile : public File {
// public:
//     GetDataFile(std::string fileName) : fileName(fileName) {}

//     std::string actionFile() const override { // ouverture fichier et récup données
//         ifstream fileIn(fileName, ios::in); // ouverture du fichier
//         if (!fileIn) { // vérifie si le fichier est correctement ouvert
//             std::cerr << "Erreur: impossible d'ouvrir le fichier " << fileName << std::endl;
//             fileIn.close();
//             return;
//         }

//         std::string dataGrid, dataCell, line;
//         std::getline(fileIn, line); // récup 1ère ligne (rows et columns)
//         dataGrid << line;
//         while (std::getline(fileIn, line)) { // récup la grille
//             for (char c : line) {
//                 if (c != ' ') { // exclut les espaces
//                     dataCell += c;
//                 }
//             }
//         }
//         fileIn.close();
//         return dataGrid, dataCell;
//     }
// };

// class SaveDataFile : public File {
// public:
//     SaveDataFile(std::string fileName) : fileName(fileName) {}


// };