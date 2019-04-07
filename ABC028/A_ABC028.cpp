#include <iostream>

int main(int argc, char* argv[])
{
    int N;
    std::cin >> N;
    // 出力
    if (N <= 59) {
        std::cout << "Bad" << "\n";
    } else if (N>=60 && N<=89) {
        std::cout << "Good" << "\n";
    } else if (N>=90 && N<=99){
        std::cout << "Great" << "\n";
    } else {
        std::cout << "Perfect" << "\n";
    }
    return 0;
}
