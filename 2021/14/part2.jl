using StatsBase
f = open("input", "r")
s = readline(f); readline(f)
d = Dict{String, Char}(); cache = Dict{String, Int}()
map(l -> (d[l[1:2]] = l[7]; cache[l[1:2]] = 1), eachline(f))
println(cache)