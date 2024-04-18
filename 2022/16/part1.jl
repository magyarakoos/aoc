using Combinatorics
f = map(l -> match(r".{6}(.[A-Z]).{15}(\d+).{24}\s+(.*)", l), readlines("input"))
rates = Dict{String, Int}(); g = Dict{String, Vector{String}}()
nodes = Vector{String}()
for m in f
    rates[m[1]] = parse(Int, m[2])
    g[m[1]] = Vector{String}()
    for v in split(m[3], ", ")
        push!(g[m[1]], v)
    end
    if rates[m[1]] != 0
        push!(nodes, m[1])
    end
end

# floyd-warshall on non-zero width pipes O(n^3)
n = length(nodes)
dist = Dict{String, Dict{String, Int}}()
for u in nodes, v in nodes