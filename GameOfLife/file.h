class File {
protected:
    std::string fileName;

public:
    virtual void inputFile(std::string fileName) const = 0;
    virtual void outputFile(std::string fileName) const = 0;
};

class GridFile : public File {
public:
    std::string inputFile(std:string fileName) const override {
        ifstream fileIn(fileName, ios::in);
        if (!fileIn) {
            std::cerr << "Erreur: impossible d'ouvrir le fichier " << fileName << std::endl;
            fileIn.close();
            return;
        }

        std::string dataGrid, dataCell, line;
        std::getline(fileIn, line);
        dataGrid << line;
        while (std::getline(fileIn, line)) {
            for (char c : line) {
                if (c != ' ') { // Exclut les espaces
                    dataCell += c;
                }
            }
        }
        return dataGrid, dataCell;
    }

    void outputFile(std::string fileName) const {
        
    }
};