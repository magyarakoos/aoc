f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
for l in eachline(f)
    m = match(r"(\w+) = \((\w+), (\w+)\)", l)
    g[m[1]] = (m[2], m[3])
end
p1 = 0
s = "AAA"
i = 0;