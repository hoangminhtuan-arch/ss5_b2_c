# Báo cáo phân tích và thiết kế giải pháp - MedCare Clinic

## 1. Phân tích bài toán (I/O)
- **Đầu vào (Input)**:
  - Mảng `tuoi_benh_nhan[4]`: Lưu độ tuổi của 4 bệnh nhân (kiểu số nguyên).
  - Mảng `co_bao_hiem[4]`: Lưu trạng thái BHYT của 4 bệnh nhân (kiểu số nguyên: 1 là có, 0 là không).
- **Tính toán (Processing)**:
  - **Kiểm soát BHYT**: Nếu dữ liệu BHYT nhập vào không phải `0` và `1`, ép về `0` (không có BHYT) để tránh thất thoát.
  - **Kiểm soát Tuổi**: Nếu tuổi `<= 0` hoặc `> 120`, đánh dấu lỗi. Phí khám bằng `0`, luồng "LỖI DỮ LIỆU", không cộng vào ca ưu tiên.
  - **Tính phí**: Nếu tuổi hợp lệ, có BHYT phí khám là `40000` VNĐ, không có BHYT là `200000` VNĐ. Cộng dồn vào doanh thu.
  - **Phân luồng**: Nếu tuổi hợp lệ và `> 70`, phân luồng "ƯU TIÊN" và cộng dồn số đếm ca ưu tiên. Các trường hợp còn lại là "THƯỜNG".
- **Đầu ra (Output)**:
  - Mảng `phi_kham[4]`: Phí khám thực tế tương ứng với từng bệnh nhân.
  - Tổng số doanh thu (VNĐ).
  - Tổng số ca ưu tiên (hợp lệ).
  - Bảng tổng kết chi tiết cho từng bệnh nhân.

## 2. Đề xuất giải pháp
- Sử dụng vòng lặp `for` (từ index 0 đến 3) để lần lượt lấy thông tin, kiểm tra tính hợp lệ và cập nhật phí khám vào mảng thứ 3 (`phi_kham`).
- Sử dụng các lệnh rẽ nhánh `if - else` bên trong vòng lặp để chặn các giá trị bất hợp lệ (Data Validation) tại thời điểm tiếp nhận.
- Áp dụng các biến cộng dồn `tong_doanh_thu` và `tong_uu_tien` để tổng hợp kết quả ca trực.
- Đảm bảo các chỉ số mảng đồng bộ với nhau (`tuoi_benh_nhan[i]`, `co_bao_hiem[i]`, `phi_kham[i]` cùng thuộc về 1 bệnh nhân).

## 3. Thiết kế các bước
- **Bước 1**: Khai báo 3 mảng kích thước 4 là `tuoi_benh_nhan`, `co_bao_hiem`, `phi_kham`. Khai báo biến `tong_doanh_thu = 0` và `tong_uu_tien = 0`.
- **Bước 2**: Lặp 4 lần (chỉ số `i` từ 0 đến 3) để nhập dữ liệu đầu vào.
- **Bước 3**: Bên trong vòng lặp, áp dụng xử lý lỗi (BHYT khác 0 và 1 thì cho bằng 0; Tuổi bất thường thì gán phí khám = 0).
- **Bước 4**: Tiếp tục nhánh xử lý đúng (tuổi hợp lệ) để tính phí khám dựa trên trạng thái BHYT hiện tại và tăng đếm nếu là người cao tuổi. Cộng phí khám vào tổng doanh thu.
- **Bước 5**: Lặp lần 2 (hiển thị) để in ra danh sách chi tiết của 4 bệnh nhân, đi kèm logic xét phân luồng ("LỖI DỮ LIỆU", "ƯU TIÊN", "THƯỜNG").
- **Bước 6**: In ra tổng doanh thu và tổng số ca ưu tiên đã tính.
