// C++ program to Demonstrate
// std::find for vectors
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main() {
    std::vector<int> vec{10, 20, 30, 40};

    // Iterator used to store the position
    // of searched element
    std::vector<int>::iterator it;

    // Print Original Vector
    std::cout << "Original vector :";

    for (int i = 0; i < vec.size(); i++)
        std::cout << " " << vec[i];

    std::cout << "\n";

    // Element to be searched
    int ser = 30;

    // std::find function call
    it = std::find(vec.begin(), vec.end(), ser);
    if (it != vec.end()) {
        std::cout << "Element " << ser << " found at position : ";
        int diff = it - vec.begin();
        std::cout << diff << " (counting from zero) \n";
    } else
        std::cout << "Element not found.\n\n";

    return 0;
}
