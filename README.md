# Selection Sort CLI (Python, C) 

[![Python Version](https://img.shields.io/badge/python-3.x%2B-blue.svg)](https://www.python.org/downloads/)
[![C](https://img.shields.io/badge/C-Programming-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![GCC](https://img.shields.io/badge/GCC-Compiler-brightgreen.svg)](https://gcc.gnu.org/install/binaries.html)
[![VS Code](https://img.shields.io/badge/VS%20Code-Editor-blue.svg)](https://code.visualstudio.com/download)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

## Table of Contents

- [Selection Sort CLI (Python, C)](#selection-sort-cli-python-c)
	- [Table of Contents](#table-of-contents)
	- [Overview](#overview)
	- [What’s here](#whats-here)
	- [Quick start](#quick-start)
	- [Input format](#input-format)
	- [Example usage](#example-usage)
	- [Visualization (Python)](#visualization-python)
	- [Interactive input (Python, C)](#interactive-input-python-c)
	- [Project structure](#project-structure)
	- [Performance \& complexity](#performance--complexity)
	- [Troubleshooting](#troubleshooting)
	- [Contributing](#contributing)
	- [License](#license)
	- [Acknowledgments](#acknowledgments)

## Overview

Simple, educational Selection Sort tools you can run from the command line. Read numbers from a file, sort them, and get timing + metadata. Includes a Python visualizer for a quick animated view of the algorithm. Selection Sort repeatedly finds the minimum remaining element and places it into the next position; it performs O(n²) comparisons but at most (n−1) swaps, making it illustrative for teaching cost models of comparison vs. write operations.

## What’s here

- `selection_sort_cli.py` — Python CLI that sorts numbers from a file and prints results with timing and metadata
- `selection_sort_cli.c` — C CLI equivalent (fast, single-file build)
- `selection_sort_visual_cli.py` — Python animation of Selection Sort using Matplotlib (for demos)
- `iinputSelectionSort.py` — Python interactive Selection Sort (integer inputs)
- `iinputSelectionSort.c` — C interactive Selection Sort (integer inputs)
- `finputSelectionSort.py` — Python interactive Selection Sort (floating-point inputs)
- `finputSelectionSort.c` — C interactive Selection Sort (floating-point inputs)
- `test_data_*.txt` — Ready-made input files (50 and 100 elements, mixed ordering)
- `LICENSE` — MIT License

## Quick start

- Python (sorting):
	- Prereq: Python 3.8+ installed
	- Run: `python .\selection_sort_cli.py .\test_data_50_1.txt`

- Python (visualization):
	- Prereq: `pip install matplotlib`
	- Run: `python .\selection_sort_visual_cli.py .\test_data_50_1.txt`

- C (CLI):
	- You can build manually with GCC/MinGW: `gcc .\selection_sort_cli.c -o .\selection_sort_cli.exe`
	- Then run: `.\selection_sort_cli.exe .\test_data_50_1.txt`


## Input format

- The input file contains numbers separated by commas and/or whitespace (spaces, tabs, newlines).
- Numbers can be integers or floating point.
- The C version parses into doubles and prints compact values using `%g` (so `1` stays `1`, `1.50` becomes `1.5`).

Example (`test_data_mix.txt`):

```
3, 2, 10 5
7, 1  4
```

## Example usage

Python CLI:

```powershell
python .\selection_sort_cli.py .\test_data_50_2.txt
```

C CLI:

```powershell
# build
gcc .\selection_sort_cli.c -o .\selection_sort_cli.exe
```
```powershell
# run
.\selection_sort_cli.exe .\test_data_50_2.txt
```

Both versions print the same metadata (field names identical):

- Original data: [ ... ]
- Sorted data: [ ... ]
- Sorting took X.XXXXXX seconds
- Sorting algorithm used: Selection Sort
- Number of elements sorted: N
- Data source: <file>
- Data type: int or float
- Data format: Comma and space-separated values
- Data order before sorting: Unsorted
- Data order after sorting: Sorted
- Data size: N elements

Notes:

- In C, the “Data type” is inferred from the first value (integral within 1e-9 → `int`, otherwise `float`) to mirror the Python display intent.
- Timing uses `clock()` in C and `time.time()` in Python. Selection Sort always performs n(n−1)/2 comparisons; timing differences mostly reflect constant factors and system load.
- (Typical implementation here is not stable; equal elements may swap non-preservingly.)

## Visualization (Python)

Want to see Selection Sort in action? The visualizer animates the scan for the minimum and the growing sorted prefix.

Requirements:

- Python 3.8+
- Matplotlib: `pip install matplotlib`

Run:

```powershell
python .\selection_sort_visual_cli.py .\test_data_100_1.txt
```

Example Output:
<p align="center">
	<em>(Add an illustrative figure here if desired)</em>
</p>

Legend (colors):

- Green: Unscanned portion
- White: Currently compared (candidate min) and current index
- Cyan: Already placed (sorted prefix)

## Interactive input (Python, C)

Prefer typing numbers directly instead of using a file? Use the interactive variants. These prompt for the number of elements and then each element, and print the sorted result using Selection Sort.

***For integers***

- Python (interactive):

```powershell
python .\iinputSelectionSort.py
```

Example session:

```text
Enter the number of elements to be sorted: 5
Enter the elements to be sorted:
9
3
7
1
5

The sorted elements are:
	1    3    5    7    9
```

- C (interactive):

```pwsh
gcc .\iinputSelectionSort.c -o .\iinputSelectionSort.exe
```
```pwsh
.\iinputSelectionSort.exe
```

***For float points***

- Python (interactive):

```powershell
python .\finputSelectionSort.py
```

Example session:

```text
Enter the number of elements to be sorted: 5
Enter the elements to be sorted:
9.7
3.2
7.5
1.1
5.6

The sorted elements are:
1.1  3.2  5.6  7.5  9.7
```

- C (interactive):

```pwsh
gcc .\finputSelectionSort.c -o .\finputSelectionSort.exe
```
```pwsh
.\finputSelectionSort.exe
```


## Project structure

```
selection_sort_cli.c          # C CLI implementation
selection_sort_cli.py         # Python CLI implementation
selection_sort_visual_cli.py  # Python visualization with Matplotlib

iinputSelectionSort.c         # C interactive version (integers)
finputSelectionSort.c         # C interactive version (floats)
iinputSelectionSort.py        # Python interactive version (integers)
finputSelectionSort.py        # Python interactive version (floats)

selection_sort.c              # Standalone C implementation (algorithm core)
selection_sort.py             # Standalone Python implementation (algorithm core)

test_data_50_1.txt            # Sample data (50 integers)
test_data_50_2.txt            # Sample data (50 floating-point)
test_data_100_1.txt           # Sample data (100 integers)
test_data_100_2.txt           # Sample data (100 floating-point)
test_data_mix.txt             # Sample data (mixed int + float)

LICENSE                       # MIT license
README.md                     # This file
```

## Performance & complexity

Selection Sort is O(n²) in time (n(n−1)/2 comparisons; up to n−1 swaps). It is easy to implement, has predictable comparison counts, but is not stable and generally slower than algorithms like Insertion Sort on partially ordered data. Use the provided test files (50–100 elements) for quick demos.

## Troubleshooting

- “python: command not found” → Ensure Python is installed and on PATH. Try `py -V` on Windows, or launch via the Python launcher: `py .\bubble_sort_cli.py <file>`.
- “gcc: command not found” → Install MinGW-w64 or a GCC toolchain and ensure `gcc` is on PATH.
- Matplotlib install issues → Upgrade pip: `python -m pip install --upgrade pip` then `pip install matplotlib`.
 - Interactive programs exit unexpectedly → Enter an integer count first, then the same number of integer values (no commas). The interactive versions do not accept floats.

## Contributing
Contributions are welcome and appreciated! **Here are some ways you can contribute:**

 **Ideas for Contribution**
- Propose new features or improvements.
- Optimize performance or add additional functionality.
- Add more robust input validation and error handling.
- Implement unit tests for the Python script.
- Create a graphical user interface (GUI) for Selection Sort (e.g., Tkinter/PyQt) or enhance the visualizer.
- Add support for additional languages.

 **Submit Pull Requests**
1. Fork the repository.
2. Create a feature branch: `git checkout -b feature/your-feature`.
3. Make your changes with clear, commented code.
4. Test thoroughly with different inputs.
5. Submit a pull request with a detailed description of your changes.

*Please ensure any code contributions maintain the existing style and include appropriate documentation.*

## License
This project is open source and available under the [MIT License](LICENSE).

## Acknowledgments
- **GCC Compiler**: For compiling the C program.
- **Python Software Foundation**: For providing the Python programming language.
- **Visual Studio Code**: For being an excellent code editor.
- **Shields.io**: For the beautiful badges used in this README.

---
> **Note:** This README.md file was adapted with the help of AI. While every effort has been made to ensure accuracy and clarity, there may still be minor errors or inconsistencies. Users are encouraged to review the content carefully and make any necessary adjustments.

<div align="center">
  <p>Made with ❤️ by <a href="https://github.com/0PKunal">0PKunal</a></p>
  <p>If this project helped you, please give it a ⭐️</p>
</div>
