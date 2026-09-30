
# BT Tuần 4. Cài đặt bài toán tháp Hà Nội theo 2 cách viết thủ tục đệ quy và khử đệ quy


## Mô tả bài toán

Có 3 cột A, B, C và 1 chồng gồm n chiếc đĩa kích thước khác nhau, đặt ở cột A với thứ tự kích thước giảm dần từ dưới lên trên. Các đĩa được đánh số từ 1 đến n theo thứ tự từ trên xuống.

Cần chuyển toàn bộ số đĩa từ cột A sang cột B, có thể sử dụng cột C làm trung gian với quy tắc như sau:
- Mỗi lần chỉ được di chuyển 1 đĩa, là đĩa trên cùng của 1 cột nào dó.
- Không được đặt đĩa lớn lên đĩa nhỏ ở bất kỳ thời điểm nào.

In ra số bước cần thực hiện và thứ tự các bước.
## 1. Thủ tục đệ quy

### Các bước thực hiện giải thuật

1. Di chuyển (n-1) đĩa từ cột A sang cột C trung gian.
2. Di chuyển 1 đĩa (lớn nhất) sang cột B.
3. Di chuyển (n-1) đĩa từ cột C sang cột B.

### Test cases

| Test case |      Input     |                                                                                                                                                                                                     Expected Output                                                                                                                                                                                                     |
|:---------:|:--------------:|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
|     1     | n < 0, A, B, C |                                                                                                                                                                                                "Invalid number of disks"                                                                                                                                                                                                |
|     2     | n = 0, A, B, C |                                                                                                                                                                                                            0                                                                                                                                                                                                            |
|     3     | n = 1, A, B, C |                                                                                                                                                                                               1<br>Move disk 1 from A to C                                                                                                                                                                                              |
|     4     | n = 2, A, B, C |                                                                                                                                                                    2<br>Move disk 1 from A to B<br>Move disk 2 from A to C<br>Move disk 1 from B to C                                                                                                                                                                   |
|     5     | n = 3, A, B, C |                                                                                                              7<br>Move disk 1 from A to B<br>Move disk 2 from A to C<br>Move disk 1 from B to C<br>Move disk 3 from A to B<br>Move disk 1 from C to A<br>Move disk 2 from C to B<br>Move disk 1 from A to B                                                                                                             |
|     6     | n = 4, A, B, C | 15<br>Move disk 1 from A to C<br>Move disk 2 from A to B<br>Move disk 1 from C to B<br>Move disk 3 from A to C<br>Move disk 1 from B to A<br>Move disk 2 from B to C<br>Move disk 1 from A to C<br>Move disk 4 from A to B<br>Move disk 1 from C to B<br>Move disk 2 from C to A<br>Move disk 1 from B to A<br>Move disk 3 from C to B<br>Move disk 1 from A to C<br>Move disk 2 from A to B<br>Move disk 1 from C to B |

## 2. Khử đệ quy
