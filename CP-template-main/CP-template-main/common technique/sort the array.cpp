Problem 1 :  /* sort the array */

Given an array of length n, the goal is to make it non-decreasing
by repeatedly choosing two adjacent elements and either increasing 
or decreasing both by 1. Elements can become negative.
solution : 
    for(i=0; i<n-2; i++) {
       if( v[i] > v[i+1] )
          x = v[i] - v[i+1], v[i+1] = v[i], v[i+2] = v[i+2] + x;
     }
    for(i=n-1; i>1; i--) {
       if( v[i] < v[i-1] )
          x = v[i-1] - v[i], v[i-1] = v[i], v[i-2] = v[i-2] - x;
    }
    // Check if the array is sorted

  /* END */
