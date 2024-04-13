function wander(curr, i, inst, g)
    return curr == "ZZZ" ? 0 :
    wander(
        g[curr][inst[i % (length(inst) + 1)]] == 'L' ? 1 : 0], 
        i + 1, inst, g)
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