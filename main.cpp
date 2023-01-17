#include <iostream>
#include "vector"
#include "algorithm"
#include "map"

using namespace std;

auto add = [](int a, int b){ return a + b; };

int main() {
    vector<int> v {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

    vector<int> v_squared{};

    for_each(v.cbegin(), v.cend(), [](int a){return a * a; });

    for (auto it = v.begin(); it != v.end(); ++it) {

    };

    for (const auto& element : v){

    };


    return 0;
}
