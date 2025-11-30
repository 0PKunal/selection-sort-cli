#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

static int is_whitespace_or_comma(char c) {
    return isspace((unsigned char)c) || c == ',';
}

static double *parse_numbers(const char *text, size_t *out_len) {
    size_t cap = 64;
    size_t len = 0;
    double *arr = (double *)malloc(cap * sizeof(double));
    if (!arr) return NULL;

    const char *p = text;
    while (*p) {
        while (*p && is_whitespace_or_comma(*p)) p++;
        if (!*p) break;
        char *endptr = NULL;
        double v = strtod(p, &endptr);
        if (endptr == p) {
            // skip non-number token
            while (*p && !is_whitespace_or_comma(*p)) p++;
            continue;
        }
        if (len == cap) {
            cap *= 2;
            double *tmp = (double *)realloc(arr, cap * sizeof(double));
            if (!tmp) { free(arr); return NULL; }
            arr = tmp;
        }
        arr[len++] = v;
        p = endptr;
    }
    *out_len = len;
    return arr;
}

static void selection_sort(double *a, size_t n) {
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        double tmp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = tmp;
    }
}

static const char *data_type_of(const double *a, size_t n) {
    if (n == 0) return "unknown";
    const double tol = 1e-9;
    for (size_t i = 0; i < n; ++i) {
        double r = (double)llround(a[i]);
        if (fabs(a[i] - r) >= tol) return "float";
    }
    return "int";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    const char *path = argv[1];

    FILE *fp = fopen(path, "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if (sz < 0) sz = 0;
    char *buf = (char *)malloc((size_t)sz + 1);
    if (!buf) { fclose(fp); fprintf(stderr, "Out of memory\n"); return 1; }
    size_t readn = fread(buf, 1, (size_t)sz, fp);
    buf[readn] = '\0';
    fclose(fp);

    size_t n = 0;
    double *original = parse_numbers(buf, &n);
    free(buf);
    if (!original) { fprintf(stderr, "Failed to parse numbers\n"); return 1; }

    double *sorted = (double *)malloc(n * sizeof(double));
    if (!sorted) { free(original); fprintf(stderr, "Out of memory\n"); return 1; }
    memcpy(sorted, original, n * sizeof(double));

    clock_t t0 = clock();
    selection_sort(sorted, n);
    clock_t t1 = clock();
    double elapsed = (double)(t1 - t0) / CLOCKS_PER_SEC;

    const char *dtype = data_type_of(original, n);

    printf("\nOriginal data: [");
    for (size_t i = 0; i < n; ++i) {
        printf("%s%g", i ? ", " : "", original[i]);
    }
    printf("]\n");

    printf("\nSorted data:   [");
    for (size_t i = 0; i < n; ++i) {
        printf("%s%g", i ? ", " : "", sorted[i]);
    }
    printf("]\n");

    printf("\nSorting took %.6f seconds\n", elapsed);
    printf("\nSorting algorithm used: Selection Sort\n");
    printf("\nNumber of elements sorted: %zu\n", n);
    printf("\nData source: file\n");
    printf("\nData type: %s\n", dtype);
    printf("\nData format: Comma and space-separated values\n");
    printf("\nData order before sorting: Unsorted\n");
    printf("\nData order after sorting: Sorted\n");
    printf("\nData size: %zu elements\n", n);
    printf("\n");

    free(original);
    free(sorted);
    return 0;
}
