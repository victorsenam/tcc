[k,n] = map(int, input().split(' '))
w = [0. for x in range(n)]
a = [0. for x in range(n+1)]

for i in range(n):
	w[i] = float(input())
	a[i+1] = a[i] + w[i]

A = [[0. for x in range(n)] for y in range(n)]

print(n)
for i in range(n):
	out = ""
	for j in range(n):
		qt = a[j+1] - a[i]
		qt = qt * qt
		A[i][j] = qt
		out = out + str(qt) + " "
	print(out)

for i in range(n-1):
	for j in range(n-1):
		assert(A[i][j] + A[i+1][j+1] <= A[i+1][j] + A[i][j+1])
