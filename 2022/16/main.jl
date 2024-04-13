function issub(t, s)
    i, j = 1, 1
    while i <= length(s) && j <= length(t)
        if s[i] == t[j]
            i += 1
        end
        j += 1
    end
    return i > length(s)
end
s = readline()
t = lowercase(readline())
if (t[3] == 'x')
    t = t[1:2]
end
i, j = 1, 1
while i <= length(s) && j <= length(t)