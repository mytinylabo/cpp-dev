#pragma once

#include <iostream>
#include <cstdlib>
#include <fstream>

namespace input_helper {

    /**
     * Redicrect a text file to STDIN
     */
    void redirect_from(const char* filename)
    {
        static std::ifstream in;
        if (const char* input_dir = std::getenv("INPUT_FILE_DIR")) {
            auto infile = std::string(input_dir) + "/" + filename;
            in = std::ifstream(infile);
            std::cin.rdbuf(in.rdbuf());
        }
    }

}
