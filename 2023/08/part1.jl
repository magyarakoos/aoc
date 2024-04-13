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
for s in starts
    
end
(p1 = 0; p2 = 0)
(i = 1; s = "AAA")
while (s != "ZZZ")
    global s = g[s][inst[i % (length(inst) + 1)] == 'L' ? 1 : 2]
    global i += 1
end
println(i - 1)