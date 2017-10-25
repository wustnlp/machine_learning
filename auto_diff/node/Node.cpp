#include "../include/node/Node.h"
#include <iostream>
using namespace std;
Node::Node () {
    output = 0;
    sum_grad = 0;
    a = 0.1;
}
Node::Node (string name) {
    this -> op_name = name;
    output = 0;
    sum_grad = 0;
    a = 0.1;
}
void Node::op () {
}
void Node::grad_op () {
}
void Node::update () {
    if (sum_grad != 0) {
        for (int i = 0; i < sum_grad -> shape[0]; ++i) {
            for (int l = 0; l < output -> shape[0]; ++l) {
                for (int m = 0; m < output -> shape[1]; ++m) {
                    output -> tensor[l][m] -= a * sum_grad -> tensor[i][l * output -> shape[1] + m];
                }
            }
        }
    }
}
Node::~Node () {
    delete output;
    delete sum_grad;
}
