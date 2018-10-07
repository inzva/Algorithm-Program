# Enter your code here. Read input from STDIN. Print output to STDOUT

N = int(raw_input())
ar = map(int, raw_input().split())
sr = sorted(ar)

if ar == sr: print 'yes'

else:
	diff_i = []
	diff_n = []

	for i in xrange(N):
		if ar[i] != sr[i]:
			diff_i.append(i)
			diff_n.append(ar[i])

	if len(diff_i) == 2:
		print 'yes\nswap', diff_i[0] + 1, diff_i[1] + 1

	else:
		ordered_i = True
		for i in xrange(len(diff_i)-1):
			if diff_i[i] + 1 != diff_i[i+1]:
				ordered = False; break

		if not ordered_i: print 'no'; quit()

		diff_s = sorted(diff_n, reverse=True)
		if diff_s == diff_n and ar[diff_i[-1]] >= ar[diff_i[0]-1]:
			print 'yes\nreverse', diff_i[0]+1, diff_i[-1] + 1
		else: print 'no'