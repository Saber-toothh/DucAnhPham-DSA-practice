
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