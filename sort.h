typedef struct _Range {
    int start, end;
} Range;

void bubble_sort(int arr[], int len);
void selection_sort(int a[], int len);
void insertion_sort(int arr[], int len);
void shell_sort(int arr[], int len);
int min(int x, int y);
void merge_sort(int arr[], int len, int isRecursive);
void merge_sort_recursive(int arr[], int reg[], int start, int end);
Range new_Range(int s, int e);
void swap(int *x, int *y);
void quick_sort(int arr[], const int len, int isRecursive);
void quick_sort_recursive(int arr[], int start, int end);