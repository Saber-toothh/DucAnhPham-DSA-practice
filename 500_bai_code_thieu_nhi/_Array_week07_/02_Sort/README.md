
## Ex9. Dutch national flag problem - Sorting 0's, 1's and 2's

Given an array containing only 0’s, 1’s, and 2’s, sort it in linear time and using constant space.

For example,
Input:  { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 } 
Output: { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 }

1. Ý tưởng
- Bài toán này hoàn toàn có thể sử dụng Quick Sort, nhưng để đáp ứng độ phức tạp thời gian là O(n), ta cần nghĩ đến cách sắp xếp hợp lí hơn.

- Vì chỉ có 3 giá trị, ta có thể tưởng tượng có 3 mảng, mỗi mảng gồm các phần tử cùng giá trị, và các mảng được sắp xếp tăng dần theo giá trị. Mục tiêu là đưa các phần tử vào đúng mảng, cụ thể số 0 vào mảng ở đầu, số 2 vào mảng ở cuối, và số 1 lúc này hiển nhiên đúng vị trí.

- Chọn giá trị trung gian là 1, coi mảng đầu và mảng cuối ban đầu có 0 phần tử.

- Ta duyệt từ đầu đến khi gặp phần tử đầu của mảng cuối đã sắp xếp. Gọi x là phần tử đang xét:
    + Nếu x = 0 < 1 -> đổi vị trí x và phần tử đang ở vị trí sau phần tử cuối của mảng đầu
    + Nếu x = 2 > 1 -> đổi vị trí x và phần tử đang ở vị trí trước phần tử đầu của mảng cuối
    + Nếu x = 1 -> giữ nguyên, duyệt tiếp

2. Test cases

- TC1: 
Input: A = [2, 0, 2, 1, 1, 0]
Output: A = [0, 0, 1, 1, 2, 2]

- TC2: N lẻ
Input: A = [1, 2, 0, 1, 2, 0, 1]
Output: A = [0, 0, 1, 1, 1, 2, 2]

- TC3: không có số 1
Input: A = [2, 0, 2, 0, 0]
Output: A = [0, 0, 0, 2, 2]

- TC4: không có số 0
Input: A = [2, 1, 2, 2, 1]
Output: A = [1, 1, 2, 2, 2]

- TC5:
Input: A = [1, 1, 1, 1, 1]
Output: A = [1, 1, 1, 1, 1]

- TC6: 
Input: A = [0, 0, 1, 1, 2, 2]
Output: A = [0, 0, 1, 1, 2, 2]

- TC7: 1 phần tử
Input: A = [2]
Output: A = [2]

## Ex10. Inplace merge two sorted arrays
Given two sorted arrays, X[] and Y[] of size m and n each, merge elements of X[] with elements of array Y[] by maintaining the sorted order, i.e., fill X[] with the first m smallest elements and fill Y[] with remaining elements.
Do the conversion in-place and without using any other data structure.

For example,

Input: X[] = { 1, 4, 7, 8, 10 } Y[] = { 2, 3, 9 } 
Output: X[] = { 1, 2, 3, 4, 7 } Y[] = { 8, 9, 10 }

1. Ý tưởng
- Ta có thể thấy, sau khi đã được sắp xếp, phần tử đầu tiên của mảng Y lớn hơn tất cả các phần tử của mảng X. 
- Vì vậy, để giải quyết bài toán, ta chỉ việc so sánh từng phần tử X[i] của X với phần tử đầu tiên của Y (chừng nào Y[0] chưa lớn hơn X[m-1] thì bài toán chưa được giải quyết)
    + Nếu X[i] > Y[0] -> đổi chỗ X[i] và Y[0] -> đưa 2 phần tử này về đúng vị trí trong mỗi mảng để giữ cho các mảng luôn trong trạng thái 'đã được sắp xếp'.
(Lưu ý: Thực chất chỉ cần đưa Y[0] sau khi đổi về đúng vị trí, vì không thể xảy ra trường hợp X[a]>Y[0] với a < i vì đã duyệt qua a trước i rồi, chắc chắn X[a] < Y[0])

2. Test cases
TC1:
Input:
X = [1, 4, 7, 8, 10]
Y = [2, 3, 9]
Output:
X = [1, 2, 3, 4, 7]
Y = [8, 9, 10]

TC2:
Input:
X = [7, 8, 9]
Y = [1, 2, 3]
Output:
X = [1, 2, 3]
Y = [7, 8, 9]

TC3: Có chứa các phần tử trùng lặp
Input:
X = [1, 3, 3, 5]
Y = [3, 4, 5]
Output:
X = [1, 3, 3, 3]
Y = [4, 5, 5]

TC4: Mảng Y chỉ có 1 phần tử
Input:
X = [2, 4, 6, 8]
Y = [5]
Output:
X = [2, 4, 5, 6]
Y = [8]

TC5: Mảng có chứa số âm
Input:
X = [-5, -1, 4, 7]
Y = [-3, 2, 6]
Output:
X = [-5, -3, -1, 2]
Y = [4, 6, 7]
