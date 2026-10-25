
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
