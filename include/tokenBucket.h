#ifndef TOKENBUCKET_TOKEN_BUCKET_H
#define TOKENBUCKET_TOKEN_BUCKET_H

class TokenBucket {
public:
    long capacity;
    long quantum;   // how many tokens added to bucket every tick
    long availableTokens;  // 可用token
    long fillInterval; // ms
    long latestTick;  //

    TokenBucket(const long capacity, const long quantum, const long fillInterval);
    ~TokenBucket() {};

    long takeTokens(long num);



};

void hello();

#endif