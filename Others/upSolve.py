n = input()
count = 0
for i in range(len(n)):
    val = ''
    for j in range(len(n) - i):
        val = val + n[j : j + i + 1]
        if int(val) % 7 == 0:
            count += 1

print(count)