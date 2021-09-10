#include <iostream>
using namespace std;

struct Tree
{
    Tree *left = NULL;
    Tree *right = NULL;
    int result = 0;
};
void recurse(Tree *t, int * array, int n){
    int mid = n/2;
    if(n == 1){
        t->result = *array;
        return;
    }
    t->result = *(array + mid - 1);

    int* lessMidArray = new int;
    int* moreMidArray = new int;
    int n1 = 0;
    int n2 = 0;

    for (int i = 0; i < n; ++i) {
        if(i < mid - 1) {
            n1++;
            *(lessMidArray + i) = *(array + i);
        }
        else if(i > mid - 1){
            n2++;
            *(moreMidArray + i - mid) = *(array + i);
        }
    }
    recurse(t->left, lessMidArray, n1);
    recurse(t->right, moreMidArray, n2);
}
Tree* addArray(int* array, int n){
    Tree *t = new Tree;
    recurse(t, array, n);

    return t;
}

int main() {
    int n;
    cin >> n;
    int * array = new int;
    int value;
    for (int i = 0; i < n; ++i) {
        cin >> value;
        *(array + i) = value;
    }
    Tree * t = addArray(array, n);
}
