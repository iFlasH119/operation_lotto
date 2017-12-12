/*
*
*@author: Tim
*compile with c++11
*
*
*
*/



#include "functions.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;



/**
 * @brief 
 * Unnecessary function that checks if the Array containts exactly 6 elements.
 * 
 * @param numbers 
 * @return true 
 * @return false 
 */
bool check_length(vector<int> numbers){
    if (numbers.size() ==  6){
        return true;
    }
    else return false;
}
/**
 * @brief 
 * Simple print function for console
 * @param numbers 
 */
void print_numbers(vector<int> numbers){
    for (int i = 0; i < numbers.size(); ++i){
        cout << numbers[i] << ' ';
    }
    cout << '\n';
}
/**
 * @brief 
 * Generates random numbers and fills them into given array.
 * @param numbers 
 */
void fill_random_numbers(vector<int> &numbers){
    std::random_device rdev;
    std::mt19937 rgen(rdev());
    std::uniform_int_distribution<int> idist(1,49); 

    for (int i = 0; i < numbers.size(); i++){
        do {
            numbers[i] = idist(rgen);
        } while(find(numbers.begin(), numbers.begin() +i, numbers[i]) != (numbers.begin()+i));
    }
}

/**
 * @brief 
 * Little Simulation
 * Compares two vectors (tip & numbers) and only ends if all numbers equal
 * @param tip 
 * @param numbers 
 */
void draw_numbers (vector<int> tip, vector<int> &numbers){
    int count = 0;
    int jackpot = 0;
    while(jackpot < tip.size()){
        fill_random_numbers(numbers);
        count++;
        for (int i = 0; i < numbers.size(); i++){
            if (find(numbers.begin(), numbers.end(), tip[i]) != (numbers.end())){
                jackpot++;
            }
            else {
                jackpot = 0;
                break;
            }
        } 
    }
    print_numbers(numbers);
    print_numbers(tip);
    cout << count << '\n';
}





int main(){
    /**
     * @brief 
     * little Test
     * 
     */

    std::vector<int> test {1,2,3,4,5,6};
    std::vector<int> drawn_numbers {0,0,0,0,0,0};
    draw_numbers(test,drawn_numbers);


    return 0;
}