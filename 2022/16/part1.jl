
f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict{String, Dict{String, Int}}()
nodes = []
for (key, rate, values) in f
    push!(nodes, key)
    dists[key]
    dists[key][key] = 0
end