#include "functions.h"
#include <iostream>
#include <vector>
using namespace std;


bool check_length(vector<int> numbers){
    if (numbers.size() ==  7){
        return true;
    }
    else return false;
}

void print_numbers(vector<int> numbers){
    for (int i = 0; i < numbers.size(); ++i){
        cout << numbers[i] << ' ';
    }
    cout << '\n';
}

struct generate_random{
    int range;
    public:
    generate_random(int r = 1) : range(r){}
    double operator()() {
        return (rand()/(int)RAND_MAX) * range;
    }
};



int main(){

    std::vector<int> test {1,2,3,4,5,6,7};
    print_numbers(test);



    return 0;
}