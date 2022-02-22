#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

// argv[1] - input file
int main(int argc, char* argv[]) {
    std::ofstream angles("calc_ang.txt", std::ios::out);
    std::ifstream pi(argv[1]); 
    std::string line;
    getline(pi, line);
    while (line != "") {
        double ang[3];
        for (int i = 0; i < 3; i++) {
            int d_pos = line.find(' ');
            ang[i] = std::stod(line.substr(0, d_pos));
            line.erase(0, d_pos + 1);
        }
        angles << 2 * sin(ang[0]) * sin(ang[1]) + cos(ang[2]) << '\n'; 
        getline(pi, line);
    }
    angles.close();
    pi.close();
    return 0;
}