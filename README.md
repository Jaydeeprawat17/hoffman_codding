# Hoffman Coding Problem

The Hoffman Coding Problem is a C++ program that implements Huffman coding, an efficient method for compressing data by assigning variable-length codes to characters based on their frequencies in a given file. This implementation reads a file, calculates character frequencies, builds a Huffman tree, and assigns Huffman codes to each character.

## Features

- **File Input**: Reads text from a user-specified file to analyze character frequencies.
- **Frequency Calculation**: Computes the frequency of each character in the file.
- **Huffman Tree Construction**: Constructs a binary tree based on character frequencies to generate Huffman codes.
- **Huffman Code Assignment**: Assigns binary Huffman codes to each character based on their position in the tree.

## Getting Started

### Prerequisites

- A C++ compiler (e.g., Turbo C++, GCC).
- A terminal or command prompt to compile and run the program.

### Installation

1. **Clone the repository** (if using version control):

   ```bash
   git clone https://github.com/yourusername/Hoffman-Coding-Problem.git
   cd Hoffman-Coding-Problem
   ```
### Example 

  **Input**
 
   ```bash
   Enter File Name: sample.txt
   ```
### Example 

 **Output**

 ```bash
Root Frequency: 100
Character Frequencies and Huffman Codes:
a 15 101
b 7 110
c 27 0
d 19 111
e 32 10
```
### Code Explanation

**The program is composed of three main classes:**

**File Class: Handles reading the file and calculating the frequency of each character.**

 ```bash
get_frequency(): Reads the file and populates the character frequency data.
show_list(): Displays the list of characters with their frequencies and Huffman bits.
```

**LinkedList Class: Extends the File class and manages a linked list of nodes representing characters and their frequencies.**

 ```bash
insertion(): Inserts a new node into the linked list.
fetch_data(): Transfers character frequency data to the linked list.
get_values(): Displays the contents of the linked list.
```

**Hoffman Class: Extends the LinkedList class and implements the Huffman coding algorithm.**

```bash
sort(): Sorts the linked list by frequency.
handle(): Builds the Huffman tree from the sorted list.
assign(): Assigns Huffman codes to each character based on the tree structure.
s(): Generates and displays the Huffman codes for each character.
```
