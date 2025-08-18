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

### Weights

Weights are defined as `std::vector<std::vector<long double>> w = {{}};` where every w[i] is one neuron and every w[i][n] is connection with every neuron from previous layer (l-1). For our example of network 1-2-1 it would look like:

```
std::vector<std::vector<long double>> inputHidden = {{0}, {0}};
std::vector<std::vector<long double>> hiddenoutput = {{0,0}};
```

### Biases

Biases are define as 1D vector for every layer where every item is bias of one neuron. The definition looks like `std::vector<long double> b = {0, 0};`, so for our network 1-2-1 it would look like this:

```
std::vector<long double> hiddenLayerBias = {0, 0};
std::vector<long double> outputLayerBias = {0};
```

## Project example

Now I will show you example how can complete code look like. Let's say we want 1-2-1 network where if we input 0 the network will output 1 and the other way around. Before starting, don't forget to import vectors using `#include <vector>`.

### 1. Dataset definition

```
std::vector<std::vector<long double>> x = {
    {0},
    {1}
};
std::vector<std::vector<long double>> y = {
    {1, 0},
    {0, 1}
};
```

y is output and x is input

### 2. Layer definition

```
std::vector<long double> iL = {0};
std::vector<long double> hL = {0,0};
std::vector<long double> oL = {0};
```

Here I will short it from inputLayer to iL and more.

### 3. Bias definition

```
std::vector<long double> hB = {0, 0};
std::vector<long double> oB = {0,0};
```

### 4. Weights definition

```
std::vector<std::vector<long double>> wih = {
    {0}, {0}
};
std::vector<std::vector<long double>> who = {
    {0, 0}
};
```

Here you can define the vales inside randomly or as you want. It will be changed during training.

### 5. Learning rate, epochs and sample

```
long double lr = 0.1;
int index = 0;
int epochs = 50000;
```

- lr (learning rate)... how much will the weights and biases move in one epoch, the bigger the number is the faster the training is but it gets less accourate
- index ... we want to train on all of our data so we use index and in main loop we are switching between every item in x and y, you will see
- epochs ... how many cycles the training will have, the more epochs, the more accourate the model can get

### 6. Main loop

```
for (int epoch = 0; epoch < epochs; epoch++) {...}
```

Here epoch is current epoch and epochs is the number of all epochs that will be runned.
Next we will take a look inside this loop.

#### 6.1 Setting input data

```
index = epoch % 2;
iL = {x[index][0]};
```

Here in every cycle we change index, it works like this: % is a modulo and it returns the remainder (or the left or how ever you want to call it) after dividing, so if epoch = 2 then epoch%2 == 0 so we take the sample with index 0 and if epoch = 5 then epoch%2==1 so we take the item with index 1 from x as input. iL is a input layer and because we have only one item in it, we can just set it to the x value.

#### 6.2 Hidden layer forward pass

```
for (int i = 0; i < hL.size(); i++) {
    hL[i] = sigmoid(sum(iL, wih[i], hB[i]));
}
```

Here we calculate the value for every neuron in hiddenLayer.

#### 6.3 Caluclating error

```
std::vector<long double> eLL = LLerror(hL, who, index, y, oL, oB);
std::vector<long double> eL1 = HLerror(eLL, who, hL);
```

The first line calcualates the error of every neruon in last layer so it is vector. The same happens for eL1 which is the error of the first (and the only one) hidden layer, also you get vector with error for every neuron.

#### 6.4 Weights update

```
who = OLupd(hL, who, eLL, lr);
wih = HLupd(iL, wih, eL1, lr);
```

Reminder: who are weights between hidden and output and wih are weights between input and output layer.
The first line updates the who weights and the second line updates the wih weights.

#### 6.5 Bias update

```
hB = Bupd(hB, eL1, lr);
oB = Bupd(oB, eLL, lr);
```

Reminder: hB are biases in hidden layer and oB are biases in output layer.
First line updates biases of hidden layer and second line updates output layer biases.

### 7. Testing model

`for (int in = 0; in < 2; in++) {}`
Here we use this loop to go through all of the testing values that we have in x and y (for testing is recomended to use completly different data, that these you used during training.)

#### 7.2 Input data init

`iL = {x[in][0]};`
Here we set the input value to one from x dataset.

#### 7.3 Hidden layer value

```
for (int i = 0; i < hL.size(); i++) {
  hL[i] = sigmoid(sum(iL, wih[i], hB[i]));
}
```

Here we calculate the value for every neuron in hidden layer. We use sum() for getting the sum of weight with some neuron in the first (or previos) layer and multiply it by the value of the neuron and to the end we add the neuron bias. To the whole sum we apply the activation function, sigmoid in this case.

#### 7.4 Output layer value

```
for (int j = 0; j < oL.size(); j++) {
    oL[j] = sigmoid(sum(hL, who[j], oB[j]));
}
```

Here we calculate it in the same way for the output layer, again with sigmoid function.

#### 7.5 Output value

`std::cout << "x="<<x[in][0]<<": "<<oL[0]<<"\n";";`
Here we print out the tested value and the output value of the network.

### 8. Complete program

Here is the complete program:

```

```
