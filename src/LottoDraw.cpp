#include <algorithm>
#include "LottoDraw.h"

LottoDraw::LottoDraw() {
    lottoNumbers = std::vector<int>(6,0);
    superNumber = 0;

    rGenerator = std::mt19937(rDevice());
    lottoNumbersDist = std::uniform_int_distribution<int> (1,49);
    superNumberDist = std::uniform_int_distribution<int> (0,9);
}

void LottoDraw::newDraw() {
    generateLottoNumbers();
    generateSuperNumber();
}

void LottoDraw::generateLottoNumbers() {
    for (int i = 0; i < lottoNumbers.size(); i++){
        do {
            lottoNumbers[i] = lottoNumbersDist(rGenerator);
        } while(find(lottoNumbers.begin(), lottoNumbers.begin() +i, lottoNumbers[i]) != (lottoNumbers.begin()+i));
    }
}

void LottoDraw::generateSuperNumber() {
    superNumber = superNumberDist(rGenerator);
}

std::vector<int> LottoDraw::getLottoNumbers() {
    return lottoNumbers;
}

int LottoDraw::getSuperNumber() {
    return superNumber;
}
