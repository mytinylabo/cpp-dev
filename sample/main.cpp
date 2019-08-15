#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    #ifdef INPUT_HELPER
    input_helper::redirect_from("sample.in");
    #endif

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
    }

    cout << "Sum: " << sum << endl;
}
