f = map(a -> [a[1], parse.(Int, a[2]), split(a[3], ", ")], 
    map(l -> 
        match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
        readlines("input")
    )
)
g = Dict(); rate = Dict()
for (k, r, v) in f
    rate[k]
    println(key)
    println(rate)
    println(values)
    println()
end