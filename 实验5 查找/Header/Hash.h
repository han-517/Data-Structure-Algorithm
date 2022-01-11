//
// Created by Wjh on 2021/12/18.
//

#ifndef DL1216_HASH_H
#define DL1216_HASH_H
#include <string>
#include <cmath>
#define di 1
#define HASHLENGTH 60
#define HASHCODE 47

int gethash(std::string str)
{
    int len = str.length();
    return (abs(str[len - 1] - str[0]) * len) % HASHCODE;
}

void hash(std::string strs[], std::string str)
{
    int index = gethash(str);
    if(strs[index] == "") strs[index] = str;
    else
    {
        while(strs[index] != "" && index < HASHLENGTH) index += di;
        strs[index] = str;
    }
}

int searchHash(std::string name, std::string names[], int &count)
{
    int index = gethash(name), n = 1;
    while(index < HASHLENGTH)
    {
        if(names[index] == name)
        {
            count = n;
            return index;
        }
        index += di;
        n += 1;
    }
    return -1;
}
#endif //DL1216_HASH_H