f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
for l in eachline(f)
    g[l[1:3]] = (l[8:10], l[13:15])
end
i = 0; s = "AAA"
while (s != "ZZZ")
    s = g[s][inst[(i % length(inst)) + 1] == 'L' ? 1 : 2]
    i += 1
end
println(i)