
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
Input: A = {2, 0, 2, 1, 1, 0}
Output: A = {0, 0, 1, 1, 2, 2}

- TC2: N lẻ
Input: A = {1, 2, 0, 1, 2, 0, 1}
Output: A = {0, 0, 1, 1, 1, 2, 2}

- TC3: không có số 1
Input: A = {2, 0, 2, 0, 0}
Output: A = {0, 0, 0, 2, 2}

- TC4: không có số 0
Input: A = {2, 1, 2, 2, 1}
Output: A = {1, 1, 2, 2, 2}

- TC5:
Input: A = {1, 1, 1, 1, 1}
Output: A = {1, 1, 1, 1, 1}

- TC6: 
Input: A = {0, 0, 1, 1, 2, 2}
Output: A = {0, 0, 1, 1, 2, 2}

- TC7: 1 phần tử
Input: A = {2}
Output: A = {2}

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
X = {1, 4, 7, 8, 10}
Y = {2, 3, 9}
Output:
X = {1, 2, 3, 4, 7}
Y = {8, 9, 10}

TC2:
Input:
X = {7, 8, 9}
Y = {1, 2, 3}
Output:
X = {1, 2, 3}
Y = {7, 8, 9}

TC3: Có chứa các phần tử trùng lặp
Input:
X = {1, 3, 3, 5}
Y = {3, 4, 5}
Output:
X = {1, 3, 3, 3}
Y = {4, 5, 5}

TC4: Mảng Y chỉ có 1 phần tử
Input:
X = {2, 4, 6, 8}
Y = {5}
Output:
X = {2, 4, 5, 6}
Y = {8}

TC5: Mảng có chứa số âm
Input:
X = {-5, -1, 4, 7}
Y = {-3, 2, 6}
Output:
X = {-5, -3, -1, 2}
Y = {4, 6, 7}

## Ex18. Move all zeros present in an array to the end
Given an integer array, move all zeros present in it to the end. The solution should maintain the relative order of items in the array and should not use constant space.
For example,
Input:  { 6, 0, 8, 2, 3, 0, 4, 0, 1 } 
Output: { 6, 8, 2, 3, 4, 1, 0, 0, 0 }

1. Ý tưởng
- Ban đầu, tôi nghĩ đến việc dùng 2 con trỏ đầu và cuối duyệt ngược chiều với chốt 0 giống như Quick Sort, nhưng để giữ nguyên trật tự các phần tử không phải 0 thì phải dịch k phần tử giữa 0 đầu và 0 cuối, độ phức tạp sẽ khá lớn.
- Để giải quyết bài toán, ta có thể đổi vị trí **số 0 đầu tiên** của mảng với **số khác 0 đầu tiên tính từ số 0 đó**, điều này đảm bảo vẫn giữ nguyên trật tự các số khác 0, mà không phải đổi chỗ nhiều lần.
- Để làm được điều này, cần 2 chỉ số vị trí, 1 để chỉ vị trí số 0 đầu tiên, 1 để duyệt, 2 chỉ số duyệt cùng chiều. Giả sử i là chỉ số phần tử hiện tại, z là chỉ số vị trí 0 đầu tiên:
    + Nếu A[i] != 0 -> đổi chỗ A[i] và A[z] -> tăng z cùng với i
    + Nếu A[i] = 0 -> giữ nguyên, không tăng z vì khi này z đag chỉ vào vị trí 0 đầu tiên -> tăng i

2. Test cases
TC1:
Input:
A = {6, 0, 8, 2, 3, 0, 4, 0, 1}
Output:
A = {6, 8, 2, 3, 4, 1, 0, 0, 0}

TC2:
Input:
A = {1, 2, 3, 0, 0, 0}
Output:
A = {1, 2, 3, 0, 0, 0}

TC3:
Input:
A = {0, 0, 0, 1, 2, 3}
Output:
A = {1, 2, 3, 0, 0, 0}

TC4:
Input:
A = {1, 5, 8, 9, 2}
Output:
A = {1, 5, 8, 9, 2}

TC5:
Input:
A = {0, 0, 0, 0}
Output:
A = {0, 0, 0, 0}

