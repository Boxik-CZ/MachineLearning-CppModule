#include "ML.h"
#include <cmath>

long double e = 2.718281828459045235360287471352;
long double sigmoid(long double x) {
    return 1.0L/(1.0L+pow(e, -x));
}
long double sigmoidDer(long double x) {
    long double s = sigmoid(x);
    return s * (1-s);
}
long double sum(std::vector<long double> vals, std::vector<long double> w) {
    long double res = 0;
    for (int i = 0; i < vals.size(); i++) {
        res += vals[i]*w[i];
    }
    return res;
}

// last layer error
std::vector<long double> LLerror(
    std::vector<long double> hL,
    std::vector<std::vector<long double>> &who,
    int sample,
    std::vector<std::vector<long double>> &y,
    std::vector<long double> &oL_out
) {
    std::vector<long double> deltaO(who.size());

    for (int j = 0; j < who.size(); j++) {
        long double z_out = sum(hL, who[j]);
        oL_out[j] = sigmoid(z_out);
        deltaO[j] = (oL_out[j] - y[sample][j]) * sigmoidDer(z_out);
    }
    return deltaO;
}

// hidden layer error
std::vector<long double> HLerror(
    std::vector<long double> nextDelta,
    std::vector<std::vector<long double>> &whn,
    std::vector<long double> &hL
) {
    std::vector<long double> deltaH(hL.size());

    for (int i = 0; i < hL.size(); i++) {
        long double sumErr = 0;
        for (int j = 0; j < nextDelta.size(); j++) {
            sumErr += whn[j][i] * nextDelta[j];
        }
        deltaH[i] = hL[i] * (1 - hL[i]) * sumErr;
    }
    return deltaH;
}

// update weights hidden->output
std::vector<std::vector<long double>> OLupd(
    std::vector<long double> &hL,
    std::vector<std::vector<long double>> who,
    std::vector<long double> &deltaO,
    long double lr
) {
    for (int j = 0; j < who.size(); j++) {
        for (int i = 0; i < hL.size(); i++) {
            who[j][i] -= lr * deltaO[j] * hL[i];
        }
    }
    return who;
}

// update weights input->hidden
std::vector<std::vector<long double>> HLupd(
    std::vector<long double> &iL,
    std::vector<std::vector<long double>> wih,
    std::vector<long double> &deltaH,
    long double lr
) {
    for (int i = 0; i < wih.size(); i++) {
        for (int k = 0; k < iL.size(); k++) {
            wih[i][k] -= lr * deltaH[i] * iL[k];
        }
    }
    return wih;
}