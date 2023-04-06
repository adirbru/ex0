#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MISTAKE (-1)
#define POWER_OF 2

int getArraySize(){
    printf("Enter size of input:\n");
    int input_size;
    bool ok = scanf("%d", &input_size);
    if(!(ok && input_size > 0)){
        printf("Invalid size\n");
        exit(1);
    }
    return input_size;
}

int* getArray(int input_size){
    int* arr = (int*)malloc(sizeof(int) * input_size);
    if(arr == NULL)
        exit(1);
    printf("Enter numbers:\n");
    for(int i=0; i < input_size; i++){
        int num;
        if(scanf("%d", &num))
            arr[i] = num;
        else{
            printf("Invalid number\n");
            exit(1);
        }
    }
    return arr;
}

int get_power_of(int num){
    int power = 0;
    while(num && num % POWER_OF == 0){
        power++;
        num /= POWER_OF;
    }
    return num == 1 ? power : MISTAKE;
}


int main() {
    int input_size = getArraySize();
    int* arr = getArray(input_size);
    int powers_sum = 0;
    for(int i=0; i < input_size; i++){
        int num = arr[i];
        int power = get_power_of(num);
        if(power != MISTAKE){
            printf("The number %d is a power of 2: %d = 2^%d\n", num, num, power);
            powers_sum += power;
        }
    }
    free(arr);
    printf("Total exponent sum is %d\n", powers_sum);
    return 0;
}
