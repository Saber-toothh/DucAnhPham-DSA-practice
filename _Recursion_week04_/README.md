
# BT Tuần 4. Cài đặt bài toán tháp Hà Nội theo 2 cách viết thủ tục đệ quy và khử đệ quy


## Mô tả bài toán

Có 3 cột A, B, C và 1 chồng gồm n chiếc đĩa kích thước khác nhau, đặt ở cột A với thứ tự kích thước giảm dần từ dưới lên trên. Các đĩa được đánh số từ 1 đến n theo thứ tự từ trên xuống.

Cần chuyển toàn bộ số đĩa từ cột A sang cột B, có thể sử dụng cột C làm trung gian với quy tắc như sau:
- Mỗi lần chỉ được di chuyển 1 đĩa, là đĩa trên cùng của 1 cột nào dó.
- Không được đặt đĩa lớn lên đĩa nhỏ ở bất kỳ thời điểm nào.

In ra số bước cần thực hiện và thứ tự các bước.
## 1. Thủ tục đệ quy

### 1.1 Các bước thực hiện giải thuật

1. Di chuyển (n-1) đĩa từ cột A sang cột C trung gian.
2. Di chuyển 1 đĩa (lớn nhất) sang cột B.
3. Di chuyển (n-1) đĩa từ cột C sang cột B.

### 1.2 Test cases

| Test case |      Input     |                                                                                                                                                                                                     Expected Output                                                                                                                                                                                                     |
|:---------:|:--------------:|:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------:|
|     1     | n < 0, A, B, C |                                                                                                                                                                                                "Invalid number of disks"                                                                                                                                                                                                |
|     2     | n = 0, A, B, C |                                                                                                                                                                                                            0                                                                                                                                                                                                            |
|     3     | n = 1, A, B, C |                                                                                                                                                                                               1<br>Move disk 1 from A to C                                                                                                                                                                                              |
|     4     | n = 2, A, B, C |                                                                                                                                                                    2<br>Move disk 1 from A to B<br>Move disk 2 from A to C<br>Move disk 1 from B to C                                                                                                                                                                   |
|     5     | n = 3, A, B, C |                                                                                                              7<br>Move disk 1 from A to B<br>Move disk 2 from A to C<br>Move disk 1 from B to C<br>Move disk 3 from A to B<br>Move disk 1 from C to A<br>Move disk 2 from C to B<br>Move disk 1 from A to B                                                                                                             |
|     6     | n = 4, A, B, C | 15<br>Move disk 1 from A to C<br>Move disk 2 from A to B<br>Move disk 1 from C to B<br>Move disk 3 from A to C<br>Move disk 1 from B to A<br>Move disk 2 from B to C<br>Move disk 1 from A to C<br>Move disk 4 from A to B<br>Move disk 1 from C to B<br>Move disk 2 from C to A<br>Move disk 1 from B to A<br>Move disk 3 from C to B<br>Move disk 1 from A to C<br>Move disk 2 from A to B<br>Move disk 1 from C to B |

## 2. Khử đệ quy

### 2.1 Ý tưởng
Giống như thủ tục đệ quy, coi toàn bộ quá trình di chuyển chồng đĩa là 1 chuỗi các bước di chuyển chồng đĩa nhỏ hơn và có thứ tự. Để giải quyết bài toán với số lượng đĩa >1, ta cần chia nhỏ thành các bài toán nhỏ hơn, nhỏ đến mức đơn giản nhất (số lượng đĩa bằng 1). 
Khi liên tục chia nhỏ như vậy, các bài toán nhỏ hơn được sinh ra sau các bài toán lớn hơn nhưng lại cần giải quyết trước --> Ta nghĩ đến nguyên lý LIFO và dùng Stack.

Ta coi mỗi phần từ trong Stack là một bước độc lập, gồm 4 thông số:
    - n - số đĩa cần di chuyển
    - start - cột chứa đĩa cần di chuyển
    - destination - cột đích cần di chuyển đến
    - transit - cột trung gian

### 2.2 Các bước thực hiện

1. Đẩy công việc lớn nhất vào Stack (chuyển toàn bộ n đĩa từ A sang B, C là cột trung gian)
2. Vòng lặp đến khi Stack rỗng (tức là đã chuyển được toàn bộ n đĩa)
    - Nếu n = 1: chuyển ngay từ start đến destination
    - Nếu n > 1: Chia thành 3 bước tuần tự
        + Bước 1: Chuyển n-1 đĩa từ start đến transit
        + Bước 2: Chuyển 1 đĩa từ start đến destination
        + Bước 3: CHuyển n-1 đĩa từ transit đến destination
        + Đẩy vào Stack theo thứ tự: Bước 3 -> Bước 2 -> Bước 1s

### 2.3 Test cases
Giống 1.2
