# Selection Sort

def selectionsort(data):
    n = len(data)
    for i in range(0, n - 1):
        si = i
        for j in range(i + 1, n):
            if data[j] < data[si]:
                si = j
        data[i], data[si] = data[si], data[i]
    return data

def main():
    n = int(input("\nEnter the number of elements to be sorted: "))
    raw_data = []
    
    print("\nEnter the elements to be sorted:")
    for _ in range(n):
        raw_data.append(float(input()))
    
    selectionsort(raw_data)
    
    print("\nThe sorted elements are:")
    for num in raw_data:
        print(f"{num:4.2f}", end=' ')
    print("\n")

if __name__ == "__main__":
    main()