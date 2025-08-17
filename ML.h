#pragma once
#include <vector>
long double e;
long double sigmoid(long double x);
long double sigmoidDer(long double x);
long double sum(std::vector<long double> vals, std::vector<long double> w);
std::vector<long double> LLerror(
    std::vector<long double> hL,
    std::vector<std::vector<long double>> &who,
    int sample,
    std::vector<std::vector<long double>> &y,
    std::vector<long double> &oL_out
);
std::vector<long double> HLerror(
    std::vector<long double> nextDelta,
    std::vector<std::vector<long double>> &whn,
    std::vector<long double> &hL
);
std::vector<std::vector<long double>> OLupd(
    std::vector<long double> &hL,
    std::vector<std::vector<long double>> who,
    std::vector<long double> &deltaO,
    long double lr
);
std::vector<std::vector<long double>> HLupd(
    std::vector<long double> &iL,
    std::vector<std::vector<long double>> wih,
    std::vector<long double> &deltaH,
    long double lr
);