//
// Created by Wjh on 2021/12/16.
//

#ifndef DL1216_BINARY_SEARCH_H
#define DL1216_BINARY_SEARCH_H
#include <algorithm>

void quicksort(int q[], int l, int r)
{
    if(l >= r) return;
    int x = q[(l + r) >> 1];
    int i = l - 1, j = r + 1;
    while(i < j)
    {
        do i++; while(q[i] < x);
        do j--; while(q[j] > x);
        if(i < j) std::swap(q[i], q[j]);
    }
    quicksort(q, l, j);
    quicksort(q, j + 1, r);
}

int binarysearch(int q[], int l, int r, int num, bool flag1=false, bool flag2=false)
{
    if(flag1)
    {
        if(flag2)
        {
            while(l < r)
            {
                int mid = l + r >> 1;
                if(q[mid] < num) r = mid - 1;
                else l = mid;
            }
        }
        else
        {
            while(l < r)
            {
                int mid = l + r >> 1;
                if(q[mid] <= num) r = mid;
                else l = mid + 1;
            }
        }
    }
    else
    {
        if(flag2)
        {
            while(l < r)
            {
                int mid = l + r >> 1;
                if(q[mid] > num) r = mid - 1;
                else l = mid;
            }
        }
        else
        {
            while(l < r)
            {
                int mid = l + r >> 1;
                if(q[mid] >= num) r = mid;
                else l = mid + 1;
            }
        }
        if(q[l] != num) return -1;
        else return l;
    }
}
#endif //DL1216_BINARY_SEARCH_H
