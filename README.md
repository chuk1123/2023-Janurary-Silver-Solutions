# 🥈 USACO January 2023 Silver Solutions

> My C++ solutions for the USA Computing Olympiad (USACO) January 2023 Silver Division contest

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![USACO](https://img.shields.io/badge/USACO-Silver-c0c0c0.svg)](http://www.usaco.org/)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)

## 📖 About

This repository contains my solutions to all three problems from the [USACO January 2023 Silver Division](http://www.usaco.org/index.php?page=jan23results) contest. All solutions are written in C++17 and optimized for competitive programming.

### What is USACO Silver?

The **USACO Silver Division** is the second tier of the USA Computing Olympiad, requiring knowledge of more advanced algorithms and data structures than Bronze. Topics include graph algorithms, dynamic programming, shortest paths, and more sophisticated problem-solving techniques.

## 🎯 Problems & Solutions

| Problem | Algorithm | Difficulty | Time Complexity | Solution |
|---------|-----------|------------|----------------|----------|
| [Problem 1: Find and Replace](#problem-1-find-and-replace) | Graph Cycle Detection (DFS) | ⭐⭐⭐ | O(T × N) | [p1.cpp](p1.cpp) |
| [Problem 2: Moo Route](#problem-2-moo-route) | Flood Fill + Simulation | ⭐⭐⭐⭐ | O(N² + Q×N²) | [p2.cpp](p2.cpp) |
| [Problem 3: Tractor Paths](#problem-3-tractor-paths) | Greedy Simulation | ⭐⭐⭐ | O(N²) | [p3.cpp](p3.cpp) |

---

### Problem 1: Find and Replace

**📝 Problem Link**: [USACO January 2023 Silver Problem 1](http://www.usaco.org/index.php?page=viewproblem2&cpid=1279)

#### Problem Summary

Given multiple test cases with pairs of strings (original and target), determine the minimum number of character replacement operations needed to transform the original string into the target string. Some transformations may be impossible.

#### Approach

**Algorithm**: Directed Graph + Cycle Detection with DFS

1. Build a directed graph where each edge represents a required character mapping (A → B)
2. Use 3-state DFS to detect cycles:
   - State 0: Unvisited
   - State 1: Currently processing (in DFS stack)
   - State 2: Completed
3. Identify cycle start nodes and count necessary operations
4. Handle impossible cases (conflicting mappings, invalid cycle structures)

**Why This Works**: The problem reduces to finding a valid topological ordering of character transformations. Cycles require special handling with temporary variables. If multiple characters must map to different targets or cycles have no resolution, the transformation is impossible.

#### Complexity
- **Time**: O(T × N) where T is test cases, N is string length
- **Space**: O(52) for letter mappings (uppercase + lowercase)

#### Key Insights
- Mapping conflicts (one letter → multiple targets) are immediately impossible
- Cycles require +1 extra operation (use temporary variable)
- Must track incoming edges to detect problematic cycle structures

---

### Problem 2: Moo Route

**📝 Problem Link**: [USACO January 2023 Silver Problem 2](http://www.usaco.org/index.php?page=viewproblem2&cpid=1280)

#### Problem Summary

Navigate an N×N grid where each cell either contains a direction (Right or Down) or has a score. Process Q queries that flip cell directions, and track how the total score changes after each query.

#### Approach

**Algorithm**: Flood Fill with Dynamic Score Propagation

1. Initialize grid with directions and boundary scores
2. Use flood fill to calculate initial total score
3. For each query:
   - Flip the direction at specified cell
   - Recursively propagate score changes to affected cells
   - Output updated total score

**Why This Works**: Each cell's score is determined by following directions until reaching a boundary. Flipping a direction only affects cells that pass through the modified cell, so we can efficiently update using flood fill.

#### Complexity
- **Time**: O(N² + Q×N²) - initial setup + queries with worst-case full grid updates
- **Space**: O(N²) for grid and score storage

#### Key Insights
- Boundary cells (row N and column N) contain the final scores
- Direction changes create cascading score updates
- Flood fill efficiently tracks which cells need recalculation

---

### Problem 3: Tractor Paths

**📝 Problem Link**: [USACO January 2023 Silver Problem 3](http://www.usaco.org/index.php?page=viewproblem2&cpid=1281)

#### Problem Summary

Construct a sequence of L and R moves to reduce all elements in an array to zero, where L decrements elements from position to left, and R decrements from position to right.

#### Approach

**Algorithm**: Greedy Simulation with Preprocessing

1. **Preprocessing**: Find minimum value and subtract (min-1) from all elements
2. **Pattern generation**: Create alternating full sweeps for the base amount
3. **Greedy completion**:
   - Move left until finding value=1 or reaching edge
   - Move right until finding value=0 or reaching edge
4. Output the complete sequence of L/R moves

**Why This Works**: The preprocessing step reduces all elements uniformly, minimizing the total moves needed. The greedy approach then efficiently handles remaining values by targeting specific patterns.

#### Complexity
- **Time**: O(N²) - preprocessing + greedy simulation
- **Space**: O(N) for array storage

#### Key Insights
- Subtracting uniform amounts first reduces problem complexity
- Greedy left-right traversal optimally handles remaining values
- Position tracking ensures we generate valid move sequences

---

## 🚀 Usage

### Prerequisites

- C++17 or higher compiler (g++, clang++)
- Make (optional, for build automation)

### Compilation

Each solution can be compiled with optimization flags:

```bash
# Problem 1
g++ -std=c++17 -O2 -Wall p1.cpp -o p1

# Problem 2
g++ -std=c++17 -O2 -Wall p2.cpp -o p2

# Problem 3
g++ -std=c++17 -O2 -Wall p3.cpp -o p3
```

### Running Solutions

USACO problems use file I/O. Create input files or redirect stdin:

```bash
# Using input files (USACO style)
./p1 < problem1.in > problem1.out

# Or with file I/O in code (if setIO is used)
# Input: problem.in, Output: problem.out
./p1
```

### Input Format

Refer to the official USACO problem statements (linked above) for detailed input specifications. Each problem follows standard competitive programming I/O format.

## 📁 Repository Structure

```
2023-Janurary-Silver-Solutions/
├── p1.cpp                     # Problem 1: Find and Replace
├── p2.cpp                     # Problem 2: Moo Route
├── p3.cpp                     # Problem 3: Tractor Paths
├── README.md                  # This file
├── LICENSE                    # MIT License
└── Community files/
    ├── CONTRIBUTING.md        # Contributing guidelines
    ├── CODE_OF_CONDUCT.md     # Code of conduct
    ├── ISSUE_TEMPLATE.md      # Issue template
    └── PULL_REQUEST_TEMPLATE.md  # PR template
```

## 💡 Learning Resources

### USACO Silver Topics

Key topics for Silver division:
- **Graph Algorithms**: DFS, BFS, Flood Fill, Connected Components
- **Sorting & Searching**: Binary search, Two pointers
- **Greedy Algorithms**: Interval scheduling, Optimization
- **Basic Dynamic Programming**: 1D DP problems
- **Data Structures**: Set, Map, Priority Queue

### Recommended Resources

- **[USACO Guide](https://usaco.guide/)** - Comprehensive training with curated problems
- **[USACO Training Pages](https://train.usaco.org/)** - Official training platform
- **[Competitive Programming Handbook](https://cses.fi/book/book.pdf)** - Free algorithms textbook
- **[USACO Silver Guide](https://usaco.guide/silver)** - Silver-specific problem solving techniques
- **[CP-Algorithms](https://cp-algorithms.com/)** - Detailed algorithm explanations

## 🔧 Code Features

### Competitive Programming Template

All solutions use a standard competitive programming template:

```cpp
#include <bits/stdc++.h>  // Include all standard libraries
using namespace std;

// Type aliases for convenience
using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

// Common macros
#define pb push_back
#define all(x) begin(x), end(x)
#define len(x) (int)(x).size()

// Fast I/O setup
void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (len(name)) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
```

### Optimization Techniques Used

- **Fast I/O**: `cin.tie(0)` and `sync_with_stdio(0)`
- **File I/O**: `freopen` for USACO-style input/output
- **STL**: Extensive use of vectors, maps, and algorithms
- **Compiler optimizations**: Compiled with `-O2` flag

## 🤝 Contributing

While these are personal contest solutions, suggestions for improvements are welcome! If you have:
- More efficient algorithms
- Clearer code explanations
- Found bugs or edge cases
- Alternative solution approaches

Please see [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines.

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- **USACO** for providing high-quality competitive programming problems
- **Kevin Chu** ([chuk1123](https://github.com/chuk1123)) - Solutions author
- The competitive programming community for techniques and insights

## 📮 About the Author

These solutions were created by Kevin Chu as part of USACO Silver division contest participation. Check out my other competitive programming solutions:

- [2022 December Bronze Solutions](https://github.com/chuk1123/2022-december-bronze-solutions) (Python)

---

**Note**: Repository name contains a typo ("Janurary" instead of "January") - this is preserved for URL consistency.

**Happy Coding!** 🐮💻

*If you found these solutions helpful, consider starring this repository!*
