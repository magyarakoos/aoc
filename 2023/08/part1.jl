f = open("input", "r")
(inst = readline(f); readline(f))
g = Dict()
for l in eachline(f)
    a, b, c = [match(r"\w+", l)[i] for i in 1:3]
    g[a] = (b, c)
end