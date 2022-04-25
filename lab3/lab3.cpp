
#include "lib.h";

int main()
{
    int amount = amountOfArrays();
    int up, down, min;
    range(down, up);
    vector <NumArray> vect = create(amount, down, up);

    cout << "_______________________________________" << endl;

    print_max(amount, vect);
    vector <int> max_v = find_min(amount, vect, min);

    cout << "_______________________________________" << endl;

    output_result(max_v, vect, min);

    return 0;
}
