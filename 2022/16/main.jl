s = readline()
t = lowercase(readline())
if (t[3] == 'x')
    t = t[1:2]
end
i = 1; j = 1
while i <= length(s) && j <= length(t)
    if s[i] == t[j]
        global j += 1
    end
    global i += 1
end
println(i > length(s) ? "Yes" : "No")