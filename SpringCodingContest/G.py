S = input()
N = int(input())
keywords = []
for i in range(N):
	keywords.append(input())

keywords.sort(key=lambda x: -len(x))

idx = 0
matches = 0
while idx < len(S):
	for k in keywords:
		if len(k) + idx <= len(S):
			if S[idx:idx+len(k)] == k:
				idx += len(k) - 1
				matches += len(k)
				break
	idx = idx + 1
print(matches)
