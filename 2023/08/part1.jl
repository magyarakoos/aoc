function wander(curr, i, inst, g)
    if (curr == "ZZZ")
        return 0
    end
    if (inst[i % (len(inst ))])
end

f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
for l in eachline(f)
    a, b, c = [match(r"(\w+) = \((\w+), (\w+)\)", l)[i] for i in 1:3]
    g[a] = [b, c]
end

println(wander("AAA", 1, inst, g))