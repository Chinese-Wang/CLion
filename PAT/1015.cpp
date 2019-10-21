//
// Created by 王京珠 on 2019/9/24.
//

#include <iostream>
#include <cstring>
using namespace std;

struct Student{
    char id[9] = {' ',' ',' ',' ',' ',' ',' ',' ','\0'};
    int moral;
    int ability;
    int flag = 0;
};

void swap(Student &s1,Student &s2){
    Student s;
    strcmp(s.id,s1.id);
    s.moral = s1.moral;
    s.ability = s1.ability;
    strcmp(s1.id,s2.id);

}

void Grading(Student *s,int index,int len){
    if(index == len)
        return;
    if(s[index].ability >= H && s[index].moral >= H)
        s[index].flag = 1;
    else if(s[index].moral >= H && s[index].ability < H)
            s[index].flag = 2;
    else if(s[index].moral < H && s[index].ability < H && s[index].moral > s[index].ability)
        s[index].flag = 3;
    else if(s[index].moral >= L && s[index].ability >L)
        s[index].flag = 4;
    Grading(s,index+1,len);
}

int main()
{
    int N,L,H;
    int num = 0;
    cin>>N>>L>>H;
    Student *s = (Student*)malloc(sizeof(Student)*N);
    for (int i = 0; i < N; ++i) {
        cin>>s[i].id>>s[i].moral>>s[i].ability;
    }
    for (int i = 0; i < N; ++i) {
        s[i].total = s[i].moral + s[i].ability;
        if(s[i].ability >= L && s[i].moral >= 60)
            num++;
    }

    delete[](s);
    return 0;
}