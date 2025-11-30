import sys
import time
import re


def parse_numbers(text):
    tokens = re.split(r"[\s,]+", text.strip())
    nums = []
    for t in tokens:
        if t == "":
            continue
        try:
            v = float(t)
            nums.append(v)
        except ValueError:
            pass
    return nums


def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr


def data_type_of(nums):
    if not nums:
        return "unknown"
    # If all are essentially integers within tolerance, call int
    tol = 1e-9
    if all(abs(x - round(x)) < tol for x in nums):
        return "int"
    return "float"


def main():
    if len(sys.argv) < 2:
        print("Usage: python selection_sort_cli.py <input_file>")
        sys.exit(1)
    path = sys.argv[1]
    try:
        with open(path, "r", encoding="utf-8") as f:
            content = f.read()
    except Exception as e:
        print(f"Error reading file: {e}")
        sys.exit(1)

    nums = parse_numbers(content)
    original = list(nums)

    start = time.time()
    selection_sort(nums)
    elapsed = time.time() - start

    dtype = data_type_of(original)

    print(f"\nOriginal data: {original}")
    print(f"\nSorted data:   {nums}")
    print(f"\nSorting took {elapsed:.6f} seconds")
    print("\nSorting algorithm used: Selection Sort")
    print(f"\nNumber of elements sorted: {len(nums)}")
    print("\nData source: file")
    print(f"\nData type: {dtype}")
    print("\nData format: Comma and space-separated values")
    print("\nData order before sorting: Unsorted")
    print("\nData order after sorting: Sorted")
    print(f"\nData size: {len(nums)} elements\n")


if __name__ == "__main__":
    main()
