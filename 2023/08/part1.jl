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
    i = 1
    while (s[3] != 'Z')
        s = g[s][inst[(i % length(inst)) + 1] == 'L' ? 1 : 2]
        println((s, i))
        sleep()
        i += 1
    end
    global p2 = lcm(p2, i - 1)
end
println(p2)