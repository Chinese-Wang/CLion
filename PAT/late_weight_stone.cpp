//
// Created by Wang on 2020/12/30.
//

#include<istream>

int absolute(int x,int y){
    if(x > y)
        return x - y;
    else
        return y - x;
}

/**
 * @brief
 * @param stones
 * @param stonesSize
 * @param start
 */
void sort(int *stones,int stonesSize,int start){
    int temp;
    for(int i = start;i < stonesSize; i++){
        for(int j = i+1 ;j < stonesSize;j++){
            if(stones[i] < stones[j]){
                temp = stones[i];
                stones[i] = stones[j];
                stones[j] = temp;
            }
        }
    }
}

/**
 * @param stones
 * @param stonesSize
 * @return
 */
int lastStoneWeight(int* stones, int stonesSize){
    if(stonesSize == 1){
        return stones[0];
    }

    sort(stones,stonesSize,0);
    for(int i = 0;i<stonesSize-1;i++){
        stones[i+1] = absolute(stones[i],stones[i+1]);
        sort(stones,stonesSize,i+1);
    }

    return stones[stonesSize -1 ];
}

int main(){
    int stones[] = {2,7,4,1,8,1};
    int weight = lastStoneWeight(stones,6);
    printf("%d\n",weight);
    return 0;
}