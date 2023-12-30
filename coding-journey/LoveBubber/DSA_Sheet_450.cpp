#include <bits/stdc++.h>
using namespace std;

// find unique element in duplicates array --> xor logic
/*
int findUnique(int *arr, int n) {
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = res ^ arr[i];
  }
  return res;
}

int main() {
  int arr[] = {1, 2, 3, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(int);
  cout << n << endl;
  cout << findUnique(arr, n) << endl;
  return 0;
}
*/

// find Duplicate element in unique array --> xor logic
/*
int findDuplicate(int *arr, int n){
  // 1 to N
  int res = 0;
  for(int i=1;i<n;i++){
    res = res^i;
  }

  for(int i=0;i<n;i++){
    res = res^arr[i];
  }

  return res;
}

int main() {
  int arr[] = {1, 2, 3, 3, 4, 5, 6, 7};
  int n = sizeof(arr) / sizeof(int);
  cout << n << endl;
  // cout << findUnique(arr, n) << endl;
  cout << findDuplicate(arr, n) << endl;
  return 0;
}

*/

// Array in intersection
/*
1) first if array is not sorted then sort first -> O(nlogn)
2) use 2 pointer approach for this : tips: don't thing about the array length

E.g: {1,2,3,3,4}, {2,3,4} : ans 2,3,4
E.g: {3,3,4,5,6,7}, {2,3,4,7,8,9} : ans 2, 3, 4, 7

int main() {
  int n=6, m=6, i=0, j=0;
  int arr1[] = {3,3,4,5,6,7};
  int arr2[] = {2,3,4,7,8,9};

  // sort the array
  sort(arr1, arr1 * n);
  sort(arr2, arr2 * m);

  while(i<n && j<m){
    if(arr1[i] < arr2[j]){
      i++;
    }
    else if(arr1[i] > arr2[j]){
      j++;
    } else if(arr[i] == arr[j]){
      cout << arr[i] << " ";
      i++;
      j++;
    }
  }

  return 0;

}
*/

// move zeros on the start --> O(n)
/*
e,g: {0,0,1,2,0,0,5,4} : ans : {0,0,0,0,1,2,5,4};

int main(){

  int arr[] = {0,0,1,2,0,0,5,4};
  int n = 8, j=0;

  for(int i=0;i<n;i++){
    if(arr[i]==0){
      arr[j++] = arr[i];
    }
  }

  return 0;
}
*/

// - rotated Array with the k index
/*
#include <iostream>
using namespace std;

int main(){
	int arr[] = {1,2,3,4,5,6};
	int n = 6, k=3;
	
	for(int i=0;i<n;i++){
		cout << arr[(i+k)%n] << " ";
	}
	
	return 0;
}
*/

// - Rotated sorted array find the rotated index val, lowest no idx
// go with the BST approach 
/*
#include <iostream>
using namespace std;
int main() {
    int arr[] = {4,5,6,7,1,2,3};
	int n=7, s=0, e=n-1;
	int mid = (s+e)/2;
	
	while(s<e){
		if(arr[mid] > arr[0]){
			s = mid+1;
		}else {
			e = mid;
		}
		mid = (s+e)/2;
	}
	
	cout << s << " " << arr[s] << endl;
	
	return 0;
}
*/


// Dnf : Dutch national flag algo
// 0,1,2 --> three digit sort technique
/*
int main(){
	int arr[]={0,0,0,1,2,1,2,1,2,0,0};
	int n = 11;
	int i=0, j=n-1, mid=0;
	
	while(mid<=j){
		if(arr[mid]==0){
			swap(arr[i++], arr[mid++]);
		} else if(arr[mid]==1){
			mid++;
		} else if(arr[mid]==2){
			swap(arr[mid],arr[j--]);
			;
		}
	}
	
	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
		
	return 0;
}


// second method
#include <bits/stdc++.h>
void sort012(int *arr, int n)
{ //   Write your code here
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    for (int i = j; i < n; i++)
    {
        if (arr[i] == 1)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}
*/


// Largest Sum Contiguous Subarray (Kadane’s Algorithm)  [done]
/*
#include <stream>
#include <climit>
using namespace std;
int main(){
	int arr[] = {1,2, 6,-2,-1,2,1,3,4};
	int n = 8, sum=0, maxi = INT_MIN;
	for(int i=0;i<n;i++){
		sum += arr[i];
		if(sum<0){
			sum=0;
		}
		maxi = max(sum, maxi);
	}
	cout << maxi << endl;
	
	return 0;
}
*/


// Sum of 2 Array 
/*
#include <bits/stdc++.h>
using namespace std;

int main() {

  int a1[] = {8, 7, 2}, a2[] = {8, 9, 4};
  int n = 3, m = 3, i = n - 1, j = m - 1, carry = 0;
  vector < int > res;

  // till the same length
  while (i >= 0 && j >= 0) {
    int total = a1[i--] + a2[j--] + carry;
    carry = total / 10;
    res.push_back(total % 10);
  }

  // if a1 length big
  while (i >= 0) {
    int total = a1[i--] + carry;
    carry = total / 10;
    res.push_back(total % 10);
  }

  // if a2 length big
  while (j >= 0) {
    int total = a1[j--] + carry;
    carry = total / 10;
    res.push_back(total % 10);
  }

  // if carry remaing
  if (carry != 0) {
    res.push_back(carry);
    carry = 0;
  }

  reverse(res.begin(), res.end());

  for (int i: res) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
*/


// Move all negative elements to end

/*
void segregateElements(int arr[],int n)
    {
        vector<int> tmp;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                tmp.push_back(arr[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                tmp.push_back(arr[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            arr[i] = tmp[i];
        }
    }
*/

// Union of two arrays

/*
int doUnion(int a[], int n, int b[], int m)  {
        //code here
        set<int> s;
        for(int i=0;i<n;i++){
           s.insert(a[i]);
        }
        for(int i=0;i<m;i++){
           s.insert(b[i]);
        }
        
        return s.size();
        
    }
*/

// Cyclically rotate an array by one
/*
int main() {
	int arr[] = {1,2,3,4,5};
	int n = 5;
	int tmp = arr[n-1];
	for(int i=n-1; i>0; i--){
		arr[i] = arr[i-1];
	}
	arr[0] = tmp;
}
*/

// Kadane's Algorithm
/*
long long maxSubarraySum(int arr[], int n){
        
	long long sum=0, maxi=INT_MIN;
	
	for(int i=0;i<n;i++){
		sum += arr[i];
		
		if(sum<0){
			sum=0;
		}
		maxi = max(maxi, sum);
	}
	
	if(maxi==0){
		maxi = INT_MIN;
		for(int i=0;i<n; i++){
			sum  = arr[i];
			maxi = max(sum, maxi);
		}
	}
	
	return maxi;
	
}
*/
