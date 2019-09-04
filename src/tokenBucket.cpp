#include "tokenBucket.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cmath>

TokenBucket::TokenBucket(const long capacity, const long quantum, const long fillInterval) {
    this->capacity = capacity;
    this->quantum = quantum;
    this->fillInterval = fillInterval;
    this->availableTokens = 0;
    this->latestTick = 0;
}

long TokenBucket::takeTokens(long num) {
    if (num <=0) {
        std::cout << "Invalid Argument" << std::endl;
    }

    // 更新tokens
    clock_t now = clock();
    std::cout << now << " - " << this->latestTick << " / " << this->fillInterval
              << " = " << floor((now - this->latestTick) / this->fillInterval) << std::endl;
    int ticks = floor((now - this->latestTick) / this->fillInterval);
    if (ticks > 0) {
        this->availableTokens += ticks * this->quantum;
        this->availableTokens = std::min(this->availableTokens, this->capacity);
        this->latestTick += ticks * this->fillInterval;
        std::cout << ticks << std::endl;
    }
    std::cout << "clock " << now <<  ", tokens "<< this->availableTokens << std::endl;

    // 先检查一下token够不够，不够的话直接报错
    if (this->availableTokens < num) {
        // todo，应该告诉客户端一个间隔时间
        std::cout << "token not enough";
        return -1;
    }

    this->availableTokens -= num;
    return num;
}