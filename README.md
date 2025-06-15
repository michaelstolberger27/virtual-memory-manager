# Virtual Memory Manager Simulator

A C++ simulation of a virtual memory system demonstrating paging and multiple page replacement algorithms. This project illustrates how an operating system handles page faults, manages physical memory, and applies page replacement policies such as **FIFO**, **LRU**, and **Optimal** when memory is full.

---

## Overview

This simulator models:

- Virtual-to-physical memory translation using a single-level page table abstraction.
- Handling of page faults and page replacement with configurable algorithms:
  - **FIFO (First-In, First-Out)**
  - **LRU (Least Recently Used)**
  - **Optimal (theoretical best)**
- Customizable virtual pages, physical frames, and page reference strings.

---

## Features

- Multiple page replacement algorithms: FIFO, LRU, Optimal
- Command-line interface to select algorithm and provide input
- Tracks page hits, page faults, and computes page fault rate
- Modular and extensible design for adding more algorithms
- Simple input format supporting file redirection or interactive mode

---

## Project Structure

```txt
virtual-memory-manager/
│
├── include/
│ ├── MemoryManager.h # Base class interface
│ ├── FIFOManager.h # FIFO algorithm implementation
│ ├── LRUManager.h # LRU algorithm implementation
│ └── OptimalManager.h # Optimal algorithm implementation
│
├── src/
│ ├── main.cpp # Program entry point and input handling
│ ├── FIFOManager.cpp # FIFO algorithm logic
│ ├── LRUManager.cpp # LRU algorithm logic
│ └── OptimalManager.cpp # Optimal algorithm logic
│
├── test/
│ └── test_input.txt # Sample input for testing
│
├── Makefile # Build script
├── README.md # Project documentation
└── .gitignore
```

---

## Getting Started

### Prerequisites

- C++ compiler with **C++14** support or higher
- POSIX-compatible shell or terminal
- `make` utility for building (optional)

### Building the Project

```bash
make
```

This compiles the source files and creates the executable `vmm_simulator`.

### Running the Simulator

Specify the page replacement algorithm as the first argument:

```bash
./vmm_simulator fifo < test/test_input.txt
./vmm_simulator lru < test/test_input.txt
./vmm_simulator optimal < test/test_input.txt
```

You can also run interactively by entering input manually after running:

```bash
./vmm_simulator fifo
```

---

### Input Format

Provide the following input separated by spaces or newlines:

```txt
<number_of_virtual_pages> <number_of_physical_frames> <length_of_reference_string> <page_reference_string...>
```

Example:

```txt
10 3 12 7 0 1 2 0 3 0 4 2 3 0 3
```

---

### Sample Output

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

## Concepts Demonstrated

- Virtual memory management and paging basics  
- Page fault detection and handling  
- FIFO, LRU, and Optimal page replacement algorithms  
- Data structures: queues, lists, hash maps  
- Performance metrics: hit/miss ratio, fault rate  

---

## Author

Michael Stolberger