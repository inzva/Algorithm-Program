
def display(full=False):
	if not full:
		for row in grid:
			print row
	else:
		for i in xrange(r):
			print 'O'*c

def change():
	global grid
	temp = set([])
	for i in xrange(r):
		for j in xrange(c):
			if grid[i][j] == ord('O'):
				temp.add((i, j))
				if i-1 >= 0: temp.add((i-1, j))
				if j-1 >= 0: temp.add((i, j-1))
				if i+1 < r : temp.add((i+1, j))
				if j+1 < c : temp.add((i, j+1))

	grid = [bytearray('O'*c) for i in xrange(r)]

	for i, j in temp: grid[i][j] = ord('.')

r, c, n = map(int, raw_input().split())
grid = [bytearray(raw_input()) for i in xrange(r)]

if n == 1:
	display()

elif n & 1 == 0:
	display(True)

elif (n + 1) % 4 == 0:
	change()
	display()

else:
	change()
	change()
	display()

