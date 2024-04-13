f = map(l -> parse(Int, l), readlines("input"))
p1 = 0
for i in 2:length(f)
    if f[i - 1] < f[i]
end