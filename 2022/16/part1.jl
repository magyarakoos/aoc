f = map(l -> match(r".{6}(\w+).{15}(\d+).{23}\w?\s(.*)", l), 
    readlines("input"))

g = map(l -> [l[1], parse.(Int, l[2]), split(l[3], ", ")], f)
println(g)