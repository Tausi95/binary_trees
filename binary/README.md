### README.md Template for "0x1D. C - Binary trees" Project

```markdown
# 0x1D. C - Binary Trees

## Project Overview

This project is part of the larger curriculum on C programming. It focuses on the implementation and understanding of various binary tree operations in C. The binary tree is a fundamental data structure in computer science, which forms the basis for many algorithms and other data structures. This project will help reinforce knowledge in memory allocation, pointers, and recursion.

## Learning Objectives

By the end of this project, you should be able to:

- Understand the concept of a binary tree and its properties.
- Implement various binary tree operations, including insertion, deletion, traversal, and search.
- Understand and apply recursion in binary tree algorithms.
- Manage memory effectively while working with dynamic data structures in C.

## Project Tasks

### 0. New node
- **Task:** Implement a function that creates a new binary tree node.
- **Prototype:**
  ```c
  binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
  ```
- **File:** `0-binary_tree_node.c`

### 1. Insert left
- **Task:** Implement a function that inserts a node as the left-child of another node.
- **Prototype:**
  ```c
  binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
  ```
- **File:** `1-binary_tree_insert_left.c`

### 2. Insert right
- **Task:** Implement a function that inserts a node as the right-child of another node.
- **Prototype:**
  ```c
  binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
  ```
- **File:** `2-binary_tree_insert_right.c`

### 3. Delete tree
- **Task:** Implement a function that deletes an entire binary tree.
- **Prototype:**
  ```c
  void binary_tree_delete(binary_tree_t *tree);
  ```
- **File:** `3-binary_tree_delete.c`

### 4. Is leaf
- **Task:** Implement a function that checks if a node is a leaf.
- **Prototype:**
  ```c
  int binary_tree_is_leaf(const binary_tree_t *node);
  ```
- **File:** `4-binary_tree_is_leaf.c`

### 5. Is root
- **Task:** Implement a function that checks if a node is the root of the tree.
- **Prototype:**
  ```c
  int binary_tree_is_root(const binary_tree_t *node);
  ```
- **File:** `5-binary_tree_is_root.c`

### [Additional tasks]
- *Add descriptions of additional tasks as needed, following the same format.*

## Installation and Usage

To compile the code, use the following command:

```sh
gcc -Wall -Wextra -Werror -pedantic *.c -o binary_tree
```

Run the program with:

```sh
./binary_tree
```

## Author

- [Your Name Here]

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

