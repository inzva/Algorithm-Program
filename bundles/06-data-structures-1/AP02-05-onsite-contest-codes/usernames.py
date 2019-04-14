usernames = {}

for _ in range(int(input())):
    
    s = input()
    
    if s not in usernames:
        print("OK")
        usernames[s] = 1
    else:
        print(s + str(usernames[s]))
        usernames[s] += 1