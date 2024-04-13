f = map(a -> [a[1], parse(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
nodes = []
for (key, rate, values) in f
    push!(nodes, key)
    rates[key] = rate
    g[key] = Vector{String}()
    dists[key] = Dict{String, Int}()
    dists[key][key] = 0
    for value in values
        dists[key][value] = 1
        g[]
    end
end