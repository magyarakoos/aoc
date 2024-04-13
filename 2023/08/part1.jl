f = open("input", "r")
(inst = readline(f); readline(f))
g = Dict()
for l in eachline(f)
    a, b, c = [match(r"\w+", l)[i] for i in 1:3]
    g[a] = (b, c)
end
wander = (curr, i) -> begin
    return curr == "ZZZ" ? 0 :
    1 + 
    if (curr == "ZZZ")
        return 0
    elseif (inst[i % length(inst)] == 'L')
        return 1 + wander(g[curr][0], i + 1)
    else
        return 1 + wander(g[curr][1], i + 1)
    end
end