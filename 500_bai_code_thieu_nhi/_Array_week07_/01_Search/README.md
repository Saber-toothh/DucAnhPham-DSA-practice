
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

## Ex124. Find the smallest missing element from a sorted array

Given a sorted array of non-negative distinct integers, find the smallest missing non-negative element in it.
For example,
Input:  nums[] = [0, 1, 2, 6, 9, 11, 15]
Output: 3  

Input:  nums[] = [1, 2, 3, 4, 6, 9, 11, 15]
Output:  0  

Input:  nums[] = [0, 1, 2, 3, 4, 5, 6]
Output: 7

1. Ý tưởng
- Có thể thấy, phần tử không thiếu là phần tử mà giá trị của nó bằng đúng chỉ số của nó, vì là số nguyên không âm đôi một khác nhau và mảng đã được sắp xếp. Vậy chỉ số i mà A[i] != i chính là giá trị cần tìm.
- Ta có thể nghĩ ngay đến việc duyệt lần lượt từng phẩn tử của mảng, và dễ dàng có được chỉ số đang tìm. Tuy nhiên, cách này yêu cầu độ phức tạp O(n), ta có thể tận dụng việc mảng đã đước sắp xếp và dùng Binary Search, giúp giảm độ phức tạp xuống O(logn).
- Ta áp dụng Binary Search như sau, giả sử left, right là 2 đầu mút, k là chỉ số ở giữa:
 + Nếu A[k] = k -> tìm ở nửa sau vì chắc chắn các phần tử trước k đều đã được sắp xếp đúng chỉ số
 + Nếu A[k] != k -> tìm ở nửa đầu, vì khi này chỉ có thể là A[k] > k, nửa đầu sẽ có chỉ số mà giá trị của nó không bằng nó.
 + Trường hợp cơ sở là mảng chỉ có 1 phần tử.

 2. Test cases
 TC1: Phần tử bị thiếu nằm ở giữa mảng
Input: A = {0, 1, 2, 4, 5, 6, 7}
Output: 3

TC2: Phần tử bị thiếu nằm ở ngay vị trí đầu tiên
Input: A = {1, 2, 3, 4, 5}
Output: 0

TC3: Phần tử bị thiếu nằm ở cuối mảng 
Input: A = {0, 1, 2, 3, 4, 5}
Output: 6

TC4: Phần tử bị thiếu ngay sau 0
Input: A = {0, 2, 3, 4}
Output: 1

TC5: Mảng chỉ có 1 phần tử là số 0
Input: A = {0}
Output: 1

TC6: Mảng chỉ có 1 phần tử lớn hơn 0
Input: A = {2}
Output: 0

## Ex128. Find the peak element in an array
Given an integer array, find the peak element in it. A peak element is an element that is greater than its neighbors. There might be multiple peak elements in an array, and the solution should report any peak element.

An element A[i] of an array A is a peak element if it’s not smaller than its neighbor(s).

A[i-1] <= A[i] >= A[i+1] for 0 < i < n-1
A[i-1] <= A[i] if i = n – 1
A[i] >= A[i+1] if i = 0

For example,
Input : [8, 9, 10, 2, 5, 6]
Output: The peak element is 10 (or 6) 

Input : [8, 9, 10, 12, 15]
Output: The peak element is 15  

1. Ý tưởng
- Ở bài toán này, ta nhận thấy việc tìm đỉnh (peak) có những nét tương đồng với việc tìm 1 số trong 1 mảng đã được sắp xếp.
- Cụ thể:
   + Tìm X trong mảng đã sắp xếp A[n], nếu X < A[mid] -> chắc chắn X nằm ở nửa đầu mảng và ngược lại.
   + Tương tự, tìm đỉnh P của A[n], nếu A[mid] < A[mid-1] -> chắc chắn tồn tại P ở nửa đầu mảng, vì ta tưởng tượng từ [mid-1] đến [mid], mảng giống như 1 đồ thị đang đi xuống; và ngược lại.
--> Có thể ứng dụng ý tưởng của thuật toán Binary Search

2. Test cases
TC1: Mảng có 1 phần tử
Input: A = {5}
Output: 5

TC2: Đỉnh nằm ở rìa phải
Input: A = {1, 2, 3, 4, 5}
Output: 5

TC3: Đỉnh nằm ở rìa trái
Input: A = {5, 4, 3, 2, 1}
Output: 5

TC4: Mảng có đỉnh nằm ở giữa
Input: A = {1, 3, 8, 4, 2}
Output: 8

TC5: Mảng có nhiều đỉnh
Input: A = {10, 20, 15, 2, 23, 90, 67}
Output: 20 (hoặc 90)

TC6: Mảng có tất cả các phần tử bằng nhau
Input: A = {3, 3, 3, 3}
Output: 3

TC7: Mảng chứa các số âm
Input: A = {-10, -5, -2, -8}
Output: -2

TC8: Mảng chỉ có 2 phần tử
Input: A = {2, 1}
Output: 2

## Ex52. Find the odd occurring element in an array in a single traversal
Given an integer array, duplicates are present in it in a way that all duplicates appear an even number of times except one which appears an odd number of times. Find that odd appearing element in linear time and without using any extra memory.

For example,
Input:  arr[] = [4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3] Output: The odd occurring element is 4

1. Ý tưởng
- Ở bài toán này, ta thấy có thể tận dụng tính chất của toán tử bitwise XOR để tìm nhanh phần tử lẻ mà không cần mảng phụ để đếm số lần xuất hiện.
- Cụ thể:
   + Tính chất 1: Hai số giống nhau khi XOR với nhau sẽ bằng 0 (x ^ x = 0). Do đó, tất cả các phần tử xuất hiện với số lần chẵn (2 lần, 4 lần...) sẽ tự triệt tiêu lẫn nhau thành 0.
   + Tính chất 2: Một số khi XOR với 0 sẽ bằng chính nó (x ^ 0 = x).
--> Có thể giải quyết với độ phức tạp thời gian O(n) bằng cách khởi tạo một biến result = 0, sau đó duyệt qua mảng 1 lần và XOR result liên tục với từng phần tử A[i]. Kết quả result cuối cùng chính là phần tử xuất hiện với số lần lẻ.

2. Test cases
TC1: Mảng chỉ có 1 phần tử
Input: A = {7}
Output: 7
TC2: Mảng có phần tử lẻ nằm ở giữa
Input: A = {1, 2, 1, 1, 2}
Output: 1
TC3: Mảng có nhiều phần tử, phần tử lẻ xuất hiện 3 lần
Input: A = {4, 3, 6, 2, 6, 4, 2, 3, 4, 3, 3}
Output: 4
TC4: Mảng chứa các số âm
Input: A = {-3, 5, -3, 5, -3}
Output: -3