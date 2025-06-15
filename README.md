# Virtual Memory Manager Simulator

A C++ simulation of a virtual memory system using paging and FIFO page replacement. This project demonstrates how an operating system handles page faults, manages physical memory, and applies page replacement policies when memory is full.

## Overview

This project simulates:

- Virtual to physical memory translation using a single-level page table.
- Page faults and page replacement using the **FIFO (First-In, First-Out)** algorithm.
- Configurable number of virtual pages, physical frames, and page access patterns.

---

## Features

- FIFO page replacement algorithm
- Command-line input or file-based simulation
- Tracks page hits, page faults, and page fault rate
- Easy to extend with new algorithms (e.g., LRU, Optimal)

---

## Project Structure

virtual-memory-manager/
│
├── src/
│ ├── main.cpp # Entry point and simulation logic
│ ├── MemoryManager.cpp # FIFO page replacement implementation
│ ├── MemoryManager.h # Class declarations
│
├── test/
│ ├── test_input.txt # Sample input for testing
│
├── Makefile # Build instructions
├── README.md # Project documentation
└── .gitignore

---

## Getting Started

### Prerequisites

- C++11 or newer
- A POSIX-compatible terminal
- `make` utility (optional)

### Building the Project

```bash
make
```

This compiles the simulator and produces an executable named vmm_simulator.

### Running the Simulator

You can run it interactively:

```bash
./vmm_simulator
```

Or use redirected input from a test file:

```bash
./vmm_simulator < test/test_input.txt
```

### Sample Input Format

The simulator expects input in the following order:

```txt
<number of virtual pages> <number of physical frames> <length of reference string> <space-separated page reference string>
```

Example: 

```txt
10 3 12 7 0 1 2 0 3 0 4 2 3 0 3
```

---

### Example Output

```txt
Accessing page 7 - Page Fault!
Accessing page 0 - Page Fault!
Accessing page 1 - Page Fault!
Accessing page 2 - Page Fault!
Accessing page 0 - Hit
Accessing page 3 - Page Fault!
...
Total memory accesses: 12
Total page faults: 10
Page fault rate: 83.3333%
```

---

### Concepts Demonstrated

- Virtual memory and page tables  
- Page faults and replacement strategies  
- FIFO algorithm and queue-based eviction  
- Memory performance metrics (hit/miss ratio)

---

### Future Enhancements

- ✅ Implement **LRU** and **Optimal** replacement algorithms  
- ✅ Simulate **TLB (Translation Lookaside Buffer)**  
- ✅ Add **multi-level page tables**  
- ✅ Track **dirty/reference bits**  
- ✅ Support **multiple processes** with isolated memory spaces  
- ✅ Visual output or GUI to show memory state dynamically

---

### Author

Michael Stolberger  
