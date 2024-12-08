#include "file.h"

IGrid* FileHandler::load() const{
    std::ifstream file(filePath, std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur: impossible d'ouvrir le fichier pour charger");
    }

    int rows, columns;
    file >> rows >> columns;
    if (file.fail() || rows <= 0 || columns <= 0) {
        throw std::runtime_error("Erreur: dimensions invalides dans le fichier");
    }

    auto* grid = new GridClassic(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            bool state;
            file >> state;
            if (file.fail()) {
                delete grid;
                throw std::runtime_error("Erreur: données invalides dans le fichier");
            }
            grid->setCellState(i, j, state);
        }
    }

    file.close();
    return grid;
}

void FileHandler::save(const IGrid& grid) const{
    std::size_t posSlash = filePath.find_last_of('/');
    std::size_t posExt = filePath.find_last_of('.');
    std::string folderPath = filePath.substr(0, posSlash + 1);
    std::string fileName = filePath.substr(posSlash + 1, posExt);
    std::string folderName = fileName + "_out";
    std::string folder = folderPath + folderName;
    std::string OutFilePath = folderPath + folderName + "/iteration_" + std::to_string(count) + ".txt";

    if (mkdir(folder.c_str(), 0755) != 0 && errno != EEXIST) {
        throw std::runtime_error("Erreur: impossible de créer le dossier de sauvegarde");
    }

    std::ofstream file(OutFilePath, std::ios::out | std::ios::trunc);
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

    file.close();
    count++;
}