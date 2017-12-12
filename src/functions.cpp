#include "functions.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;




bool check_length(vector<int> numbers){
    if (numbers.size() ==  6){
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

void fill_random_numbers(vector<int> &numbers){
    if (check_length(numbers)){
        std::random_device rdev;
        std::mt19937 rgen(rdev());
        std::uniform_int_distribution<int> idist(1,49); 

        for (int i = 0; i < numbers.size(); i++){
            do {
                numbers[i] = idist(rgen);
            } while(find(numbers.begin(), numbers.begin() +i, numbers[i]) != (numbers.begin()+i));
        }
    }
    else cout << "Das übergebene Array hat nicht die richtige Länge \n";
}



int main(){

    std::vector<int> test {1,2,3,4,5,6};
    print_numbers(test);
    fill_random_numbers(test);
    print_numbers(test);


    return 0;
}