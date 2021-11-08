#include <iostream>
#include "../Header/Huffman_Tree.h"

int main() {
    std::string str;
    std::cin >> str;
    HuffTree *test = new HuffTree(str);
    test->Init();
    test->Tree_Creat();
    test->Tree_Print();
    test->Tree_Convert();
    system("pause");
    return 0;
}
