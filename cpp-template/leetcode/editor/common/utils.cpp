#include <iostream>
#include <vector>

void print_vec_2d(const std::vector<std::vector<int>>& vec) {
    for (const auto& row : vec) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl; // 每行结束后换行
    }
}
void print_vec(const std::vector<int>& vec)
{
    for (const auto& elem : vec) 
        std::cout << elem << " ";
    std::cout << std::endl; 
}
// int main() {
//     std::vector<std::vector<int>> vec = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     print_vec_2d(vec); // 调用函数打印二维向量
//     return 0;
// }