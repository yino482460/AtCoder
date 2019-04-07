#include <iostream>

int main(int argc, char* argv[])
{
    double N, K;
    std::cin >> N >> K;
    double ans;
    ans = ((N-K)*(K-1)*6 + (N-1)*3 + 1)/(N*N*N);
    std::cout.precision(15);
    std::cout << ans << "\n";
    return 0;
}
