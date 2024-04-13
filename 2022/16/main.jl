function issub(s, t)
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
    println(issub(s, t[1:2]))
println(issub(s, t) || issub(s, ))