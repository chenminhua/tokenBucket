//
// Created by 陈敏华 on 9/4/19.
//

#include "tokenBucket.h"
#include <unistd.h>
#include <iostream>

int main() {
    TokenBucket tb = TokenBucket(100L, 10L, 3000L);
    tb.takeTokens(1);
    std::cout << "hello world" << std::endl;
    tb.takeTokens(2);
    for(int i=0; i<=10000000; i++); // <----- note that the loop doesn't do anything
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(0);
    tb.takeTokens(0);
    tb.takeTokens(2);
    tb.takeTokens(2);
    tb.takeTokens(2);

}