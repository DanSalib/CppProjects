#include "bst.hpp"
using namespace std;

int main() {
    Bst<int> bst1;
    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(1);
    bst1.insert(2);
    bst1.insert(4);
    bst1.insert(10);
    bst1.insert(8);
    bst1.insert(7);
    bst1.insert(9);
    bst1.insert(12);
    
    Bst<int> bst2;
    bst2 = bst1;
    Bst<int> bst3{bst1};
    bst2.insert(13);
    
//?    bst1.print();
    cout << "-----" << endl;
//?    bst2.print();
}
