import sys
import re
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def parse_numbers(text):
    tokens = re.split(r"[\s,]+", text.strip())
    nums = []
    for t in tokens:
        if t == "":
            continue
        try:
            nums.append(float(t))
        except ValueError:
            pass
    return nums


def selection_sort_steps(arr):
    a = list(arr)
    n = len(a)
    steps = []
    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            # Record comparison state
            steps.append((list(a), i, j, min_idx))
            if a[j] < a[min_idx]:
                min_idx = j
                steps.append((list(a), i, j, min_idx))
        # Swap
        a[i], a[min_idx] = a[min_idx], a[i]
        steps.append((list(a), i, i, min_idx))
    steps.append((list(a), n - 1, n - 1, n - 1))
    return steps


def animate_selection_sort(data):
    steps = selection_sort_steps(data)
    fig, ax = plt.subplots(figsize=(10, 5))
    bars = ax.bar(range(len(data)), data, color=["green"] * len(data))
    ax.set_title("Selection Sort Visualization")
    ax.set_xlabel("Index")
    ax.set_ylabel("Value")

    def update(frame):
        arr, i, j, min_idx = steps[frame]
        for k, b in enumerate(bars):
            b.set_height(arr[k])
            # Color scheme: green unsorted, cyan sorted portion [0..i-1], white compared, red current min
            if k < i:
                b.set_color("cyan")
            else:
                b.set_color("green")
        if j < len(arr):
            bars[j].set_color("white")
        if min_idx < len(arr):
            bars[min_idx].set_color("red")
        ax.set_title(rf"Selection Sort: i={i}, j={j}, min_idx={min_idx}")
        return bars

    ani = animation.FuncAnimation(fig, update, frames=len(steps), interval=50, blit=False, repeat=False)
    plt.tight_layout()
    plt.show()


def main():
    if len(sys.argv) < 2:
        print("Usage: python selection_sort_visual_cli.py <input_file>")
        sys.exit(1)
    path = sys.argv[1]
    with open(path, "r", encoding="utf-8") as f:
        content = f.read()
    nums = parse_numbers(content)
    if not nums:
        print("No numeric data found in file.")
        sys.exit(1)
    animate_selection_sort(nums)


if __name__ == "__main__":
    main()
