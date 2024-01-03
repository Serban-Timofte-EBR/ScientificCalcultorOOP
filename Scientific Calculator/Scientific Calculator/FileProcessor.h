#pragma once
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

class FileProcessor {
public:
    virtual void processFile(const std::string& filePath) = 0; 
    virtual ~FileProcessor() {} 
};

#endif 