## Ex 114. Inversion count of an array
Given an array, find the total number of inversions of it. If (i < j) and (A[i] > A[j]), then pair (i, j) is called an inversion of an array A. We need to count all such pairs in the array.

For example,
Input:  A[] = [1, 9, 6, 4, 5] 
Output: 5
( There are 5 inversions in the array: (9, 6), (9, 4), (9, 5), (6, 4), (6, 5) )

1. Ý tưởng
- Có thể thấy, dễ dàng giải quyết bài toán bằng cách dùng 2 vòng lặp for, duyệt từng phần tử, với độ phức tạp O(n^2)
- Tuy nhiên, ta có thể tận dụng Merge Sort để giải quyết bài toán với O(nlogn) với ý tưởng như sau:
    + Giả sử tách mảng ban đầu A[m+n] thành 2 mảng L[m] và R[n]
    + Dùng đệ quy, ta được 2 mảng đã được sắp xếp là L[m] với biến chạy là i và R[n] với biến chạy là j.
    + Khi trộn 2 mảng này, nếu L[i] > R[j] thì hiển nhiên mỗi phần tử từ L[i+1] đến L[m] cũng đều lớn hơn R[j]. Từ đây, ta có thể tính toán nhanh số cặp đảo ngược đối với R[j] mà không cần so sánh từng phần tử của L[i] với với R[j].
        Cụ thể: Số cặp đảo ngược dối với R[j] = m - i + 1
    + Làm điều này với từng phần tử của R[n], ta sẽ có kết quả cần tìm.
    + Lưu ý rằng, việc sắp xếp các phần tử của 2 mảng trước khi so sánh sẽ không làm ảnh hưởng đến kết quả, vì Merge Sort chọn điểm chia là điểm giữa, đảm bảo tất cả các phần tử mảng bên trái đều nằm trước các phần tử mảng bên phải ở mảng ban đầu.

2. Test cases
TC1: Mảng sắp xếp tăng dần
Input: A = {1, 2, 3, 4, 5}
Output: 0

TC2: Mảng sắp xếp giảm dần 
Input: A = {5, 4, 3, 2, 1}
Output: 10
(Các cặp số nghịch là (5,4), (5,3), (5,2), (5,1), (4,3), (4,2), (4,1), (3,2), (3,1), (2,1))

TC3: 
Input: A = {1, 9, 6, 4, 5}
Output: 5

TC4: Mảng chứa các phần tử trùng lặp
Input: A = {2, 2, 1, 1}
Output: 4

TC5:
Input: A = {7, 7, 7, 7}
Output: 0

TC6:
Input: A = {10}
Output: 0

## Ex 115. Segregate positive and negative integers in linear time
Given an array of positive and negative integers, segregate them in linear time and constant space. The output should print all negative numbers, followed by all positive numbers.

For example,
Input:  [9, -3, 5, -2, -8, -6, 1, 3]
Output: [-3, -2, -8, -6, 5, 9, 1, 3]

1. Ý tưởng
- Nhìn vào bài toán, ta thấy có thể dùng thuật toán giống với Quick Sort, với 0 là pivot.
- Khi đó, ta có thể xếp phần số âm (<0) ở phía trước pivot, và số dương sau pivot, chỉ khác là pivot ở đây không nằm trong mảng.

2. Test cases
TC1: 
Input: A = {9, -3, 5, -2, -8, -6, 1, 3}
Output: {-3, -2, -8, -6, 9, 5, 1, 3}

TC2: Mảng toàn số dương
Input: A = {5, 2, 9, 1, 7}
Output: {5, 2, 9, 1, 7}

TC3: Mảng toàn số âm
Input: A = {-4, -7, -1, -3, -10}
Output: {-4, -7, -1, -3, -10}

TC4: Best case
Input: A = {-5, -2, -9, 1, 6, 8}
Output: {-5, -2, -9, 1, 6, 8}

TC5:
Input: A = {1, -2, 3, -4, 5, -6}
Output: {-2, -4, -6, 1, 3, 5}

TC6: Mảng có chứa số 0
Input: A = {0, -1, 2, -3, 0, -5}
Output: {-1, -3, -5, 0, 2, 0}

TC7:
Input: A = {-10}
Output: {-10}

TC8: 
Input: A = {10}
Output: {10}