s = readline()
t = lowercase(readline())
if (t[3] == 'x')
    t = t[1:2]
end
i, j = 1, 1
while i <= length(s) && j <= length(t)
    if s[i] == t[j]
        j += 1
    end
    i += 1
end
println(i > length(s) ? "Yes" : "No")