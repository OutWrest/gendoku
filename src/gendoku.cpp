#include <iostream>
#include <vector>

using namespace std;

void write(vector<vector<int>> board);

int main(int argc, char *argv[]) {
    // Usage ./gendoku <how many to generate, -1 for all> <output file> -r <rules file>
    // Example ./gendoku -1 output.txt -r rules.txt

    // check if there are enough arguments
    if (argc < 3) {
        printf("Usage ./gendoku <how many to generate, -1 for all> <output file> -r <rules file>\n");
        printf("Example ./gendoku -1 output.txt -r rules.txt\n");
        return 1;
    }

    // check if the output file exists
    static FILE *f = fopen(argv[2], "r");

    if (f != NULL) {
        printf("Output file already exists.\n");
        return 1;
    }

    // check if the rules file exists
    // f = fopen(argv[4], "r");

    // if (f == NULL) {
    //     printf("Rules file does not exist.\n");
    //     return 1;
    // }

    // check if the rules file is empty
    // fseek(f, 0, SEEK_END);
    // int size = ftell(f);
    // fseek(f, 0, SEEK_SET);

    // if (size == 0) {
    //     printf("Rules file is empty.\n");
    //     return 1;
    // }

    

    return 0;
}