# MachneLearning-CppModule

is a module for c++ that contains really basic functions for machine learning. Note: This module is a student project, don't expect anything life changing :).

## Built-in variables:

- long double e; ... Variable of e (Euler's number) which is about 2.71828. This number is used in sigmoid activation function.

## Built-in functions:

### Math

#### Sigmoid activation function

Function definition:
`long double sigmoid(long double x) {}`

Input:

- x ... input value for sigmoid. Sigmoid is a mathematic functions described as f(x)=1/(1+e^-x)

Output -> long double value that is f(x)

#### Derivative of sigmoid function

Function definition:
`long double sigmoidDer(long double x) {}`
Input:

- x ... input value for fucntion (Sigmoid derivative is a math based function. It is described as f'(x)=f(x)\*(1-f(x)) where f(x) is a sigmoid function and ' means derivative.
  Output -> result of f'(x)

### Forward propagation

#### Neuron sum

Function definition:
`long double sum(std::vector<long double> vals, std::vector<long double> w) {}`
Input:

- vals ... 1D vector of values in previous layer (l-1)
- w ... 1D vector of weights between this neuron and every neuron from layer l-1
- b ... bias value of this neuron
  Output -> One value, that is the value of this neuron (Recomendation: don't forget to apply the activation function)

### Backpropagation

#### Error of last layer

Function definition:
`std::vector<long double> LLerror(std::vector<long double> hL,std::vector<std::vector<long double>> &who,int sample,std::vector<std::vector<long double>> &y,std::vector<long double> &oL_out) {}`

Input:

- hL ... values of hidden layer (vector). Check Layer Formating
- who .. (stands for weights-hidden-output) weights between hidden and output layer. Check weights formating
- sample ... index of tested value from x or y (these are datasets, x is input and y is output, check datasets formating)
- y ... output dataset
- oL_out ... Valeus of output layer
- b ... bias vector (check bias formating)

Output -> 1D vector with error for all neurons in last layer

#### Error of hidden layer

Function definition:
`std::vector<long double> HLerror(std::vector<long double> nextDelta,std::vector<std::vector<long double>> &whn,std::vector<long double> &hL) {}`
Input:

- nextDelta ... vector of errors for next layer (or l+1), this error vector can be returned by LLerror() or HLerror()
- whn ... (stands for weights-hidden-next) is a 2D vector with weights between hidden and next layer (can be output or also hidden)
- hL ... vector of values of any hidden layer
  Output -> 1D vector with error of this layer

#### Update of output layer wights

Function definition:
`std::vector<std::vector<long double>> OLupd(std::vector<long double> &hL,std::vector<std::vector<long double>> who,std::vector<long double> &deltaO,long double lr) {}`
Input:

- hL ... values of hidden layer
- who ... weights between hidden and output layer
- deltaO ... error of last layer
- lr ... learning rate
  Output -> updated who (just use it as who = OLupd(hl, who, deltaO, lr); and you are good to go)

#### Update of hidden layer weights

Function definition:
`std::vector<std::vector<long double>> HLupd(std::vector<long double> &iL,std::vector<std::vector<long double>> wih,std::vector<long double> &deltaH,long double lr) {}`
Input:

- iL ... values of layer before (l-1), it can be input layer or hidden layer if there is more of them
- wih ... (stands for weights-input-hidden) are weights between previous layer (it can be another hidden or input) and this
- deltaH ... error of this layer
- lr ... learning rate
  Output -> updated whole wih vector

#### Update of biases

Function definition:
`std::vector<long double> Bupd(std::vector<long double> &b, std::vector<long double> &delta, long double lr) {}`
Input:

- b ... biases of this layer
- delta ... error of this layer
- lr ... learning rate
  Output -> vector of biases for this one layer

## Formating layer and weight vectors

### Layers

Every layer is defined as `std::vector<long double> layer = {0};` where every item of this vector is value of neuron (the values you can define as yo want or randomly), so if I want to define network like 1-2-1, I would use:

```
std::vector<long double> input = {0};
std::vector<long double> hidden = {0, 0};
std::vector<long double> output = {0};
```
