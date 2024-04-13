
f = map(a -> [parse.(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict(); dists = Dict()
i = 1
for (rate, values) in f
    rates[i] = rate
    g[i] = Vector{String}()
    for value in values
        push!(g[i], value)
    end
    global i += 1
end

for i in 