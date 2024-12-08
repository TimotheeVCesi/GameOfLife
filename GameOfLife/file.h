#ifndef FILE_H
#define FILE_H

#include "headers.h"

class IGrid;

class IFileHandler {
protected:
    std::string filePath;

public:
    IFileHandler(std::string filePath) : filePath(filePath) {}
    virtual ~IFileHandler() = default;

    virtual IGrid* load() const = 0;
    virtual void save(const IGrid& grid) const = 0;
};

class FileHandler : public IFileHandler {
private:
    mutable int count = 0;

public:
    FileHandler(std::string filePath) : IFileHandler(filePath) {}

    IGrid* load() const override;
        

    void save(const IGrid& grid) const override;
};

#endif