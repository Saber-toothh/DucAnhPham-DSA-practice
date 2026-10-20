
## Ex122. Find first or last occurrence of a given number in a sorted array

Given a sorted integer array, find the index of a given number’s first or last occurrence. If the element is not present in the array, report that as well.
Ví dụ: 
Input: A = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9],  target = 5 
Output: 1, 3

Input: nums = [2, 5, 5, 5, 6, 6, 8, 9, 9, 9], target = 4 
Output: Not found

1. Ý tưởng
- Sử dụng Binary Search, ta có thể tìm được index của 1 target. Lấy đó làm chốt, ta duyệt dần sang hai bên. Duyệt sang trái đến khi gặp được phần tử nhỏ ơn, ta có thể biết first occurrence; tương tự với duyệt sang phải.

2. Test cases

- TC1: Input: A = {1, 2, 2, 2, 2, 3, 4}, target = 2
        Output: 1, 4
- TC2: Input: A = {1, 3, 5, 7, 9}, target = 5
        Output: 2, 2
- TC3: Input: A = {5, 5, 5, 6, 7, 8}, target = 5
        Output: 0, 2
- TC4: Input: A = {1, 2, 3, 9, 9, 9}, target = 9
        Output: 3, 5
- TC5: Input: A = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7}, target = 7
        Output: 0, 9
