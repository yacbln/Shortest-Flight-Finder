#include "dataset.h"

using std::vector;
using std::string;
using std::getline;

namespace FileIO {
    std::vector<std::vector<string>> Dataset::GetData() {
        return airports_;
    }
    
    std::istream &operator>>(std::istream &is, Dataset &set) {
        vector<string> line;
        
        while (!is.eof()) {
            getline(is, line, '\n');
            set.airports_.push_back(line);
        }
        return is;
    }
}