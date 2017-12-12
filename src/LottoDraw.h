#ifndef LOTTODRAW_H
#define LOTTODRAW_H

#include <vector>
#include <random>

class LottoDraw {
    public:
        LottoDraw();
        void newDraw();
        std::vector<int> getLottoNumbers();
        int getSuperNumber();

    private:
        std::vector<int> lottoNumbers;
        int superNumber;

        std::random_device rDevice;
        std::mt19937 rGenerator;
        std::uniform_int_distribution<int> lottoNumbersDist;
        std::uniform_int_distribution<int> superNumberDist;

        void generateLottoNumbers();
        void generateSuperNumber();
};

#endif