#include <iostream>
#include <algorithm>

int main(int argc, char* argv[])
{
    int A, B, C, D, E;
    std::cin >> A >> B >> C >> D >> E;
    std::cout << std::max(A+D+E, B+C+E) << "\n";
    return 0;
}
