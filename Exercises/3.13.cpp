//
// Created by 王京珠 on 2019/9/10.
//

#include <iostream>
#include <cstring>
using namespace std;

int Find(char squar[5][5],const char *word){
    int col,row;
    int flag = 0;
    int index_word = 0;
    int origin_col,origin_row;
    int len_word = strlen(word);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (squar[i][j] == word[0]){
                col = i;
                row = j;
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
    origin_col = col;
    origin_row = row;
    while ((col<5)&&(index_word<len_word)){
        if(squar[col][row] == word[index_word]){
            col++;
            index_word++;
        }
        else{
            col = origin_col;
            row = origin_row;
            index_word = 0;
            break;
        }
    }
    while ((col<5) &&(index_word <len_word) &&(row < 5)){
        if(squar[col][row] == word[index_word]){
            col++;
            row++;
            index_word++;
        }
        else{
            col = origin_col;
            row = origin_row;
            index_word = 0;
            break;
        }
    }
    while ( (row < 5) && (index_word < len_word)){
        if(squar[col][row] == word[index_word]){
            row++;
            index_word++;
        }
        else{
            break;
        }
    }
    if(index_word == len_word) return 1;
    else return 0;
}

int main()
{
    char square[5][5] = {{'a', 'b', 'c', 'd', 'e'}, {'f', 'g', 'h', 'i', 'j'}, {'k', 'l', 'm', 'n', 'o'}, {'p', 'q', 'r', 's', 't'}, {'u', 'v', 'w', 'x', 'y'}};
    int len = 5;
    char words[15];
    cout<<"Entry the word:";
    cin>>words;
    int flag = Find(square, words);
    if (flag) cout<<"Yes!"<<endl;
    else cout<<"NO!"<<endl;
    return 0;
}