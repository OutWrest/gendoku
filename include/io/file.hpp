#ifndef IO_FILEIO_HPP
#define IO_FILEIO_HPP

using namespace std;

#include <fstream>
#include <iostream>
#include <vector>

class FileIO {
public:
    // constructor
    FileIO(const char* filename);

    // destructor
    ~FileIO();

    // read file
    // bool read(vector<vector<int>>& data);

    // write file
    void write(const vector<vector<int>> board);
private:
    FILE* file;
    const char* filename;
};

#endif // IO_FILEIO_HPP