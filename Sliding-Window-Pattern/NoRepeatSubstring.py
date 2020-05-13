def substring(s):
    a=""
    b=""
    for i in range(len(s)):
        if s[i] not in b:
            b+=s[i]
        else:
            if len(a)<=len(b):
                a = b
            b = b[b.index(s[i])+1:]+s[i]
    print(len(a))
    print(a)
    print(b)
 
substring("abcdabcdefghijklabcdesllsqwertyuioop")