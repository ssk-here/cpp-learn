#include <iostream>
#include <vector>

class VectorCheck {
public:
    void run() {
        std::vector<int> vec;

        // Adding elements
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        std::cout << "After push_back: ";
        printVector(vec);

        // Accessing elements
        std::cout << "Element at index 1: " << vec[1] << std::endl;
        std::cout << "Element at index 2 using at(): " << vec.at(2) << std::endl;

        // Size and capacity
        std::cout << "Size: " << vec.size() << std::endl;
        std::cout << "Capacity: " << vec.capacity() << std::endl;

        // Inserting elements
        vec.insert(vec.begin() + 1, 4);
        std::cout << "After insert: ";
        printVector(vec);

        // Removing elements
        vec.erase(vec.begin() + 2);
        std::cout << "After erase: ";
        printVector(vec);

        // Checking if empty
        std::cout << "Is empty: " << std::boolalpha << vec.empty() << std::endl;

        // Clearing the vector
        vec.clear();
        std::cout << "After clear, size: " << vec.size() << std::endl;
    }

private:
    void printVector(const std::vector<int>& vec) {
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};


int main() {
    VectorCheck vc;
    vc.run();
    return 0;
}