f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
for l in eachline(f)
    m = match(r"(\w+) = \((\w+), (\w+)\)", l)
    g[m[1]] = (m[2], m[3])
end
(p1 = 0; i = 1; s = "AAA")
while (s != "ZZZ")
    if i > length(inst)
        global i = 1
    end
    global p1 += 1
    global s = g[s][inst[i] == 'L' ? 1 : 2]
    i += 1
end
println(p1)