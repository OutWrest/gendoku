#include "io/file.hpp"

FileIO::FileIO(const char* filename) {
    this->filename = filename;

    // check if file exists
    file = fopen(filename, "r");

    if (file == NULL) {
        // file does not exist
        // create file
        file = fopen(filename, "w");

        // write csv header
        fprintf(file, "id,board\n");
    }

    // close file
    fclose(file);
}

FileIO::~FileIO() {
    // if file is open, close it
    if (file != NULL) {
        fclose(file);
    }

    // delete filename
    delete filename;
}

void FileIO::write(const vector<vector<int>> board) {
    // open file
    file = fopen(filename, "w");

    // write board to file
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            fprintf(file, "%d", board[i][j]);
        }
    }

    // write new line
    fprintf(file, "\n");

    // close file
    fclose(file);
}

