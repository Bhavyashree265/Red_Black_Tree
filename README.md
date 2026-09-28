# Red-Black Tree in C

## Overview

This project implements a **Red-Black Tree (RBT)** in C.

A Red-Black Tree is a self-balancing Binary Search Tree that maintains balance after insertion and deletion using **rotations and recoloring**.

## Features

- Insert a node
- Delete a node
- Search for an element
- Find minimum value
- Find maximum value
- Delete minimum value
- Delete maximum value
- Display the tree
- Inorder traversal
- Automatic balancing after insertion
- Automatic balancing after deletion
- Duplicate element detection
- Input validation

## Red-Black Tree Properties

The implementation maintains the following properties:

1. Every node is either RED or BLACK.
2. The root is always BLACK.
3. NULL leaves are considered BLACK.
4. A RED node cannot have a RED child.
5. Every path from a node to its descendant NULL leaves contains the same number of BLACK nodes.

These properties keep the tree balanced and ensure `O(log n)` height.

## Menu

```text
1. Insert
2. Delete
3. Find Minimum
4. Find Maximum
5. Delete Minimum
6. Delete Maximum
7. Display
8. Search
9. Exit
