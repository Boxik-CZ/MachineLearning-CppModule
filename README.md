#MachneLearning-CppModule
is a module for c++ that contains really basic functions for machine learning.

##Built-in variables:

- long double e; ... Variable of e (Euler's number) which is about 2.71828. This number is used in sigmoid activation function.


##Built-in functions:

###long double sigmoid(long double x) {}:

Input:
x ... input value for sigmoid. Sigmoid is a mathematic functions described as f(x)=1/(1+e^-x).

Output : long double value that is f(x).

###std::vector<long double> LLerror(
    std::vector<long double> hL,
    std::vector<std::vector<long double>> &who,
    int sample,
    std::vector<std::vector<long double>> &y,
    std::vector<long double> &oL_out
);
