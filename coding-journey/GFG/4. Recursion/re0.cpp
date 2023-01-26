/*
    All recursion related pattern
*/

// Algorithm
/*
    f(i=0, vector ds, arr, n){
        if(idx >= n){
            print(ds)
            return
        }

        // take conditions
        ds.push(arr[i])
        f(i+1, ds, arr, n)
        ds.pop(arr[i])

        // not take condition
        f(i+1, ds, arr, n);
    }
*/
