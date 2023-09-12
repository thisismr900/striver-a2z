#include <bits/stdc++.h> 
#define mod 100005
        
    /* Recursive Method to find the number of dinstict ways to reach the 'nth' stair.  */
    // Time Complexity: O(2^n), where n is the number of stairs.
    // Space Complexity: O(n), recursive stack space.
    int solveRecursive(int n)
    {
        // Base Case
        if (n == 0)
        {
            // if n == 1, it means you reached the 0th stair and in this case return 1.
            // where 1, means you found one path to reach the 0th stair starting from the nth stair.
            return 1;
        }

        // When you are standing at the '1st' stair, then I can say that there is only one path that exists to reach the 0th stair and the way is, by taking one step, because if you take 2 steps from the 1th stair, you may end up reaching the -1th stair, which is basically an invalid stair. So simply return 1.
        if (n == 1)
        {
            return 1;
        }

        // Recursive Case.
        // From each stair you can either take one step or two step. It means for each stair we have 2 choices.
        return (solveRecursive(n - 1) + solveRecursive(n - 2)) % mod;
    }

    /* Optimizing the above Recursive Code using Top-Down Dynamic Programming (AKA Memoization). */

    /* In the top-down approach, we start with the original problem and break it down
    into smaller subproblems. We then recursively solve each subproblem, storing
    the result in a cache or table as we go. When we encounter a subproblem that
    we've already solved, we simply look up the answer in the cache instead of
    recomputing it. This approach is also known as memoization. */

    // Time Complexity: O(n), where n is the number of stairs.
    // Space Complexity: O(n) + O(n) ≈ O(n), recursive stack space and size used by 'dp' array/vector.
    int solveMemoized(int n, vector<int> &dp)
    {
        // Base Case
        if (n == 0)
        {
            // if n == 1, it means you reached the 0th stair and in this case return 1.
            // where 1, means you found one path to reach the 0th stair starting from the nth stair.
            return 1;
        }

        // When you are standing at the '1st' stair, then I can say that there is only one path that exists to reach the 0th stair and the way is, by taking one step, because if you take 2 steps from the 1th stair, you may end up reaching the -1th stair, which is basically an invalid stair. So simply return 1.
        if (n == 1)
        {
            return 1;
        }

        /* Now, Before Calling recursion, first check whether this subproblem is an overlapping subproblem or not because if this subproblem is an overlapping subproblem (repetative subproblem), in this case, the answer of this subproblem is stored in our 'dp' array. */
        if (dp[n] != -1)
        {
            // If dp[n] == -1, it means this is not an overlapping subproblem.
            // but If dp[n] != -1, it means this is an overlapping subproblem and the dp[n] contains the answer of this subproblem.
            return dp[n];
        }

        // Recursive Case.
        // From each stair you can either take one step or two step. It means for each stair we have 2 choices.
        dp[n] = (solveMemoized(n - 1, dp) + solveMemoized(n - 2, dp)) % mod;
        return dp[n];
    }

    /* Optimizing the above DP Memoized Code using Bottom-Up Dynamic Programming (AKA Tabulation). */

    /* In the bottom-up approach, we start with the smallest subproblems and work
    our way up to the original problem. We store the results of each subproblem in
    a table or cache and use those results to solve larger subproblems. By the time
    we get to the original problem, we've already solved all the subproblems we
    need and can simply look up the answer in the table. This approach is also
    known as tabulation. */

    // Time Complexity: O(n), where n is the number of stairs.
    // Space Complexity: O(n), size used by 'dp' array/vector.
    int solveTabulized(int n)
    {
        // 'dp' array to calculate and store the result of particular subproblem.
        vector<int> dp(n + 1);

        // Base Case
        // We are standing at 0th stair so there will be one way to reach 0 that is from 0 itself.
        dp[0] = 1;

        // When you are standing at the '1st' stair, then I can say that there is only one path that exists to reach the 0th stair and the way is, by taking one step, because if you take 2 steps from the 1th stair, you may end up reaching the -1th stair, which is basically an invalid stair.
        dp[1] = 1;

        // Now run a loop from 2 to n and find the number of distinct ways to reach the nth stair.
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }

        // return the number of distinct ways to reach the nth stair.
        return dp[n];
    }

    /* Space Optimizing the above DP Tabulation code. */
    // Using Variable instead of 'dp' array/vector.

    // Time Complexity: O(n), where 'n' is the nth Fibonacci number.
    // Space Complexity: O(1).
    int solveSpaceOptimized(int n)
    {

        // Base Case
        // We are standing at 0th stair so there will be one way to reach 0 that is from 0 itself.
        int zeroThStair = 1;

        // When you are standing at the '1st' stair, then I can say that there is only one path that exists to reach the 0th stair and the way is, by taking one step, because if you take 2 steps from the 1th stair, you may end up reaching the -1th stair, which is basically an invalid stair.
        int oneThStair = 1;

        // Variable to store the number of distinct ways to reach the nth stair.
        int nThStair = -1;

        // Now run a loop from 2 to n and find the number of distinct ways to reach the nth stair.
        for (int i = 2; i <= n; i++)
        {   int mode = 1e9 + 7;
            nThStair = (zeroThStair + oneThStair) % mode;

            // update pointers.
            zeroThStair = oneThStair;
            oneThStair = nThStair;
        }
        
        // return the number of distinct ways to reach the nth stair.
        return oneThStair;
    }
int countDistinctWays(int n) {
    //  Write your code here.
    return solveSpaceOptimized(n);
    
    
} 