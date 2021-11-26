#include <iostream>
#include <fstream>
#include <vector>

namespace FileIO {
    class Dataset {
        public:
            friend std::istream &operator>>(std::istream &is, Dataset &set);

            std::vector<std::vector<string>> GetData();
        
        private:
            std::vector<std::vector<string>> airports_;
    };
}