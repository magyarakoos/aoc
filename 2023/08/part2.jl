f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
starts = []
for l in eachline(f)
    g[l[1:3]] = (l[8:10], l[13:15])
    if (l[3] == 'A')
        push!(starts, l[1:3])
    end
end
p2 = 1
for s in starts
    i = 0
    while (s[3] != 'Z')
        s = g[s][inst[(i % length(inst)) + 1] == 'L' ? 1 : 2]
        i += 1
    end
    global p2 = lcm(p2, i)
end
println(p2)