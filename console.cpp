/**
 * @file console.cpp
 * @author Nicky Kriplani
 * @brief See if you can figure out what will happen when this code is compiled and ran on a Windows system!
 * @date 2022-07-18
 */
#include <fstream>
using namespace std;
const string FILENAME = "\x63\x6f\x6e\x2e\x74\x78\x74";

struct main {
    main(ofstream *const textfile = new ofstream)
    { operator<<(textfile->operator=(ofstream(FILENAME)), 
    FILENAME);delete textfile;}}textfile;

int main() {}