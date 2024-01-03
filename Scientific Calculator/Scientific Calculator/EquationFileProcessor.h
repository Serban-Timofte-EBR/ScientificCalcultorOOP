#pragma once
#ifndef EQUATIONFILEPROCESSOR_H
#define EQUATIONFILEPROCESSOR_H

#include "FileProcessor.h"

class EquationFileProcessor : public FileProcessor {
public:
    void processFile(const std::string& filePath) override;
};

#endif
