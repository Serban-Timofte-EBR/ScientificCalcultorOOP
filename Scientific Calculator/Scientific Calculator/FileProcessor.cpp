class FileProcessor {
public:
    virtual void processFile(const std::string& filePath) = 0;
    virtual ~FileProcessor() {} 
};
