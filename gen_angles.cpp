#include <iostream>
#include <cmath>
#include <ctime>
#include <fstream>

const int PI_NUM = 3;

double rand_double(double min, double max) {
    double num = (double)rand() / RAND_MAX;
    return min + num * (max - min);
}

void gen_rands(double* arr) {
    for (int i = 0; i < PI_NUM; i++) {
        arr[i] = rand_double(-M_PI, M_PI);
    }
}

void write_rands(double* arr, std::ofstream& file) {
    for (int i = 0; i < PI_NUM; i++) {
        file << arr[i] << ' ';
    }
    file << '\n';
}

// argv[1] - number, argv[2] - output file
int main(int argc, char* argv[]) {
    std::string out_name, out_num;
    if (argc == 1) {
        out_name = "gen_ang.txt";
        out_num = "10";
    } 
    else {
        out_name = argv[2];
        out_num = argv[1];
    }
    srand(time(NULL));
    std::ofstream out_file(out_name, std::ios::out);  
    double arr[PI_NUM];
    int set_num = std::stoi(out_num);
    for (int i = 0; i < set_num; i++) {
        gen_rands(&arr[0]);
        write_rands(&arr[0], out_file);
    }
    out_file.close();
    return 0;
}