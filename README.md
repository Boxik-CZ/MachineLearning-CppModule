# MachneLearning-CppModule
is a module for c++ that contains really basic functions for machine learning.

## Built-in variables:

- long double e; ... Variable of e (Euler's number) which is about 2.71828. This number is used in sigmoid activation function.


## Built-in functions:

### long double sigmoid(long double x) {}:

Input:
x ... input value for sigmoid. Sigmoid is a mathematic functions described as f(x)=1/(1+e^-x).

Output : long double value that is f(x).



### std::vector<long double> LLerror(std::vector<long double> hL,std::vector<std::vector<long double>> &who,int sample,std::vector<std::vector<long double>> &y,std::vector<long double> &oL_out);

Input:
hL ... 


## Formating layer and weight vectors

### Layers

Every layer is defined as `std::vector<long double> layer = {0};`  where every item of this vector is value of neuron (the values you can define as yo want or randomly), so if I want to define network like 1-2-1, I would use:
`
std::vector<long double> input = {0};
std::vector<long double> hidden = {0, 0};
std::vector<long double> output = {0};
`
