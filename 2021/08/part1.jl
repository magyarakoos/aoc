f = map(l -> match(r".*\|(.*)", l)[1], readlines("input"))
println(count(s -> in(length(s), [2, 3,]), split(join(f, " "))))
