f = map(a -> [a[1], parse.(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rates = Dict()
for (key, rate, values) in f
    rates[key] = rate
    for value in values
        push!(g[key], value)
    end
end