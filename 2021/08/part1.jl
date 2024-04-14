f = map(l -> match(r".*\|(.*)", l)[1], readlines("input"))
println(count(s -> in(), split(join(f, " "))))
