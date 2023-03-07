
def Straightener(which):
	result = matrix[which][which:len(matrix[0])-which]

	for x in xrange(which+1, len(matrix) - which - 1):
		result.append(matrix[x][-which-1])

	result += matrix[len(matrix)-which-1][which:len(matrix[0])-which][::-1]

	for x in xrange(len(matrix) - which - 1, which+1, -1):
		result.append(matrix[x-1][which])

	return result

if __name__ == '__main__':
	M, N, R = map(int, raw_input().split())

	matrix = []
	for m0 in xrange(M):
		row = map(int, raw_input().split())
		matrix.append(row)

	for w in xrange(min(M,N)/2):
		s = Straightener(w)
		r = R%len(s)
		s = s[r:] + s[:r]

		matrix[    w][w:N-w] = s[:N-2*w]

		temp = len(s) - (len(s)-2*(N-2*w)) / 2 - 1
		matrix[M-w-1][w:N-w] = s[temp: temp - (N-2*w) :-1]

		left = s[len(s):temp:-1]
		for i in xrange(len(left)):
			matrix[w+i+1][w] = left[i]

		right = s[N-2*w:N-2*w + len(left)]
		for i in xrange(len(right)):
			matrix[w+i+1][N-w-1] = right[i]


	for i in matrix:
		print ' '.join(map(str, i))

