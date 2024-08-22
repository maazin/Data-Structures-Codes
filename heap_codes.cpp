// //leetcode 2558
// #include <vector>
// #include <queue>
// #include <cmath>

// class Solution {
// public:
//     int pickGifts(vector<int>& gifts, int k) {
//         // Create a max heap using a priority queue
//         priority_queue<int> maxHeap(gifts.begin(), gifts.end());

//         for (int i = 0; i < k; i++) {
//             // Choose the pile with the maximum number of gifts
//             int maxGifts = maxHeap.top();
//             maxHeap.pop();

//             // Leave behind the floor of the square root of the number of gifts
//             int remainingGifts = floor(sqrt(maxGifts));

//             // Push the remaining gifts back into the max heap
//             maxHeap.push(remainingGifts);
//         }

//         // Calculate the total number of gifts remaining
//         int totalRemaining = 0;
//         while (!maxHeap.empty()) {
//             totalRemaining += maxHeap.top();
//             maxHeap.pop();
//         }

//         return totalRemaining;
//     }
// };
// int main() {
//     Solution solution;
    
//     vector<int> gifts = {25, 64, 9, 4, 100};
//     int k = 4;

//     int result = solution.pickGifts(gifts, k);
//     cout << "Number of gifts remaining: " << result << endl;

//     return 0;
// }


//--------
//leetcode 1046

// #include <vector>
// #include <queue>

// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         // Create a max heap using a priority queue
//         priority_queue<int> maxHeap(stones.begin(), stones.end());

//         while (maxHeap.size() > 1) {
//             // Take the two heaviest stones
//             int stone1 = maxHeap.top();
//             maxHeap.pop();
//             int stone2 = maxHeap.top();
//             maxHeap.pop();

//             // Smash the stones
//             if (stone1 != stone2) {
//                 maxHeap.push(stone1 - stone2);
//             }
//         }

//         // Return the weight of the last remaining stone, or 0 if no stones left
//         return maxHeap.empty() ? 0 : maxHeap.top();
//     }
// };
// #include <iostream>
// #include <vector>
// #include <queue>

// std::vector<int> findKLargest(const std::vector<int>& nums, int k) {
//     // Create a min heap
//     std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
//     // Add first k elements to the min heap
//     for (int i = 0; i < k; i++) {
//         minHeap.push(nums[i]);
//     }
    
//     // For remaining elements, if element is larger than the top (minimum) element
//     // of the heap, remove the top element and add this element
//     for (int i = k; i < nums.size(); i++) {
//         if (nums[i] > minHeap.top()) {
//             minHeap.pop();
//             minHeap.push(nums[i]);
//         }
//     }
    
//     // The heap now contains k largest elements
//     std::vector<int> result;
//     while (!minHeap.empty()) {
//         result.push_back(minHeap.top());
//         minHeap.pop();
//     }
    
//     return result;
// }

// int main() {
//     std::vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
//     int k = 3;
    
//     std::vector<int> kLargest = findKLargest(nums, k);
    
//     std::cout << "The " << k << " largest elements are: ";
//     for (int num : kLargest) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
    
//     return 0;
// }

//g++ -std=c++11  heap_codes.cpp -o heap

//---
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    auto compare = [](vector<int>& a, vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> maxHeap(compare);
    
    for (auto& point : points) {
        maxHeap.push(point);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    vector<vector<int>> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }
    return result;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;
    vector<vector<int>> result = kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:\n";
    for (auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}

//---

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();
        int cost = first + second;
        totalCost += cost;
        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};
    int result = minCostToConnectRopes(ropes);

    cout << "The minimum cost to connect all ropes is: " << result << endl;

    return 0;
}
//----

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto compare = [&](pair<int, int>& a, pair<int, int>& b) {
        return matrix[a.first][a.second] > matrix[b.first][b.second];
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> minHeap(compare);
    
    int n = matrix.size();
    for (int i = 0; i < min(n, k); ++i) {
        minHeap.push({i, 0});
    }

    int result = 0;
    while (k--) {
        auto [row, col] = minHeap.top(); minHeap.pop();
        result = matrix[row][col];
        if (col + 1 < n) {
            minHeap.push({row, col + 1});
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;
    int result = kthSmallest(matrix, k);

    cout << "The " << k << "th smallest element in the matrix is: " << result << endl;

    return 0;
}

