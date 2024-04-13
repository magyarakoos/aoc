function wander(curr, i, inst, g)
    if (curr == "ZZZ")
        return 0
    end
    if (inst[i % (length(inst) + 1)] == 'L')
        return wander(g[curr][0], i + 1, inst, g)
    else
        return wander(g[curr][1], i + 1, inst, g)
    end
end

f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict{String, String}()
for l in eachline(f)
    m = match(r"(\w+) = \((\w+), (\w+)\)", l)
end

println(wander("AAA", 1, inst, g))