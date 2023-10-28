// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int getTotalGuestBill(int totalGuestWater)
{
    if (totalGuestWater <= 500)
    {
        return totalGuestWater * 2;
    }
    else if (totalGuestWater <= 1500)
    {
        return (500 * 2) + (totalGuestWater - 500) * 3;
    }
    else if (totalGuestWater <= 3000)
    {
        return (500 * 2) + (1000 * 3) + (totalGuestWater - 1500) * 5;
    }
    else
    {
        return (500 * 2) + (1000 * 3) + (1500 * 5) + (totalGuestWater - 3000) * 8;
    }
    return 0;
}

int main()
{
    // Write C++ code here
    int guest, type, r1, r2, totalGuest = 0, totalWater = 0, totalGuestWater = 0;

    cout << "Enter the type of apartment 2 or 3 -> " << endl;

    cin >> type;

    cout << "Enter the first ratio " << endl;
    cin >> r1;

    cout << "Enter the second ratio " << endl;
    cin >> r2;

    cout << "Enter the below option :" << endl;
    cout << "Enter the guest number : " << endl
         << "Press For the bill 0 " << endl;
    cin >> guest;

    while (guest != 0)
    {
        totalGuest += guest;
        cout << endl
             << "Enter the guest number : " << endl
             << "Press For the bill 0 " << endl;
        cin >> guest;
    }

    if (guest == 0)
    {
        // calculation
        if (type == 2)
        {
            totalWater = (3 * 10 * 30);
            totalGuestWater = (totalGuest * 10 * 30);
        }

        if (type == 3)
        {
            totalWater = (5 * 10 * 30);
            totalGuestWater = (totalGuest * 10 * 30);
        }

        // guest bill
        int totalGuestBill = getTotalGuestBill(totalGuestWater);

        float ratioOneAmount = (r1 * totalWater * 1) / (r1 + r2);
        float ratioTwoAmount = (r2 * totalWater * 1.5) / (r1 + r2);

        totalWater += totalGuestWater;
        totalGuestBill += ratioOneAmount + ratioTwoAmount;
        cout << totalWater << " " << totalGuestBill << endl;
    }

    return 0;
}
