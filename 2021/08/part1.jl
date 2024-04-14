f = map(l -> match(r".*\|(.*)", l)[1], readlines("input"))
println(split(join(f, " ")))
