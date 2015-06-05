import math,string,itertools,fractions,heapq,collections,re,array,bisect,random

class PermutationCountsDiv2:
    def countPermutations(self, N, pos):
        lessThanNext = [False] * N
        for x in pos:
            lessThanNext[x - 1] = True;
        
        dp = [ [0] * (N + 1) for i in range(N + 1) ]
        for i in range(0, N):
            dp[i][i] = 1
            dp[i][i+1] = 1
        dp[N][N] = 1

        MOD = 1000000007
        C = [ [0] * (N + 1) for i in range(N + 1) ]
        for i in range(N + 1):
            C[i][0] = 1
            for j in range(1, i + 1):
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1]
                C[i][j] %= MOD

        for t in range(2, N + 1):
            for a in range(N - t + 1):
                b = a + t
                dp[a][b] = 0
                for i in range(a, b):
                    if ( lessThanNext[i] or i == b - 1 ) and ( (i == a) or ( not lessThanNext[i - 1] ) ):
                        p = dp[a][i]
                        q = dp[i + 1][b]
                        r = C[t - 1][i - a]
                        dp[a][b] += p * q * r
                        dp[a][b] %= MOD

        return dp[0][N]

# BEGIN KAWIGIEDIT TESTING
# Generated by KawigiEdit-pf 2.3.0
import sys
import time
def KawigiEdit_RunTest(testNum, p0, p1, hasAnswer, p2):
	obj = PermutationCountsDiv2()
	startTime = time.clock()
	answer = obj.countPermutations(p0, p1)
	endTime = time.clock()
	res = True
	if (hasAnswer):
		res = answer == p2
	
	sys.stdout.write(str("Test ") + str(testNum) + str(" "))
	if (not res):
		print(str("failed."))
		sys.stdout.write(str("expected: "))
		print(str("\t") + str(p2))
		sys.stdout.write(str("received: "))
		print(str("\t") + str(answer))
		print(str(""))
	elif ((endTime - startTime) >= 2):
		print(str("FAIL the timeout"))
		res = False
	elif (hasAnswer):
		sys.stdout.write(str("passed.      "))
		sys.stdout.write(str("Time: ") + str((endTime - startTime)) + str(" seconds"))
		print(str(""))
	else:
		print(str("OK, but is it right?"))
	
	return res

all_right = True
tests_disabled = False

# ----- test 0 -----
disabled = False
p0 = 3
p1 = ()
p2 = 1
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 0 -----
disabled = False
p0 = 5
p1 = (3,)
p2 = 9
all_right = (disabled or KawigiEdit_RunTest(0, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 1 -----
disabled = False 
p0 = 13
p1 = (12,11,10,9,8,7,6,5,4,3,2,1)
p2 = 1
all_right = (disabled or KawigiEdit_RunTest(1, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 2 -----
disabled = False 
p0 = 13
p1 = ()
p2 = 1
all_right = (disabled or KawigiEdit_RunTest(2, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 3 -----
disabled =False
p0 = 9
p1 = (2,4,5)
p2 = 1421
all_right = (disabled or KawigiEdit_RunTest(3, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

# ----- test 4 -----
disabled = False
p0 = 80
p1 = (31,41,59,26,53,58,9,79,32,3,8,46)
p2 = 82650786
all_right = (disabled or KawigiEdit_RunTest(4, p0, p1, True, p2) ) and all_right
tests_disabled = tests_disabled or disabled
# ------------------

if (all_right):
	print(str(""))
	if (tests_disabled):
		print(str("You're a stud (but some test cases were disabled)!"))
	else:
		print(str("You're a stud (at least on given cases)!"))
	
else:
	print(str("Some of the test cases had errors."))

# END KAWIGIEDIT TESTING
#Powered by KawigiEdit-pf 2.3.0!