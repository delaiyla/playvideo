#include <iostream>
#include <fstream>
#include <cstdlib>
// Просмотр одновременно нескольких видеопотоков и/или файлов из плейлиста
int main() {
    std::ifstream inputFile("playlist.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input file" << std::endl;
        return 1;
    }

    std::string stream;
    while (std::getline(inputFile, stream)) {
        std::string command = "ffplay -i " + stream;
    // Если нужно посмотреть видео последовательно из плейлиста
    //  system(command.c_str());
 #if defined(_WIN32)
        system(("start cmd.exe @cmd /k " + command).c_str());
 #else
		system(("screen -d -m -S jabber " + command).c_str());
 #endif
    }

    inputFile.close();

    return 0;
}