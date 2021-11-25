#include "io/file.hpp"

FileIO::FileIO(const char* filename) {
    this->filename = filename;

    file = fopen(filename, "w");

    // write csv header
    fprintf(file, "id,board\n");
}

FileIO::~FileIO() {
    if (file != NULL) {
        fclose(file);
    }

    file = NULL;
}

void FileIO::write(const vector<vector<int>> board) {
    // make sure the file is open
    if (file == NULL) {
        perror("File not open");
        exit(1);
    }

    // write board to file
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            fprintf(file, "%d", board[i][j]);
        }
    }

    // write new line
    fprintf(file, "\n");
}

