/*
*
*@author: Tim
*compile with c++11
*
*
*
*/

#include "functions.h"
#include "LottoDraw.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
using namespace std;

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
 * Little Simulation
 * Compares two vectors (tip & numbers) and only ends if all numbers equal
 * @param tip 
 * @param numbers 
 */
void draw_numbers (vector<int> tip,  LottoDraw *lottoDraw){
    int count = 0;
    int jackpot = 0;
    std::vector<int> numbers;
    while(jackpot < tip.size()){
        lottoDraw->newDraw();
        numbers = lottoDraw->getLottoNumbers();
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

/*
 *  Main
 */
int main(){
    std::vector<int> test {10,17,18,25,38,40};
    LottoDraw *lottoDraw = new LottoDraw();

    draw_numbers(test, lottoDraw);
    return 0;
}