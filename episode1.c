#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// this is the training data

float train[][2] = {
    {0,0},
    {1,2},
    {2,4},
    {3,6},
    {4,8}
};

#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void){
    return (float)rand()/ (float)RAND_MAX;
}

float cost(float w){

    float result = 0.0;
    for(int i=0; i<train_count; i++){
        float x = train[i][1];
        float y = x*w;
        float d = y - train[i][1];
        result += d*d;
        // printf("actual : %f, expected: %f\n",y,train[i][1]);
    }
    result /= train_count;

    return result;
}

int main(){

    srand(time(0));
    // srand(69);
    
    // y = x*w;

    float  w = rand_float()*10.0f;
    // cost function is like a parabolic function.
    // so there is a direction of x upto which y decreases
    float eps = 1e-3;
    //using the first principal's limit definition
    // but its called Finite difference.. h->0 here h is eps

    float dcost = (cost(w + eps) - cost(w))/eps;

    printf("%f\n", cost(w));
    printf("%f\n", cost(w - eps));

    return 0;
}