#include <iostream>
#include "../Header/Binary_search.h"
#include "../Header/BinarySortTree.h"
#include "../Header/Hash.h"
#include "cstring"
int main()
{
    //5-1
    int q[15], len, num;
    std::cout << "���������鳤�ȣ�" ;
    std::cin >> len;
    std::cout << "�����������е�Ԫ�أ�\n" ;
    for(int i = 0; i < len; i ++) std::cin >> q[i];
    std::cout << "��������Ҫ���ҵ�����:" ;
    std::cin >> num;
    int x = binarysearch(q, 0, len, num, false, false);
    if(x != -1) std::cout << "���ֵĽڵ��±�Ϊ�� " << x << std::endl;
    else std::cout << "δ��ѯ��������" << std::endl;

    //5-2
    auto* tree = new BSTree();
    int test;
    while(scanf("%d", &test) != EOF)
    {
        if(test != -1)
        {
            if(tree->insert(tree->root, test)) std::cout << "Successfully insert!\n";
            else std::cout << "Loss to insert\n" ;
        }
        else break;
    }

    //5-3
    // ASLС�ڵ���2 => ��С�ڵ���2/3 => ��ϣ����Ӧ����45
    std::string names[30] = {"zhao", "qian", "sun", "li", "zhou", "wu",
                             "zheng","wang", "feng", "chen", "chu", "wei",
                             "jiang","shen", "han", "yang", "zhu", "qin",
                             "you","xu", "he", "lv", "shi", "zhang",
                             "kong", "cao", "yan", "hua", "jin", "wei"};
    std::string strs[60];
    memset(strs, 0, sizeof strs);
    for(int i = 0; i < 30; i++) hash(strs, names[i]);
    int count = 0, sum = 0;
    for(int i = 0; i < 30; i++)
    {
        int index = 0;
        if(searchHash(names[i], strs, count) != -1)
        {
            index = searchHash(names[i], strs, count);
            sum += count;
            std::cout << strs[index] << " --- " << index << " --- " << count << std::endl;
        }
        else
        {
            std::cout << "δ�ҵ��ڵ�\n";
        }
    }
    printf("%.1f", sum / 30.0);

};
