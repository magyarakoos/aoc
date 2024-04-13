f = open("input", "r")
(inst = readline(f); readline(f))
g = Dict()
for l in eachline(f)
    println(l)
    a, b, c = [match(r"\w+", l)[i] for i in 1:3]
    g[a] = (b, c)
end
exit(0)
wander = (curr, i) -> begin
    return curr == "ZZZ" ? 0 :
    1 + wander(g[curr][inst[i % length(inst)] == 'L' ? 1 : 0], i + 1)
end
println(wander("AAA"))