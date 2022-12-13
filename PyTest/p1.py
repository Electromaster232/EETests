# 
# Solution to Project Euler problem 1
# Copyright (c) Project Nayuki. All rights reserved.
# 
# https://www.nayuki.io/page/project-euler-solutions
# https://github.com/nayuki/Project-Euler-solutions
# 
import time
import sys

# Computers are fast, so we can implement this solution directly without any clever math.
def compute(num):
	ans = sum(x for x in range(num) if (x % 3 == 0 or x % 5 == 0))
	return str(ans)



if __name__ == "__main__":
        limit = int(sys.argv[1])
        start_time = time.time()
        res = compute(limit)
        duration = ((time.time() - start_time)* 1000)
        print(res + "," + str(duration))
