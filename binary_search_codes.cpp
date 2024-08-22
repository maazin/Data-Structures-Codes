// #include <iostream>
// using namespace std;
// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x == 0) {
//             return 0;
//         }
        
//         int left = 1, right = x;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (mid * mid == x) {
//                 return mid;
//             } else if (mid * mid < x) {
//                 left = mid + 1;
                
//             } else {
//                 right = mid - 1;
                
//             }
//         }
        
//         return right;
//     }
// };

// int main() {
//     Solution solution;
//     int x;
    
//     std::cout << "Enter a number to find its square root: ";
//     std::cin >> x;
    
//     int result = solution.mySqrt(x);
//     std::cout << "The square root of " << x << " is: " << result << std::endl;
    
//     return 0;
// }
//----------
// #include <iostream>
// using namespace std;
// class Solution {
// public:
//     int countNegatives(vector<vector<int>>& grid) {
//         if (grid.empty() || grid[0].empty()) {
//             return 0;
//         }
        
//         int m = grid.size();
//         int n = grid[0].size();
//         int count = 0;
        
//         for (const auto& row : grid) {
//             // Binary search for the first negative element in the row
//             int left = 0;
//             int right = n - 1;
//             while (left <= right) {
//                 int mid = left + (right - left) / 2;
//                 if (row[mid] < 0) {
//                     right = mid - 1;
//                 } else {
//                     left = mid + 1;
//                 }
//             }
            
//             // Count negative numbers in this row
//             count += n - left;
//         }
        
//         return count;
//     }
// };
//----
// #include <iostream>
// #include <vector>

// int firstOccurrence(const std::vector<int>& arr, int target) {
//     int left = 0;
//     int right = arr.size() - 1;
//     int result = -1;
    
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
        
//         if (arr[mid] == target) {
//             result = mid;
//             right = mid - 1;  // Continue searching in the left half
//         } else if (arr[mid] < target) {
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
    
//     return result;
// }

// int main() {
//     std::vector<int> arr = {1, 2, 2, 2, 3, 4, 5, 5, 6};
//     int target = 2;
    
//     int result = firstOccurrence(arr, target);
    
//     if (result != -1) {
//         std::cout << "First occurrence of " << target << " is at index: " << result << std::endl;
//     } else {
//         std::cout << "Element not found in the array" << std::endl;
//     }
    
//     return 0;
// }
// g++ -std=c++11 -o bin binary_search_codes.cpp
//


#include <iostream>

// Assume this function is provided by the system
bool isBadVersion(int version) {
    // For this example, let's say versions 4 and above are bad
    return version >= 4;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int n = 10;  // Total number of versions
    int result = firstBadVersion(n);
    std::cout << "The first bad version is: " << result << std::endl;
    return 0;
}