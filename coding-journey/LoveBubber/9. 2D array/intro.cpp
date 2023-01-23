#include <bits/stdc++.h>
using namespace std;

bool checkElement(int arr[][3], int k, int row, int col)
{ // O(n^2)
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (arr[row][col] == k)
                return 1;
        }
    }
    return 0;
}

void rowWiseSum(int arr[][3])
{
    // O(n)
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

void colWiseSum(int arr[][3])
{
    // O(n)
    for (int col = 0; col < 3; col++)
    {
        int sum = 0;
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}

int largestRowSum(int arr[][3])
{
    int maxi = INT_MIN, rowIdx = -1;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
            if (maxi < sum)
            {
                maxi = sum;
                rowIdx = row;
            }
        }
        cout << sum << " ";
    }
    cout << endl;
    return rowIdx;
}

void wavePrint(int arr[][3])
{

    for (int col = 0; col < 3; col++)
    {
        if (col & 1)
        { // odd
            for (int row = 2; row > -1; row--)
            {
                cout << arr[col][row] << " ";
            }
        }
        else
        {
            for (int row = 0; row < 3; row++)
            {
                cout << arr[col][row] << " ";
            }
        }
    }
}

void spiralPrint(int arr[][3], int n, int m)
{
    int row = n;
    int col = m;

    int count = 0;
    int totalEle = row * col;

    // indexes
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;

    while (count < totalEle)
    {

        for (int idx = startingCol; idx <= endingCol; idx++)
        {
            cout << arr[startingRow][idx] << " ";
            count++;
        }
        startingRow++;

        for (int idx = startingRow; idx <= endingRow; idx++)
        {
            cout << arr[idx][endingCol] << " ";
            count++;
        }
        endingCol--;

        for (int idx = endingCol; idx >= startingCol; idx--)
        {
            cout << arr[endingRow][idx] << " ";
            count++;
        }
        endingRow--;

        for (int idx = endingRow; idx >= startingRow && count < totalEle; idx--)
        {
            cout << arr[idx][startingCol] << " ";
            count++;
        }
        startingCol++;
    }
    cout << endl;
}

void rotate90DegLeft(int arr[][3])
{
    cout << endl;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void rotate90DegRight(int arr[][3])
{
    cout << "working" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 2; j >= 0; j--)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

//  binary search in 2d array
int sortedArraySearch(vector<vector<int>> &arr, int k)
{
    int row = arr.size();
    int col = arr[0].size();

    int start = 0;
    int end = row * col - 1;
    int mid = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        int element = arr[mid / col][mid % col];
        if (element == k)
        {
            cout << mid << " " << element << " persent " << mid / row << " " << mid % col << endl;
            return mid;
        }
        else if (element < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return mid;
}

int bs2DArraySearch(vector<vector<int>> &arr, int target)
{
    int n = arr.size();
    int i = 0;
    int j = arr[0].size() - 1;
    while (i < n && j > -1)
    {
        cout << i << " " << j << endl;
        if (arr[i][j] == target)
        {
            cout << arr[i][j] << " " << i << " " << j << endl;
            return 1;
        }
        else if (arr[i][j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int main()
{
    // vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // vector<vector<int>> arr[3][3];
    // int n;
    // input row wise
    /*for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }
    // display row wise show
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // row wise show
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[col][row] << " ";
        }
        cout << endl;
    }
*/
    // cout << checkElement(arr, 10, 3, 3) << endl;
    // rowWiseSum(arr);
    // colWiseSum(arr);
    // cout << largestRowSum(arr) << endl;
    // wavePrint(arr);
    // display row wise show
    // for (int row = 0; row < 3; row++)
    // {
    //     for (int col = 0; col < 3; col++)
    //     {
    //         cout << arr[row][col] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // spiralPrint(arr, 3, 3);
    // rotate90DegLeft(arr);
    // rotate90DegRight(arr);

    // vector<vector<int>> arr = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}; // 2d array but in line wise sorted. [1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60]
    // sortedArraySearch(arr, 23);

    // vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}};
    vector<vector<int>> arr = {{3, 5, 7, 12, 20}, {6, 13, 15, 18, 29}, {9, 17, 25, 36, 40}, {9, 17, 25, 36, 55, 60}, {16, 30, 37, 59, 80}};
    int target = 16;

    cout << bs2DArraySearch(arr, target);
    return 0;
}
