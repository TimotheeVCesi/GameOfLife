#ifndef FILE_H
#define FILE_H

#include "grid.h"

class IFileHandler {
public:
    virtual ~IFileHandler() = default;
    virtual IGrid* load(const std::string& filePath) const = 0;
    virtual void save(const IGrid& grid, const std::string& filePath) const = 0;
};

class FileHandler : public IFileHandler {
private:
    mutable int count = 0;

public:
    IGrid* load(const std::string& filePath) const override {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Erreur: impossible d'ouvrir le fichier pour charger");
        }

        int rows, columns;
        file >> rows >> columns;

        auto* grid = new GridClassic(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                bool state;
                file >> state;
                grid->setCellState(i, j, state);
            }
        }

        file.close();
        return grid;
    }

    void save(const IGrid& grid, const std::string& filePath) const override {
        std::size_t posSlash = filePath.find_last_of('/');
        std::size_t posExt = filePath.find_last_of('.');
        std::string folderPath = filePath.substr(0, posSlash);
        std::string fileName = filePath.substr(posSlash + 1, posExt);
        std::string folderName = fileName + "_out";

        if (mkdir(folderName.c_str(), 0755) != 0 && errno != EEXIST) {
            throw std::runtime_error("Erreur: impossible de créer le dossier de sauvegarde");
        }

        std::string OutFilePath = folderPath + "/" + folderName + "/iteration_" + std::to_string(count) + ".txt";

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

        file.close();
        count++;
    }
};

#endif