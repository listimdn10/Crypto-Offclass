#include <iostream>
#include <random>
#include <string>

// Hàm để tạo ngẫu nhiên khóa AES và trả về dưới dạng chuỗi string
std::string generateRandomKeyAsString(int keySize) {
    std::random_device rd; // Thiết bị sinh số ngẫu nhiên
    std::mt19937 gen(rd()); // Máy sinh số ngẫu nhiên với seed từ rd
    std::uniform_int_distribution<int> dis(0, 255); // Phân phối đồng nhất từ 0 đến 255

    std::string result;
    for (int i = 0; i < keySize; ++i) {
        result += static_cast<char>(dis(gen)); // Chuyển đổi byte ngẫu nhiên thành ký tự ASCII và thêm vào chuỗi kết quả
    }
    return result; // Trả về chuỗi string
}

int main() {
    // Tạo khóa AES với độ dài 16 byte
    std::string key16 = generateRandomKeyAsString(16);
    std::cout << "Random AES 128-bit Key: " << key16 << std::endl;

    // Tạo khóa AES với độ dài 24 byte
    std::string key24 = generateRandomKeyAsString(24);
    std::cout << "Random AES 192-bit Key: " << key24 << std::endl;

    // Tạo khóa AES với độ dài 32 byte
    std::string key32 = generateRandomKeyAsString(32);
    std::cout << "Random AES 256-bit Key: " << key32 << std::endl;

    return 0;
}
