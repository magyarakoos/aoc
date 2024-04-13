function wander(curr, i)
    return curr == "ZZZ" ? 0 :
    wander(
        g[curr][inst[i % length(inst)] == 'L' ? 1 : 0], 
        i + 1)
end

f = open("input", "r")
inst = readline(f)
readline(f)
g = Dict()
for l in eachline(f)
    a, b, c = [match(r"(\w+) = \((\w+), (\w+)\)", l)[i] for i in 1:3]
    g[a] = (b, c)
end
wander = (curr, i) -> begin
return curr == "ZZZ" ? 0 :
1 + 
end
println(wander("AAA"))